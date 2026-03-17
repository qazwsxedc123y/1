#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
}

Widget::~Widget()
{
    delete ui;
}

//void Widget::handle()
//{
//    this->setWindowTitle("按钮已被按下");
//}




void Widget::on_pushButton_clicked()
{
    this->setWindowTitle("还是损失函数");
}
