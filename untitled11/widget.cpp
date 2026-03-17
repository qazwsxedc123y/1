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

// 按钮点击，互相却换对方的状态
void Widget::on_pushButton_clicked()
{
    if(ui->pushButton_2->isEnabled() == false)
    {
        ui->pushButton_2->setEnabled(true);
    }
    else
    {
        ui->pushButton_2->setEnabled(false);
    }
}

void Widget::on_pushButton_2_clicked()
{
    if(ui->pushButton->isEnabled() == false)
    {
        ui->pushButton->setEnabled(true);
    }
    else
    {
        ui->pushButton->setEnabled(false);
    }
}
