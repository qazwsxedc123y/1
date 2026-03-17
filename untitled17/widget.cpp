#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
//    ui->setupUi(this);
//    ui->pushButton->setToolTip("这是一个表示同意的按钮");
//    ui->pushButton->setToolTipDuration(3000);

//    ui->pushButton_2->setToolTip("这是一个表示同意的按钮");
//    ui->pushButton_2->setToolTipDuration(3000);
}

Widget::~Widget()
{
    delete ui;
}

