#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

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


void Widget::on_radioButton_clicked(bool checked)
{
    qDebug() << "点击";
}

void Widget::on_radioButton_2_pressed()
{
    qDebug() << "点击2";
}
