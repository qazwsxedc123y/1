#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


//    connect(button, &QPushButton::clicked, this, &Widget::on_pushButton_clicked);
    connect(this, &Widget::mysignal, this, &Widget::handle);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::handle()
{
    this->setWindowTitle("嘻嘻嘻嘻");
}

void Widget::on_pushButton_clicked()
{
    emit mysignal();
}

void Widget::on_pushButton_2_clicked()
{
    this->setWindowTitle("按钮已被按下");
}
