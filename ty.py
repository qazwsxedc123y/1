# 天气分类精简版 (MobileNetV3)
import os
import numpy as np
import matplotlib.pyplot as plt
import tensorflow as tf
from tensorflow.keras import layers, models
from tensorflow.keras.applications import MobileNetV3Small
from tensorflow.keras.preprocessing.image import ImageDataGenerator

# 配置参数
IMG_SIZE = 160
BATCH_SIZE = 32
EPOCHS = 30
CLASS_NAMES = ['sunny', 'rainy', 'cloudy', 'sunrise']

# 数据增强
train_datagen = ImageDataGenerator(
    rescale=1. / 255,
    rotation_range=20,
    zoom_range=0.2,
    height_shift_range=0.2,
    width_shift_range=0.2,
    horizontal_flip=True,
    validation_split=0.2
)


# 数据加载
def load_data():
    train_gen = train_datagen.flow_from_directory(
        'dataset',
        target_size=(IMG_SIZE, IMG_SIZE),
        batch_size=BATCH_SIZE,
        class_mode='categorical',
        subset='training'
    )

    val_gen = train_datagen.flow_from_directory(
        'dataset',
        target_size=(IMG_SIZE, IMG_SIZE),
        batch_size=BATCH_SIZE,
        class_mode='categorical',
        subset='validation'
    )
    return train_gen, val_gen


# 构建轻量模型
def build_lite_model():
    base = MobileNetV3Small(
        input_shape=(IMG_SIZE, IMG_SIZE, 3),
        include_top=False,
        weights='imagenet',
        pooling='avg'
    )
    base.trainable = True

    model = models.Sequential([
        layers.Input(shape=(IMG_SIZE, IMG_SIZE, 3)),
        base,
        layers.Dropout(0.3),
        layers.Dense(4, activation='softmax')
    ])

    model.compile(
        optimizer=tf.keras.optimizers.Adam(0.0001),
        loss='categorical_crossentropy',
        metrics=['accuracy']
    )
    return model


# 训练可视化
def plot_results(history):
    plt.figure(figsize=(12, 4))
    plt.subplot(1, 2, 1)
    plt.plot(history.history['accuracy'], label='Train')
    plt.plot(history.history['val_accuracy'], label='Val')
    plt.title('Accuracy')
    plt.legend()

    plt.subplot(1, 2, 2)
    plt.plot(history.history['loss'], label='Train')
    plt.plot(history.history['val_loss'], label='Val')
    plt.title('Loss')
    plt.legend()
    plt.savefig('lite_model_results.png')


# 主流程
def main():
    # 加载数据
    train_gen, val_gen = load_data()
    print(f"Classes: {train_gen.class_indices}")

    # 构建模型
    model = build_lite_model()
    model.summary()

    # 训练
    history = model.fit(
        train_gen,
        validation_data=val_gen,
        epochs=EPOCHS,
        callbacks=[
            tf.keras.callbacks.EarlyStopping(patience=5),
            tf.keras.callbacks.ModelCheckpoint('best_lite_model.h5')
        ]
    )

    # 评估
    plot_results(history)
    print("Training completed. Model saved to 'best_lite_model.h5'")


if __name__ == '__main__':
    main()