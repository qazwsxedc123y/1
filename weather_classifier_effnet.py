# -*- coding: utf-8 -*-
"""
天气分类系统 - EfficientNetV2版本
数据集结构：dataset/{sunny,rainy,cloudy,sunrise}/
"""
import os
import numpy as np
import matplotlib.pyplot as plt
import tensorflow as tf
from tensorflow.keras import layers, models, applications
from tensorflow.keras.optimizers import Adam
from tensorflow.keras.losses import CategoricalFocalCrossentropy
from tensorflow.keras.callbacks import EarlyStopping, ModelCheckpoint
from tensorflow.keras.preprocessing.image import ImageDataGenerator

# 超参数配置
config = {
    "img_size": (300, 300),
    "batch_size": 16,
    "epochs": 50,
    "num_classes": 4,
    "class_names": ["sunny", "rainy", "cloudy", "sunrise"],
    "data_aug": {
        "rotation_range": 45,
        "width_shift_range": 0.3,
        "height_shift_range": 0.3,
        "zoom_range": 0.2,
        "horizontal_flip": True,
        "vertical_flip": True,
        "brightness_range": [0.7, 1.3],
    }
}


def build_model():
    inputs = layers.Input(shape=config["img_size"] + (3,))

    # 使用EfficientNetV2
    effnet = applications.EfficientNetV2B0(
        include_top=False,
        weights='imagenet',
        input_tensor=inputs
    )
    effnet.trainable = False

    x = layers.GlobalAveragePooling2D()(effnet.output)
    x = layers.Dense(512, activation='gelu')(x)
    x = layers.Dropout(0.6)(x)
    outputs = layers.Dense(config["num_classes"], activation='softmax')(x)

    model = models.Model(inputs, outputs)

    model.compile(
        optimizer=Adam(learning_rate=1e-4),
        loss=CategoricalFocalCrossentropy(gamma=2.0),
        metrics=['accuracy']
    )
    return model


def create_datagen(subset):
    if subset == 'train':
        return ImageDataGenerator(
            rescale=1. / 255,
            validation_split=0.2,
            **config["data_aug"]
        )
    else:
        return ImageDataGenerator(
            rescale=1. / 255,
            validation_split=0.2
        )


def main():
    # 数据准备
    train_datagen = create_datagen('train')
    test_datagen = create_datagen('val')

    train_gen = train_datagen.flow_from_directory(
        'dataset',
        target_size=config["img_size"],
        batch_size=config["batch_size"],
        class_mode='categorical',
        subset='training',
        shuffle=True
    )

    val_gen = test_datagen.flow_from_directory(
        'dataset',
        target_size=config["img_size"],
        batch_size=config["batch_size"],
        class_mode='categorical',
        subset='validation'
    )

    # 模型构建
    model = build_model()
    model.summary()

    # 训练
    history = model.fit(
        train_gen,
        steps_per_epoch=train_gen.samples // config["batch_size"],
        validation_data=val_gen,
        validation_steps=val_gen.samples // config["batch_size"],
        epochs=config["epochs"],
        callbacks=[
            EarlyStopping(patience=8, restore_best_weights=True),
            ModelCheckpoint('best_model.h5', save_best_only=True)
        ]
    )

    # 可视化结果
    plt.figure(figsize=(12, 5))
    plt.subplot(1, 2, 1)
    plt.plot(history.history['accuracy'], label='Train Acc')
    plt.plot(history.history['val_accuracy'], label='Val Acc')
    plt.title('Accuracy Curve')
    plt.legend()

    plt.subplot(1, 2, 2)
    plt.plot(history.history['loss'], label='Train Loss')
    plt.plot(history.history['val_loss'], label='Val Loss')
    plt.title('Loss Curve')
    plt.legend()
    plt.savefig('training_metrics.png')
    plt.show()


if __name__ == '__main__':
    main()