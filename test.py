import os
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.metrics import confusion_matrix, classification_report
from sklearn.model_selection import train_test_split
from tensorflow.keras.preprocessing.image import ImageDataGenerator
from tensorflow.keras.models import Sequential, Model
from tensorflow.keras.layers import (Conv2D, MaxPooling2D, Flatten, Dense,
                                     Dropout, BatchNormalization, GlobalAveragePooling2D,
                                     Multiply, Reshape, Permute)
from tensorflow.keras.optimizers import Adam
from tensorflow.keras.applications import EfficientNetB0, MobileNetV2
from tensorflow.keras.mixed_precision import experimental as mixed_precision
from tensorflow.keras.callbacks import (EarlyStopping, ReduceLROnPlateau,
                                        ModelCheckpoint, TerminateOnNaN)
from tensorflow.keras.utils import to_categorical
from PIL import Image
import random
import tensorflow as tf

# 启用混合精度训练
policy = mixed_precision.Policy('mixed_float16')
mixed_precision.set_policy(policy)

# 设置随机种子保证可重复性
random.seed(2023)
np.random.seed(2023)
tf.random.set_seed(2023)


# %%
class SmartDataLoader:
    def __init__(self, dataset_path, classes, target_size=(224, 224)):
        self.dataset_path = dataset_path
        self.classes = classes
        self.target_size = target_size
        self.class_weights = None

    def _calculate_class_weights(self, labels):
        class_counts = np.bincount(labels)
        total_samples = len(labels)
        self.class_weights = {i: total_samples / (len(class_counts) * count)
                              for i, count in enumerate(class_counts)}

    def load_data(self):
        images = []
        labels = []

        print("正在智能加载数据...")
        for class_idx, class_name in enumerate(self.classes):
            class_path = os.path.join(self.dataset_path, class_name)
            for img_name in os.listdir(class_path):
                img_path = os.path.join(class_path, img_name)
                try:
                    img = Image.open(img_path).convert('RGB')
                    img = img.resize(self.target_size)
                    images.append(np.array(img) / 255.0)  # 归一化
                    labels.append(class_idx)
                except Exception as e:
                    print(f"智能跳过损坏图像: {img_path} - 错误: {str(e)}")

        images = np.array(images, dtype=np.float32)
        labels = np.array(labels)

        self._calculate_class_weights(labels)
        print("数据加载完成，类别权重:", self.class_weights)

        return images, labels


# 初始化智能数据加载器
data_loader = SmartDataLoader('weather_dataset', ['sunny', 'rainy', 'cloudy', 'sunrise'])
X, y = data_loader.load_data()

# 可视化数据分布
plt.figure(figsize=(10, 6))
sns.countplot(x=y)
plt.title("数据集类别分布")
plt.xticks(ticks=range(4), labels=data_loader.classes)
plt.show()

# %%
def create_augmenter():
    base_aug = ImageDataGenerator(
        rotation_range=30,
        width_shift_range=0.25,
        height_shift_range=0.25,
        shear_range=0.2,
        zoom_range=0.3,
        horizontal_flip=True,
        vertical_flip=True,
        fill_mode='reflect'
    )

    advanced_aug = ImageDataGenerator(
        brightness_range=[0.7, 1.3],
        channel_shift_range=50,
        preprocessing_function=lambda x: apply_random_erase(x, probability=0.5)
    )

    return base_aug, advanced_aug


def apply_random_erase(image, probability=0.5, sl=0.02, sh=0.4, r1=0.3):
    if np.random.rand() > probability:
        return image

    h, w, c = image.shape
    area = h * w

    for _ in range(100):
        erase_area = np.random.uniform(sl, sh) * area
        aspect_ratio = np.random.uniform(r1, 1 / r1)

        h_erase = int(np.sqrt(erase_area * aspect_ratio))
        w_erase = int(np.sqrt(erase_area / aspect_ratio))

        if h_erase < h and w_erase < w:
            x1 = np.random.randint(0, h - h_erase)
            y1 = np.random.randint(0, w - w_erase)

            image[x1:x1 + h_erase, y1:y1 + w_erase, :] = np.random.uniform(0, 1, (h_erase, w_erase, c))
            break

    return image


# 演示数据增强效果
demo_img = X[0]
base_aug, advanced_aug = create_augmenter()

plt.figure(figsize=(15, 5))
for i in range(5):
    plt.subplot(1, 5, i + 1)
    augmented = base_aug.random_transform(demo_img)
    if i >= 3:
        augmented = advanced_aug.random_transform(augmented)
    plt.imshow(augmented)
    plt.axis('off')
    plt.title(f"增强样本 {i + 1}")
plt.suptitle("创新数据增强效果展示", y=1.05)
plt.show()

"""
## 注意力增强的轻量级模型架构

我们设计了一个包含通道注意力机制的高效网络结构。
"""


# %%
def channel_attention_block(inputs, ratio=8):
    channel_axis = -1
    channels = inputs.shape[channel_axis]

    shared_layer_one = Dense(channels // ratio, activation='relu', kernel_initializer='he_normal')
    shared_layer_two = Dense(channels, kernel_initializer='he_normal')

    avg_pool = GlobalAveragePooling2D()(inputs)
    avg_pool = Reshape((1, 1, channels))(avg_pool)
    avg_pool = shared_layer_one(avg_pool)
    avg_pool = shared_layer_two(avg_pool)

    max_pool = tf.reduce_max(inputs, axis=[1, 2], keepdims=True)
    max_pool = shared_layer_one(max_pool)
    max_pool = shared_layer_two(max_pool)

    cbam_feature = tf.keras.layers.Add()([avg_pool, max_pool])
    cbam_feature = tf.keras.layers.Activation('sigmoid')(cbam_feature)

    return Multiply()([inputs, cbam_feature])


def build_attention_model(input_shape=(224, 224, 3), num_classes=4):
    inputs = tf.keras.Input(shape=input_shape)

    # 初始卷积块
    x = Conv2D(32, (3, 3), activation='relu', padding='same')(inputs)
    x = BatchNormalization()(x)
    x = MaxPooling2D((2, 2))(x)

    # 注意力增强块1
    x = Conv2D(64, (3, 3), activation='relu', padding='same')(x)
    x = BatchNormalization()(x)
    x = channel_attention_block(x)
    x = MaxPooling2D((2, 2))(x)

    # 注意力增强块2
    x = Conv2D(128, (3, 3), activation='relu', padding='same')(x)
    x = BatchNormalization()(x)
    x = channel_attention_block(x)
    x = MaxPooling2D((2, 2))(x)

    # 输出层
    x = GlobalAveragePooling2D()(x)
    x = Dense(256, activation='relu')(x)
    x = Dropout(0.5)(x)
    outputs = Dense(num_classes, activation='softmax', dtype='float32')(x)

    model = Model(inputs=inputs, outputs=outputs)

    model.compile(optimizer=Adam(learning_rate=1e-3),
                  loss='sparse_categorical_crossentropy',
                  metrics=['accuracy'])

    return model


attention_model = build_attention_model()
attention_model.summary()

"""
## 高效迁移学习策略

我们采用渐进式解冻技术优化预训练模型。
"""


# %%
def build_transfer_model(base_model, num_classes=4):
    # 冻结所有层
    for layer in base_model.layers:
        layer.trainable = False

    inputs = tf.keras.Input(shape=(224, 224, 3))
    x = base_model(inputs, training=False)
    x = GlobalAveragePooling2D()(x)
    x = Dense(256, activation='relu')(x)
    x = Dropout(0.5)(x)
    outputs = Dense(num_classes, activation='softmax')(x)

    model = Model(inputs=inputs, outputs=outputs)

    model.compile(optimizer=Adam(learning_rate=1e-3),
                  loss='sparse_categorical_crossentropy',
                  metrics=['accuracy'])

    return model


# 创建两个不同的预训练模型
effnet = EfficientNetB0(weights='imagenet', include_top=False, input_shape=(224, 224, 3))
mobilenet = MobileNetV2(weights='imagenet', include_top=False, input_shape=(224, 224, 3))

effnet_model = build_transfer_model(effnet)
mobilenet_model = build_transfer_model(mobilenet)

"""
## 智能训练系统

实现动态学习率调整和渐进式解冻。
"""


# %%
class SmartTrainer:
    def __init__(self, models, X_train, y_train, X_val, y_val, batch_size=32):
        self.models = models
        self.X_train = X_train
        self.y_train = y_train
        self.X_val = X_val
        self.y_val = y_val
        self.batch_size = batch_size
        self.histories = []

    def progressive_unfreeze(self, model, unfreeze_layers=10):
        for layer in model.layers[-unfreeze_layers:]:
            if not isinstance(layer, BatchNormalization):
                layer.trainable = True

        model.compile(optimizer=Adam(learning_rate=1e-4),
                      loss='sparse_categorical_crossentropy',
                      metrics=['accuracy'])

    def train_model(self, model, epochs=20, callbacks=None, augmenter=None):
        if callbacks is None:
            callbacks = [
                EarlyStopping(patience=5, restore_best_weights=True),
                ReduceLROnPlateau(factor=0.2, patience=3, min_lr=1e-6),
                TerminateOnNaN()
            ]

        if augmenter is None:
            augmenter = create_augmenter()[0]

        history = model.fit(
            augmenter.flow(self.X_train, self.y_train, batch_size=self.batch_size),
            steps_per_epoch=len(self.X_train) // self.batch_size,
            epochs=epochs,
            validation_data=(self.X_val, self.y_val),
            callbacks=callbacks,
            class_weight=data_loader.class_weights
        )

        self.histories.append(history)
        return history

    def train_all(self, initial_epochs=15, fine_tune_epochs=10):
        results = {}

        # 训练注意力模型
        print("\n训练注意力模型...")
        results['attention'] = self.train_model(self.models['attention'], initial_epochs)

        # 训练EfficientNet
        print("\n训练EfficientNet...")
        results['effnet'] = self.train_model(self.models['effnet'], initial_epochs)
        self.progressive_unfreeze(self.models['effnet'].layers[1])  # 解冻基础模型
        results['effnet_fine'] = self.train_model(self.models['effnet'], fine_tune_epochs)

        # 训练MobileNet
        print("\n训练MobileNet...")
        results['mobilenet'] = self.train_model(self.models['mobilenet'], initial_epochs)
        self.progressive_unfreeze(self.models['mobilenet'].layers[1])  # 解冻基础模型
        results['mobilenet_fine'] = self.train_model(self.models['mobilenet'], fine_tune_epochs)

        return results


# 数据划分
X_train, X_val, y_train, y_val = train_test_split(X, y, test_size=0.2, stratify=y, random_state=2023)

# 初始化训练器
trainer = SmartTrainer(
    models={
        'attention': attention_model,
        'effnet': effnet_model,
        'mobilenet': mobilenet_model
    },
    X_train=X_train,
    y_train=y_train,
    X_val=X_val,
    y_val=y_val,
    batch_size=32
)

# 开始训练
training_results = trainer.train_all(initial_epochs=15, fine_tune_epochs=10)

"""
## 模型融合与评估

我们采用加权平均法融合多个模型的预测结果。
"""


# %%
class ModelEnsembler:
    def __init__(self, models, weights=None):
        self.models = models
        self.weights = weights if weights else [1 / len(models)] * len(models)

    def predict(self, X):
        predictions = []
        for model in self.models:
            pred = model.predict(X, verbose=0)
            predictions.append(pred)

        weighted_preds = np.zeros_like(predictions[0])
        for pred, weight in zip(predictions, self.weights):
            weighted_preds += pred * weight

        return weighted_preds / sum(self.weights)

    def evaluate(self, X, y):
        y_pred = self.predict(X)
        y_pred_classes = np.argmax(y_pred, axis=1)

        # 计算指标
        accuracy = np.mean(y_pred_classes == y)
        cm = confusion_matrix(y, y_pred_classes)
        cr = classification_report(y, y_pred_classes, target_names=data_loader.classes)

        return accuracy, cm, cr


# 创建集成模型
ensemble = ModelEnsembler(
    models=[attention_model, effnet_model, mobilenet_model],
    weights=[0.3, 0.4, 0.3]  # 根据验证性能调整权重
)

# 评估集成模型
ensemble_acc, ensemble_cm, ensemble_cr = ensemble.evaluate(X_val, y_val)
print(f"集成模型准确率: {ensemble_acc:.4f}")
print("\n分类报告:\n", ensemble_cr)

# 可视化混淆矩阵
plt.figure(figsize=(8, 6))
sns.heatmap(ensemble_cm, annot=True, fmt='d', cmap='Blues',
            xticklabels=data_loader.classes, yticklabels=data_loader.classes)
plt.title("集成模型混淆矩阵")
plt.xlabel("预测标签")
plt.ylabel("真实标签")
plt.show()
