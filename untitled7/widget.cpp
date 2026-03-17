#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Widget::handle1);
}
void Widget::handle1()
{
    this->setWindowTitle("当前标题1");
    qDebug() << "当前标题1";
}
void Widget::handle2()
{
    this->setWindowTitle("当前标题2");
    qDebug() << "当前标题2";
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    //disconnect(ui->pushButton_2, &QPushButton::clicked, this, &Widget::handle1);

    connect(ui->pushButton_2, &QPushButton::clicked, this, &Widget::handle2);
}
