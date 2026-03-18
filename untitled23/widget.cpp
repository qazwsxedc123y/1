#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QResizeEvent>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 先将lable设置为与窗口大小一致
    ui->label->setGeometry(0, 0, this->width(), this->height());

    QPixmap pixmap(":/1.png");
    ui->label->setPixmap(pixmap);
    ui->label->setScaledContents(true);
}
void Widget::resizeEvent(QResizeEvent *event)
{
    ui->label->setGeometry(0, 0, event->size().width(), event->size().height());
    qDebug() << event->size();
}

Widget::~Widget()
{
    delete ui;
}

