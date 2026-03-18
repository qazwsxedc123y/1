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


void Widget::on_pushButton_clicked()
{
    QString ret;
    if(ui->checkBox->isChecked())
    {
        ret += ui->checkBox->text();
    }
    if(ui->checkBox_2->isChecked())
    {
        ret += ui->checkBox_2->text();
    }
    if(ui->checkBox_3->isChecked())
    {
        ret += ui->checkBox_3->text();
    }
    qDebug() << "今日的安排" << ret;
}
