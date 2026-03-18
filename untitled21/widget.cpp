#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QButtonGroup>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) 
{
    ui->setupUi(this);

    // 创建三个分组
    QButtonGroup* group1 = new QButtonGroup(this);
    QButtonGroup* group2 = new QButtonGroup(this);
    QButtonGroup* group3 = new QButtonGroup(this);

    group1->addButton(ui->radioButton);
    group1->addButton(ui->radioButton_2);
    group1->addButton(ui->radioButton_3);

    group2->addButton(ui->radioButton_4);
    group2->addButton(ui->radioButton_5);
    group2->addButton(ui->radioButton_6);

    group3->addButton(ui->radioButton_7);
    group3->addButton(ui->radioButton_8);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    qDebug() << s1 << ";" << s2 << ";" << s3;
}

void Widget::on_radioButton_clicked()
{
    s1 = "选择的主食：汉堡1";
}

void Widget::on_radioButton_2_clicked()
{
    s1 = "选择的主食：汉堡2";
}

void Widget::on_radioButton_3_clicked()
{
    s1 = "选择的主食：汉堡3";
}


void Widget::on_radioButton_4_clicked()
{
    s2 = "选择的小食：小食1";
}

void Widget::on_radioButton_6_clicked()
{
    s2 = "选择的小食：小食2";
}

void Widget::on_radioButton_5_clicked()
{
    s2 = "选择的小食：小食3";
}

void Widget::on_radioButton_7_clicked()
{
    s3 = "选择的饮料：饮料1";
}

void Widget::on_radioButton_8_clicked()
{
    s3 = "选择的饮料：饮料2";
}
