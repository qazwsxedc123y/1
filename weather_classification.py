# -*- coding: utf-8 -*-
"""
创新天气分类系统 - ConvNeXt-Tiny + 自适应增强
数据集结构：dataset/{sunny,rainy,cloudy,sunrise}/
"""
import os
import numpy as np
import matplotlib.pyplot as plt
import tensorflow as tf
from tensorflow.keras import layers, models
from tensorflow.keras.optimizers import AdamW
from tensorflow.keras.losses import CategoricalCrossentropy
from tensorflow.keras.callbacks import LearningRateScheduler
from tensorflow.keras.applications import ConvNeXtTiny
from tensorflow.keras.preprocessing.image import ImageDataGenerator
from sklearn.metrics import classification_report

# 动态增强策略
class AdaptiveAugmenter:
    def __init__(self):
        self.augmenters = [
            lambda img: tf.image.random_flip_left_right(img),
            lambda img: tf.image.random_flip_up_down(img),
            lambda img: tf.image.random_brightness(img, 0.2),
            lambda img: tf.image.random_contrast(img, 0.8, 1.2),
            lambda img: tf.image.rot90(img, k=np.random.randint(4))
        ]

    def __call__(self, img):
        if np.random.rand() > 0.5:  # 50%概率应用增强
            aug = np.random.choice(self.augmenters)
            img = aug(img)
        return img

# 构建ConvNeXt模型
def build_convnext_model(input_shape=(256, 256, 3), num_classes=4):
    base = ConvNeXtTiny(
        input_shape=input_shape,
        include_top=False,
        weights='imagenet',
        pooling='avg'
    )
    base.trainable = True  # 微调所有层

    inputs = layers.Input(shape=input_shape)
    x = AdaptiveAugmenter()(inputs)  # 应用动态增强
    x = base(x)
    x = layers.Dense(256, activation='gelu')(x)
    x = layers.Dropout(0.4)(x)
    outputs = layers.Dense(num_classes, activation='softmax')(x)

    model = models.Model(inputs, outputs)

    # 标签平滑损失
    loss = CategoricalCrossentropy(label_smoothing=0.1)
    model.compile(
        optimizer=AdamW(learning_rate=1e-4, weight_decay=1e-4),
        loss=loss,
        metrics=['accuracy']
    )
    return model

# 余弦退火学习率
def cosine_decay(epoch, total_epochs=50, init_lr=1e-4):
    return init_lr * 0.5 * (1 + np.cos(np.pi * epoch / total_epochs))

# 数据管道
def create_data_pipeline():
    train_datagen = ImageDataGenerator(
        rescale=1./255,
        validation_split=0.2
    )

    train_gen = train_datagen.flow_from_directory(
        'dataset',
        target_size=(256, 256),
        batch_size=32,
        class_mode='categorical',
        subset='training',
        shuffle=True
    )

    val_gen = train_datagen.flow_from_directory(
        'dataset',
        target_size=(256, 256),
        batch_size=32,
        class_mode='categorical',
        subset='validation'
    )
    return train_gen, val_gen

def main():
    # 准备数据
    train_gen, val_gen = create_data_pipeline()

    # 构建模型
    model = build_convnext_model()
    model.summary()

    # 训练配置
    callbacks = [
        LearningRateScheduler(cosine_decay),
        tf.keras.callbacks.CSVLogger('training_log.csv')
    ]

    # 训练
    history = model.fit(
        train_gen,
        epochs=50,
        validation_data=val_gen,
        callbacks=callbacks
    )

    # 评估
    val_gen.reset()
    y_pred = model.predict(val_gen)
    y_true = val_gen.classes
    print(classification_report(
        y_true,
        np.argmax(y_pred, axis=1),
        target_names=config["class_names"]
    ))

    # 可视化
    plt.figure(figsize=(12, 5))
    plt.subplot(1, 2, 1)
    plt.plot(history.history['accuracy'], label='Train')
    plt.plot(history.history['val_accuracy'], label='Val')
    plt.title('Accuracy Curve')
    plt.legend()

    plt.subplot(1, 2, 2)
    plt.plot(history.history['loss'], label='Train')
    plt.plot(history.history['val_loss'], label='Val')
    plt.title('Loss Curve')
    plt.legend()
    plt.savefig('convnext_metrics.png')

if __name__ == '__main__':
    config = {
        "class_names": ["sunny", "rainy", "cloudy", "sunrise"]
    }
    main()