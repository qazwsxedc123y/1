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

// 每点击一下，移动5像素

void Widget::on_target_up_clicked()
{
    QRect rect = ui->target->geometry();


}

void Widget::on_target_left_clicked()
{

}

void Widget::on_target_right_clicked()
{

}

void Widget::on_target_down_clicked()
{

}
