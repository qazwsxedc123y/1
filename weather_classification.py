import splitfolders
from tensorflow.keras.preprocessing.image import ImageDataGenerator
from tensorflow.keras.models import Sequential, Model, load_model
from tensorflow.keras.layers import Conv2D, MaxPooling2D, Flatten, Dense, Dropout, BatchNormalization
from tensorflow.keras.callbacks import EarlyStopping, ModelCheckpoint
from tensorflow.keras.applications import VGG16
from tensorflow.keras.preprocessing import image
import numpy as np
import matplotlib.pyplot as plt
import os


# 1. Split dataset
def split_dataset():
    # 划分数据集：训练集70%，测试集30%
    splitfolders.ratio("data/weather/original",
                       output="data/weather/processed",
                       seed=1337,
                       ratio=(.7, .3))


# 2. Prepare data generators
def prepare_data():
    # 训练集数据增强配置
    train_datagen = ImageDataGenerator(
        rescale=1. / 255,
        rotation_range=20,
        width_shift_range=0.2,
        height_shift_range=0.2,
        shear_range=0.2,
        zoom_range=0.2,
        horizontal_flip=True,
        fill_mode='nearest'
    )

    # 测试集只需要归一化
    test_datagen = ImageDataGenerator(rescale=1. / 255)

    # 生成训练集和测试集数据
    train_generator = train_datagen.flow_from_directory(
        'data/weather/processed/train',
        target_size=(150, 150),
        batch_size=32,
        class_mode='categorical'
    )

    test_generator = test_datagen.flow_from_directory(
        'data/weather/processed/val',
        target_size=(150, 150),
        batch_size=32,
        class_mode='categorical'
    )

    return train_generator, test_generator


# 3. Build custom model
def build_custom_model():
    model = Sequential([
        Conv2D(32, (3, 3), activation='relu', input_shape=(150, 150, 3)),
        BatchNormalization(),
        MaxPooling2D(2, 2),

        Conv2D(64, (3, 3), activation='relu'),
        BatchNormalization(),
        MaxPooling2D(2, 2),

        Conv2D(128, (3, 3), activation='relu'),
        BatchNormalization(),
        MaxPooling2D(2, 2),

        Flatten(),
        Dropout(0.5),
        Dense(128, activation='relu'),
        BatchNormalization(),
        Dense(4, activation='softmax')  # 4个类别
    ])

    # 编译模型
    model.compile(
        optimizer='adam',
        loss='categorical_crossentropy',
        metrics=['accuracy']
    )

    return model


# 4. Build pretrained model
def build_pretrained_model():
    # 加载预训练模型
    base_model = VGG16(weights='imagenet', include_top=False, input_shape=(150, 150, 3))

    # 冻结预训练层
    for layer in base_model.layers:
        layer.trainable = False

    # 添加自定义层
    x = base_model.output
    x = Flatten()(x)
    x = Dense(256, activation='relu')(x)
    x = Dropout(0.5)(x)
    predictions = Dense(4, activation='softmax')(x)

    # 构建新模型
    model = Model(inputs=base_model.input, outputs=predictions)

    # 编译模型
    model.compile(
        optimizer='adam',
        loss='categorical_crossentropy',
        metrics=['accuracy']
    )

    return model


# 5. Train models
def train_models(train_generator, test_generator):
    # 训练自定义模型
    custom_model = build_custom_model()

    custom_callbacks = [
        EarlyStopping(patience=3, restore_best_weights=True),
        ModelCheckpoint('models/custom_model.h5', save_best_only=True)
    ]

    custom_history = custom_model.fit(
        train_generator,
        epochs=20,
        validation_data=test_generator,
        callbacks=custom_callbacks
    )

    # 训练预训练模型
    pretrained_model = build_pretrained_model()

    pretrained_callbacks = [
        EarlyStopping(patience=3, restore_best_weights=True),
        ModelCheckpoint('models/pretrained_model.h5', save_best_only=True)
    ]

    pretrained_history = pretrained_model.fit(
        train_generator,
        epochs=10,
        validation_data=test_generator,
        callbacks=pretrained_callbacks
    )

    return custom_model, custom_history, pretrained_model, pretrained_history


# 6. Evaluate models
def evaluate_models(custom_model, pretrained_model, test_generator):
    # 评估模型
    custom_test_loss, custom_test_acc = custom_model.evaluate(test_generator)
    pretrained_test_loss, pretrained_test_acc = pretrained_model.evaluate(test_generator)

    print(f"自建模型测试准确率: {custom_test_acc:.4f}")
    print(f"预训练模型测试准确率: {pretrained_test_acc:.4f}")

    # 选择最佳模型
    best_model = pretrained_model if pretrained_test_acc > custom_test_acc else custom_model
    best_model_name = "预训练模型" if pretrained_test_acc > custom_test_acc else "自建模型"
    print(f"最佳模型: {best_model_name}")

    return best_model


# 7. Plot training history
def plot_history(custom_history, pretrained_history):
    # 绘制准确率曲线
    plt.figure(figsize=(16, 6))

    plt.subplot(1, 2, 1)
    plt.plot(custom_history.history['accuracy'])
    plt.plot(custom_history.history['val_accuracy'])
    plt.title('自建模型准确率')
    plt.ylabel('准确率')
    plt.xlabel('训练轮次')
    plt.legend(['训练', '验证'], loc='lower right')

    plt.subplot(1, 2, 2)
    plt.plot(pretrained_history.history['accuracy'])
    plt.plot(pretrained_history.history['val_accuracy'])
    plt.title('预训练模型准确率')
    plt.ylabel('准确率')
    plt.xlabel('训练轮次')
    plt.legend(['训练', '验证'], loc='lower right')

    plt.tight_layout()
    plt.show()

    # 绘制损失曲线
    plt.figure(figsize=(16, 6))

    plt.subplot(1, 2, 1)
    plt.plot(custom_history.history['loss'])
    plt.plot(custom_history.history['val_loss'])
    plt.title('自建模型损失')
    plt.ylabel('损失')
    plt.xlabel('训练轮次')
    plt.legend(['训练', '验证'], loc='upper right')

    plt.subplot(1, 2, 2)
    plt.plot(pretrained_history.history['loss'])
    plt.plot(pretrained_history.history['val_loss'])
    plt.title('预训练模型损失')
    plt.ylabel('损失')
    plt.xlabel('训练轮次')
    plt.legend(['训练', '验证'], loc='upper right')

    plt.tight_layout()
    plt.show()


# 8. Prediction function
def predict_weather(img_path, model):
    img = image.load_img(img_path, target_size=(150, 150))
    img_array = image.img_to_array(img)
    img_array = np.expand_dims(img_array, axis=0)
    img_array = img_array / 255.0  # 归一化

    predictions = model.predict(img_array)
    class_index = np.argmax(predictions)
    class_names = ['晴天', '多云', '雨', '雪']  # 根据实际类别调整

    return class_names[class_index], predictions[0][class_index]


# Main execution
if __name__ == "__main__":
    # Split dataset
    split_dataset()

    # Prepare data
    train_generator, test_generator = prepare_data()

    # Train models
    custom_model, custom_history, pretrained_model, pretrained_history = train_models(train_generator, test_generator)

    # Evaluate models
    best_model = evaluate_models(custom_model, pretrained_model, test_generator)

    # Plot training history
    plot_history(custom_history, pretrained_history)

    # Test prediction
    test_image_path = 'path_to_test_image.jpg'
    if os.path.exists(test_image_path):
        predicted_class, confidence = predict_weather(test_image_path, best_model)
        print(f"预测结果: {predicted_class}, 置信度: {confidence:.2%}")
    else:
        print("请提供有效的测试图像路径")