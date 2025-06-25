import os
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from scipy.signal import find_peaks
from matplotlib.colors import ListedColormap
from sklearn.preprocessing import StandardScaler

# 设置中文显示和绘图风格（更新后的样式设置）
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
plt.style.use('seaborn-v0_8')  # 使用兼容的seaborn样式


def load_and_preprocess_data(filepath):
    """加载并预处理光谱数据"""
    try:
        df = pd.read_excel(filepath, engine='openpyxl')

        # 提取波长和数据
        wavelengths = df.columns[1:].values.astype(float)
        samples = df.iloc[:, 1:].values.astype(float)
        sample_names = df.iloc[:, 0].values

        # 标准化数据
        scaler = StandardScaler()
        samples_scaled = scaler.fit_transform(samples)

        # 提取药材名称（去除数字）
        labels = []
        for name in sample_names:
            # 移除末尾数字
            last_non_digit = len(name)
            while last_non_digit > 0 and name[last_non_digit - 1].isdigit():
                last_non_digit -= 1
            labels.append(name[:last_non_digit])

        return wavelengths, samples_scaled, np.array(labels)
    except Exception as e:
        print(f"数据加载失败: {str(e)}")
        print(f"当前工作目录: {os.getcwd()}")
        print(f"目录内容: {os.listdir()}")
        raise


def compare_herbs_spectra(wavelengths, spectra, labels, herbs_to_compare, prominence=0.05):
    """
    比较多种药材的整体光谱趋势
    """
    plt.figure(figsize=(14, 8))

    # 设置颜色
    colors = ListedColormap(['#1f77b4', '#ff7f0e', '#2ca02c', '#d62728', '#9467bd']).colors

    for i, herb in enumerate(herbs_to_compare):
        # 筛选当前药材的样本
        mask = np.array([herb == label for label in labels])
        herb_spectra = spectra[mask]

        if len(herb_spectra) == 0:
            print(f"警告：未找到药材 '{herb}' 的样本")
            continue

        # 计算统计量
        mean_spectrum = np.mean(herb_spectra, axis=0)
        std_spectrum = np.std(herb_spectra, axis=0)

        # 绘制均值曲线
        plt.plot(wavelengths, mean_spectrum,
                 color=colors[i],
                 linewidth=2,
                 label=f'{herb} (n={len(herb_spectra)})')

        # 绘制标准差区域
        plt.fill_between(wavelengths,
                         mean_spectrum - std_spectrum,
                         mean_spectrum + std_spectrum,
                         color=colors[i], alpha=0.1)

        # 检测并标记特征峰
        peaks, _ = find_peaks(mean_spectrum, prominence=prominence)
        for peak in peaks:
            plt.scatter(wavelengths[peak], mean_spectrum[peak],
                        color=colors[i], s=50, zorder=5)
            plt.text(wavelengths[peak], mean_spectrum[peak] + 0.05,
                     f'{wavelengths[peak]:.0f}nm',
                     ha='center', fontsize=9, color=colors[i])

    # 图表美化
    plt.xlabel('波长 (nm)', fontsize=12)
    plt.ylabel('标准化吸光度', fontsize=12)
    plt.title('不同药材红外光谱特征对比', fontsize=14, pad=20)
    plt.legend(fontsize=10, loc='upper right')
    plt.grid(True, linestyle='--', alpha=0.3)
    plt.xlim(wavelengths.min(), wavelengths.max())

    # 创建输出目录
    os.makedirs('results', exist_ok=True)

    # 保存图片
    save_path = 'results/herbs_comparison.png'
    plt.tight_layout()
    plt.savefig(save_path, dpi=300, bbox_inches='tight')
    plt.close()
    print(f"对比图已保存至: {os.path.abspath(save_path)}")


# 主程序
if __name__ == "__main__":
    try:
        # 1. 加载数据
        data_path = "data.xlsx"
        print(f"尝试从 {os.path.abspath(data_path)} 加载数据...")
        wavelengths, X, y = load_and_preprocess_data(data_path)

        # 2. 自动识别数据中的药材种类
        unique_herbs = np.unique(y)
        print(f"数据加载完成，共发现 {len(unique_herbs)} 种药材:")
        print(unique_herbs)

        # 3. 比较前4种药材（可根据需要修改）
        herbs_to_compare = unique_herbs[:4] if len(unique_herbs) >= 4 else unique_herbs
        compare_herbs_spectra(wavelengths, X, y, herbs_to_compare, prominence=0.1)

    except Exception as e:
        print(f"程序运行出错: {str(e)}")
        if 'data_path' in locals():
            print(f"请检查数据文件路径: {os.path.abspath(data_path)}")
            print("确保：")
            print("1. 文件存在且可访问")
            print("2. 文件不是空文件")
            print("3. 文件格式符合要求（第一列为样本名，第一行为波长）")