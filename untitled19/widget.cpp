#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    this->setStyleSheet("background-color: #f3f3f3");

    ui->textEdit->setStyleSheet("background-color: #fff; color: #000;");
    ui->pushButton->setStyleSheet("color: #000");
    ui->pushButton_2->setStyleSheet("color: #000");
}

void Widget::on_pushButton_2_clicked()
{
    this->setStyleSheet("background-color: #333");

    ui->textEdit->setStyleSheet("background-color: #333; color: #fff;");
    ui->pushButton->setStyleSheet("color: #fff");
    ui->pushButton_2->setStyleSheet("color: #fff");
}
