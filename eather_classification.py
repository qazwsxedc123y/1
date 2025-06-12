import torch
import torch.nn as nn
import torch.optim as optim
from torchvision import transforms, models, datasets
from torch.utils.data import DataLoader, Subset
import os
import numpy as np
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt
from tqdm import tqdm

# 1. 设备配置
device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
print(f"使用设备: {device}")

# 2. 数据准备
def prepare_data(data_dir='./weather_dataset', batch_size=32, test_size=0.2):
    transform = transforms.Compose([
        transforms.Resize((224, 224)),
        transforms.RandomHorizontalFlip(),
        transforms.RandomRotation(10),
        transforms.ToTensor(),
        transforms.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225])
    ])
    
    dataset = datasets.ImageFolder(data_dir, transform=transform)
    targets = [s[1] for s in dataset.samples]
    
    # 划分训练集和测试集
    train_idx, test_idx = train_test_split(
        np.arange(len(targets)), 
        test_size=test_size, 
        shuffle=True,
        stratify=targets
    )
    
    train_loader = DataLoader(
        Subset(dataset, train_idx),
        batch_size=batch_size,
        shuffle=True
    )
    
    test_loader = DataLoader(
        Subset(dataset, test_idx),
        batch_size=batch_size,
        shuffle=False
    )
    
    return train_loader, test_loader, dataset.classes

# 3. 自定义模型
class SimpleCNN(nn.Module):
    def __init__(self, num_classes=4):
        super().__init__()
        self.features = nn.Sequential(
            nn.Conv2d(3, 32, 3, padding=1),
            nn.BatchNorm2d(32),
            nn.ReLU(),
            nn.MaxPool2d(2),
            
            nn.Conv2d(32, 64, 3, padding=1),
            nn.BatchNorm2d(64),
            nn.ReLU(),
            nn.MaxPool2d(2),
        )
        
        self.classifier = nn.Sequential(
            nn.Dropout(0.5),
            nn.Linear(64*56*56, 128),
            nn.ReLU(),
            nn.Linear(128, num_classes)
        )
    
    def forward(self, x):
        x = self.features(x)
        x = x.view(x.size(0), -1)
        x = self.classifier(x)
        return x

# 4. 训练和评估函数
def train_model(model, train_loader, test_loader, epochs=10, lr=0.001):
    criterion = nn.CrossEntropyLoss()
    optimizer = optim.Adam(model.parameters(), lr=lr)
    
    results = {'train_loss': [], 'train_acc': [], 'test_loss': [], 'test_acc': []}
    
    for epoch in range(epochs):
        model.train()
        running_loss, correct, total = 0.0, 0, 0
        
        for images, labels in tqdm(train_loader, desc=f'Epoch {epoch+1}/{epochs}'):
            images, labels = images.to(device), labels.to(device)
            
            optimizer.zero_grad()
            outputs = model(images)
            loss = criterion(outputs, labels)
            loss.backward()
            optimizer.step()
            
            running_loss += loss.item()
            _, predicted = torch.max(outputs.data, 1)
            total += labels.size(0)
            correct += (predicted == labels).sum().item()
        
        # 记录训练结果
        results['train_loss'].append(running_loss/len(train_loader))
        results['train_acc'].append(100*correct/total)
        
        # 测试集评估
        model.eval()
        test_loss, test_correct, test_total = 0.0, 0, 0
        with torch.no_grad():
            for images, labels in test_loader:
                images, labels = images.to(device), labels.to(device)
                outputs = model(images)
                test_loss += criterion(outputs, labels).item()
                _, predicted = torch.max(outputs.data, 1)
                test_total += labels.size(0)
                test_correct += (predicted == labels).sum().item()
        
        results['test_loss'].append(test_loss/len(test_loader))
        results['test_acc'].append(100*test_correct/test_total)
        
        print(f"Epoch {epoch+1}: "
              f"Train Loss: {results['train_loss'][-1]:.4f}, "
              f"Train Acc: {results['train_acc'][-1]:.2f}% | "
              f"Test Loss: {results['test_loss'][-1]:.4f}, "
              f"Test Acc: {results['test_acc'][-1]:.2f}%")
    
    return results

# 5. 主程序
if __name__ == '__main__':
    # 准备数据
    print("准备数据...")
    train_loader, test_loader, classes = prepare_data()
    print(f"分类类别: {classes}")
    
    # 创建模型
    print("\n创建自定义CNN模型...")
    custom_model = SimpleCNN(len(classes)).to(device)
    custom_results = train_model(custom_model, train_loader, test_loader, epochs=10)
    
    # 创建预训练模型
    print("\n创建预训练ResNet18模型...")
    pretrained_model = models.resnet18(pretrained=True)
    for param in pretrained_model.parameters():  # 冻结参数
        param.requires_grad = False
    pretrained_model.fc = nn.Linear(pretrained_model.fc.in_features, len(classes))
    pretrained_model = pretrained_model.to(device)
    
    pretrained_results = train_model(pretrained_model, train_loader, test_loader, epochs=5, lr=0.0001)
    
    # 结果比较
    print("\n模型比较:")
    print(f"自定义CNN - 最终测试准确率: {custom_results['test_acc'][-1]:.2f}%")
    print(f"预训练模型 - 最终测试准确率: {pretrained_results['test_acc'][-1]:.2f}%")
    
    # 绘制结果
    plt.figure(figsize=(12, 5))
    plt.subplot(1, 2, 1)
    plt.plot(custom_results['train_acc'], label='Custom Train')
    plt.plot(custom_results['test_acc'], label='Custom Test')
    plt.plot(pretrained_results['test_acc'], label='Pretrained Test')
    plt.title('Accuracy Comparison')
    plt.xlabel('Epoch')
    plt.ylabel('Accuracy (%)')
    plt.legend()
    
    plt.subplot(1, 2, 2)
    plt.plot(custom_results['train_loss'], label='Custom Train')
    plt.plot(custom_results['test_loss'], label='Custom Test')
    plt.plot(pretrained_results['test_loss'], label='Pretrained Test')
    plt.title('Loss Comparison')
    plt.xlabel('Epoch')
    plt.ylabel('Loss')
    plt.legend()
    
    plt.tight_layout()
    plt.show()