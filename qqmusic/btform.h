#ifndef BTFORM_H
#define BTFORM_H

#include <QWidget>
#include <QIcon>
#include <QPixmap>
#include <QString>
#include <QPropertyAnimation>

namespace Ui {
class BtForm;
}

class BtForm : public QWidget
{
    Q_OBJECT
protected:
    void mousePressEvent(QMouseEvent *event)override;
public:
    explicit BtForm(QWidget *parent = nullptr);
    ~BtForm();
    // 设置相关信息
    void seticon(QString btIcon,QString content,int mid);
    // 获取当前界面的id
    int getId();
    // 清楚背景样式
    void clearBackground();
    void initBtForm();
    void showAnimal();
signals:
    void btclick(int id);
private:
    Ui::BtForm *ui;
    // 按钮对应页
    int id = 0;
    // linebox动画起伏效果
    QPropertyAnimation *animationLine1;
    QPropertyAnimation *animationLine2;
    QPropertyAnimation *animationLine3;
    QPropertyAnimation *animationLine4;
};

#endif // BTFORM_H
