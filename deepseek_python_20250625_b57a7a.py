import os
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.preprocessing import StandardScaler, LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report, confusion_matrix
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Dropout
from tensorflow.keras.utils import to_categorical
from tensorflow.keras.callbacks import EarlyStopping
from tensorflow.keras.optimizers import Adam
output_dir = "output_figures"
os.makedirs(output_dir, exist_ok=True)

def load_data(filepath):
    """加载并处理光谱数据"""
    df = pd.read_excel(filepath, engine='openpyxl')

    # 提取波长（第一行）
    wavelengths = df.columns[1:].values.astype(float)

    # 提取样本数据和标签
    samples = df.iloc[:, 1:].values.astype(float)  # 光谱数据
    sample_names = df.iloc[:, 0].values  # 样本名称

    # 从样本名提取药材种类（移除数字）
    labels = np.array([name.rstrip('0123456789') for name in sample_names])

    return wavelengths, samples, labels


def plot_confusion_matrix(y_true, y_pred, classes):
    cm = confusion_matrix(y_true, y_pred)
    fig = plt.figure(figsize=(10, 8))
    plt.imshow(cm, interpolation='nearest', cmap=plt.cm.Blues)
    plt.title('混淆矩阵')  # 现在可以正常显示中文
    plt.colorbar()
    tick_marks = np.arange(len(classes))
    plt.xticks(tick_marks, classes, rotation=45)
    plt.yticks(tick_marks, classes)

    # 标注数值
    thresh = cm.max() / 2.
    for i in range(cm.shape[0]):
        for j in range(cm.shape[1]):
            plt.text(j, i, format(cm[i, j], 'd'),
                     ha="center", va="center",
                     color="white" if cm[i, j] > thresh else "black")

    plt.ylabel('True label')
    plt.xlabel('Predicted label')
    plt.tight_layout()
    plt.show()


def main():
    try:
        # 1. 加载数据
        filepath = "data.xlsx"  # 修改为你的文件名
        wavelengths, X, y = load_data(filepath)

        print(f"数据加载成功！共 {len(y)} 个样本，{X.shape[1]} 个波长特征")
        print("药材类别分布：")
        print(pd.Series(y).value_counts())

        # 2. 数据预处理
        scaler = StandardScaler()
        X_scaled = scaler.fit_transform(X)

        # 标签编码
        le = LabelEncoder()
        y_encoded = le.fit_transform(y)
        y_onehot = to_categorical(y_encoded)

        # 3. 分割数据集
        X_train, X_test, y_train, y_test, y_train_labels, y_test_labels = train_test_split(
            X_scaled, y_onehot, y,
            test_size=0.2,
            stratify=y,  # 保持类别比例
            random_state=42
        )

        # 4. 构建模型
        model = Sequential([
            Dense(256, activation='relu', input_shape=(X_train.shape[1],)),
            Dropout(0.5),
            Dense(128, activation='relu'),
            Dropout(0.3),
            Dense(len(le.classes_), activation='softmax')
        ])

        model.compile(
            optimizer=Adam(learning_rate=0.001),
            loss='categorical_crossentropy',
            metrics=['accuracy']
        )

        # 5. 训练模型
        early_stop = EarlyStopping(monitor='val_loss', patience=30, restore_best_weights=True)

        history = model.fit(
            X_train, y_train,
            epochs=300,
            batch_size=16,
            validation_split=0.1,
            callbacks=[early_stop],
            verbose=1
        )

        # 6. 评估模型
        # 训练过程曲线
        plt.figure(figsize=(12, 5))
        plt.subplot(1, 2, 1)
        plt.plot(history.history['loss'], label='Train Loss')
        plt.plot(history.history['val_loss'], label='Validation Loss')
        plt.title('Loss Curve')
        plt.legend()

        plt.subplot(1, 2, 2)
        plt.plot(history.history['accuracy'], label='Train Accuracy')
        plt.plot(history.history['val_accuracy'], label='Validation Accuracy')
        plt.title('Accuracy Curve')
        plt.legend()
        plt.show()

        # 测试集评估
        y_pred = model.predict(X_test)
        y_pred_labels = le.inverse_transform(np.argmax(y_pred, axis=1))

        print("\n分类报告:")
        print(classification_report(y_test_labels, y_pred_labels, target_names=le.classes_))

        # 混淆矩阵
        plot_confusion_matrix(y_test_labels, y_pred_labels, le.classes_)

        # 7. 保存模型（可选）
        # model.save('chinese_herb_classifier.h5')
        # print("模型已保存")

    except Exception as e:
        print(f"程序出错: {str(e)}")
        if 'filepath' in locals():
            print(f"当前工作目录: {os.getcwd()}")
            print(f"目录内容: {os.listdir()}")
            print(f"尝试加载的文件: {os.path.abspath(filepath)}")


if __name__ == "__main__":
    main()