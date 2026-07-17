#ifndef RECBOX_H
#define RECBOX_H

#include <QWidget>
#include "recboxitem.h"
#include <QJsonArray>
#include <QJsonObject>
#include <cmath>

namespace Ui {
class RecBox;
}

class RecBox : public QWidget
{
    Q_OBJECT

public:
    explicit RecBox(QWidget *parent = nullptr);
    ~RecBox();

    void initRecBoxUi(QJsonArray data, int row);

    // 根据固件的Json串，添加图片
    void createRecItem();

private slots:
    void on_PageUp_clicked();

    void on_PageDown_clicked();

private:
    Ui::RecBox *ui;
    int row; // 行数
    int col; // 列数
    QJsonArray imageList; // 实际Json串保存的是界面图片与文版，其为key,value键值对
    int currentIndex; // 当前显示的为第几组照片的信息
    int count; // 标记imageList中元素按照col分组的总组数
};

#endif // RECBOX_H
