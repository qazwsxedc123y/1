# %% [markdown]
# # 天气图片分类深度学习项目

# %% [markdown]
# ## 1. 项目概述
# 本项目旨在构建一个深度学习模型，能够准确分类四种不同类型的天气图片。我们将使用自定义的CNN模型和预训练的VGG16模型进行比较，选择性能更好的模型。

# %% [markdown]
# ## 2. 数据准备

# %%
import os
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from tensorflow.keras.preprocessing.image import ImageDataGenerator
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Conv2D, MaxPooling2D, Flatten, Dense, Dropout, BatchNormalization
from tensorflow.keras.optimizers import Adam
from tensorflow.keras.applications import VGG16
from tensorflow.keras.models import Model
from tensorflow.keras.callbacks import EarlyStopping, ReduceLROnPlateau
from sklearn.metrics import classification_report, confusion_matrix
import seaborn as sns

# %%
# 设置随机种子以保证结果可重复
np.random.seed(42)

# %% [markdown]
# ### 2.1 下载数据集
# 我们将使用一个包含四种天气类型(晴天、雨天、多云、日出)的数据集

# %%
# 这里假设我们已经有一个包含图片的目录，结构如下：
# dataset/
#     sunny/
#     rainy/
#     cloudy/
#     sunrise/

# 由于我们无法实际访问文件系统，这里模拟一个数据准备过程
# 在实际应用中，你需要将图片放在上述目录结构中

# %% [markdown]
# ### 2.2 数据探索

# %%
# 模拟数据路径（实际使用时需要替换为真实路径）
dataset_dir = r'E:\code\PythonProject1\dataset'
classes = ['sunny', 'rainy', 'cloudy', 'sunrise']
num_classes = len(classes)

# %%
# 检查每个类别的图片数量（模拟）
for cls in classes:
    print(f"{cls} images: 100")  # 假设每个类别有100张图片

# %% [markdown]
# ### 2.3 数据预处理

# %%
# 图像参数
img_width, img_height = 150, 150
batch_size = 32

# %%
# 创建数据生成器
train_datagen = ImageDataGenerator(
    rescale=1. / 255,
    rotation_range=20,
    width_shift_range=0.2,
    height_shift_range=0.2,
    shear_range=0.2,
    zoom_range=0.2,
    horizontal_flip=True,
    fill_mode='nearest',
    validation_split=0.2  # 使用20%的数据作为验证集
)

# 测试数据生成器（只进行归一化）
test_datagen = ImageDataGenerator(rescale=1. / 255)

# %%
# 训练数据生成器
train_generator = train_datagen.flow_from_directory(
    dataset_dir,
    target_size=(img_width, img_height),
    batch_size=batch_size,
    class_mode='categorical',
    subset='training',
    shuffle=True,
    seed=42
)

# 验证数据生成器
validation_generator = train_datagen.flow_from_directory(
    dataset_dir,
    target_size=(img_width, img_height),
    batch_size=batch_size,
    class_mode='categorical',
    subset='validation',
    shuffle=True,
    seed=42
)

# %%
# 查看类别索引
print("Class indices:", train_generator.class_indices)

# %% [markdown]
# ### 2.4 可视化一些样本

# %%
# 从训练数据中获取一个批次
sample_images, sample_labels = next(train_generator)

# %%
# 显示图像
plt.figure(figsize=(12, 8))
for i in range(9):
    plt.subplot(3, 3, i + 1)
    plt.imshow(sample_images[i])
    plt.title(classes[np.argmax(sample_labels[i])])
    plt.axis('off')
plt.tight_layout()
plt.show()


# %% [markdown]
# ## 3. 构建自定义CNN模型

# %%
def build_custom_model(input_shape=(img_width, img_height, 3), num_classes=num_classes):
    model = Sequential([
        Conv2D(32, (3, 3), activation='relu', input_shape=input_shape),
        BatchNormalization(),
        MaxPooling2D((2, 2)),

        Conv2D(64, (3, 3), activation='relu'),
        BatchNormalization(),
        MaxPooling2D((2, 2)),

        Conv2D(128, (3, 3), activation='relu'),
        BatchNormalization(),
        MaxPooling2D((2, 2)),

        Conv2D(256, (3, 3), activation='relu'),
        BatchNormalization(),
        MaxPooling2D((2, 2)),

        Flatten(),
        Dense(512, activation='relu'),
        Dropout(0.5),
        BatchNormalization(),
        Dense(num_classes, activation='softmax')
    ])

    model.compile(optimizer=Adam(learning_rate=0.001),
                  loss='categorical_crossentropy',
                  metrics=['accuracy'])

    return model


# %%
# 创建模型
custom_model = build_custom_model()
custom_model.summary()

# %% [markdown]
# ### 3.1 训练自定义模型

# %%
# 设置回调函数
early_stopping = EarlyStopping(monitor='val_loss', patience=10, restore_best_weights=True)
reduce_lr = ReduceLROnPlateau(monitor='val_loss', factor=0.2, patience=5, min_lr=0.0001)

# %%
# 训练模型
history_custom = custom_model.fit(
    train_generator,
    steps_per_epoch=train_generator.samples // batch_size,
    epochs=50,
    validation_data=validation_generator,
    validation_steps=validation_generator.samples // batch_size,
    callbacks=[early_stopping, reduce_lr],
    verbose=1
)


# %% [markdown]
# ### 3.2 评估自定义模型

# %%
# 绘制训练曲线
def plot_history(history):
    plt.figure(figsize=(12, 4))

    plt.subplot(1, 2, 1)
    plt.plot(history.history['accuracy'], label='Train Accuracy')
    plt.plot(history.history['val_accuracy'], label='Validation Accuracy')
    plt.title('Accuracy over epochs')
    plt.xlabel('Epoch')
    plt.ylabel('Accuracy')
    plt.legend()

    plt.subplot(1, 2, 2)
    plt.plot(history.history['loss'], label='Train Loss')
    plt.plot(history.history['val_loss'], label='Validation Loss')
    plt.title('Loss over epochs')
    plt.xlabel('Epoch')
    plt.ylabel('Loss')
    plt.legend()

    plt.tight_layout()
    plt.show()


# %%
plot_history(history_custom)

# %%
# 在验证集上评估模型
val_loss, val_acc = custom_model.evaluate(validation_generator)
print(f"Custom Model - Validation Accuracy: {val_acc:.4f}, Validation Loss: {val_loss:.4f}")


# %% [markdown]
# ## 4. 使用预训练模型 (VGG16)

# %%
def build_pretrained_model(input_shape=(img_width, img_height, 3), num_classes=num_classes):
    # 加载预训练的VGG16模型，不包括顶部分类层
    base_model = VGG16(weights='imagenet', include_top=False, input_shape=input_shape)

    # 冻结预训练模型的权重
    for layer in base_model.layers:
        layer.trainable = False

    # 在预训练模型基础上添加新的分类层
    x = base_model.output
    x = Flatten()(x)
    x = Dense(512, activation='relu')(x)
    x = Dropout(0.5)(x)
    x = BatchNormalization()(x)
    predictions = Dense(num_classes, activation='softmax')(x)

    # 构建完整模型
    model = Model(inputs=base_model.input, outputs=predictions)

    model.compile(optimizer=Adam(learning_rate=0.001),
                  loss='categorical_crossentropy',
                  metrics=['accuracy'])

    return model


# %%
# 创建预训练模型
pretrained_model = build_pretrained_model()
pretrained_model.summary()

# %% [markdown]
# ### 4.1 训练预训练模型

# %%
# 训练模型
history_pretrained = pretrained_model.fit(
    train_generator,
    steps_per_epoch=train_generator.samples // batch_size,
    epochs=30,
    validation_data=validation_generator,
    validation_steps=validation_generator.samples // batch_size,
    callbacks=[early_stopping, reduce_lr],
    verbose=1
)

# %% [markdown]
# ### 4.2 评估预训练模型

# %%
plot_history(history_pretrained)

# %%
# 在验证集上评估模型
val_loss, val_acc = pretrained_model.evaluate(validation_generator)
print(f"Pretrained Model - Validation Accuracy: {val_acc:.4f}, Validation Loss: {val_loss:.4f}")

# %% [markdown]
# ## 5. 模型比较与选择

# %%
# 比较两个模型的验证准确率
print(f"Custom CNN Model - Best Validation Accuracy: {max(history_custom.history['val_accuracy']):.4f}")
print(f"Pretrained VGG16 Model - Best Validation Accuracy: {max(history_pretrained.history['val_accuracy']):.4f}")


# %% [markdown]
# ### 5.1 微调预训练模型

# %%
# 解冻最后几个卷积块进行微调
def fine_tune_pretrained_model(model):
    # 解冻最后两个卷积块
    for layer in model.layers[-10:]:
        if not isinstance(layer, BatchNormalization):
            layer.trainable = True

    # 重新编译模型，使用更小的学习率
    model.compile(optimizer=Adam(learning_rate=0.0001),
                  loss='categorical_crossentropy',
                  metrics=['accuracy'])

    return model


# %%
# 微调模型
pretrained_model = fine_tune_pretrained_model(pretrained_model)

# %%
# 训练微调后的模型
history_finetuned = pretrained_model.fit(
    train_generator,
    steps_per_epoch=train_generator.samples // batch_size,
    epochs=20,
    validation_data=validation_generator,
    validation_steps=validation_generator.samples // batch_size,
    callbacks=[early_stopping, reduce_lr],
    verbose=1
)

# %%
plot_history(history_finetuned)

# %%
# 评估微调后的模型
val_loss, val_acc = pretrained_model.evaluate(validation_generator)
print(f"Fine-tuned Pretrained Model - Validation Accuracy: {val_acc:.4f}, Validation Loss: {val_loss:.4f}")

# %% [markdown]
# ## 6. 最终模型评估

# %%
# 选择性能最好的模型
if max(history_custom.history['val_accuracy']) > max(history_finetuned.history['val_accuracy']):
    best_model = custom_model
    print("Selected Custom CNN Model as the best model")
else:
    best_model = pretrained_model
    print("Selected Fine-tuned VGG16 Model as the best model")

# %% [markdown]
# ### 6.1 混淆矩阵和分类报告

# %%
# 获取验证集的真实标签和预测标签
validation_generator.reset()
y_true = validation_generator.classes
y_pred = best_model.predict(validation_generator)
y_pred = np.argmax(y_pred, axis=1)

# %%
# 混淆矩阵
cm = confusion_matrix(y_true, y_pred)
plt.figure(figsize=(8, 6))
sns.heatmap(cm, annot=True, fmt='d', cmap='Blues',
            xticklabels=classes, yticklabels=classes)
plt.title('Confusion Matrix')
plt.xlabel('Predicted Label')
plt.ylabel('True Label')
plt.show()

# %%
# 分类报告
print("Classification Report:")
print(classification_report(y_true, y_pred, target_names=classes))

# %% [markdown]
# ## 7. 结论

# %% [markdown]
# 在本项目中，我们构建并比较了两种深度学习模型用于天气图片分类：
# 1. 自定义的CNN模型
# 2. 基于VGG16的预训练模型（包含微调）
#
# 实验结果表明：
# - 自定义CNN模型在验证集上达到了XX%的准确率
# - 预训练VGG16模型在验证集上达到了XX%的准确率
# - 经过微调后，VGG16模型的准确率提升到XX%
#
# 最终我们选择了[自定义CNN/预训练VGG16]模型作为最佳模型，因为...[说明原因]。
#
# 通过引入数据增强、Dropout和BatchNormalization等技术，我们有效地减轻了模型的过拟合问题。

# %% [markdown]
# ## 8. 模型保存

# %%
# 保存最佳模型
best_model.save('best_weather_classifier.h5')
print("Best model saved as 'best_weather_classifier.h5'")