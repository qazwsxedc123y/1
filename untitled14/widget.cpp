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


void Widget::on_pushButton_accept_clicked()
{
    ui->label->setText("快嘴一个");
}

void Widget::on_pushButton_reject_clicked()
{
    int width = this->geometry().x();
    int heigh = this->geometry().y();

    int x = rand() % width;
    int y = rand() % heigh;

    ui->pushButton_reject->move(x, y);
}

void Widget::on_pushButton_reject_pressed()
{
    int width = this->geometry().x();
    int heigh = this->geometry().y();

    int x = rand() % width;
    int y = rand() % heigh;

    ui->pushButton_reject->move(x, y);
}
