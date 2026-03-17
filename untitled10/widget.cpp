#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* bin  = new QPushButton(this);
    bin->setText("按钮被点击后，状态会变为禁用");
    qDebug() << "当前按钮的状态: " <<  bin->isEnabled();
    connect(bin, &QPushButton::clicked, this, &Widget::myhandle);

}

void Widget::myhandle()
{
    this->setEnabled(false);
    qDebug() << "当前按钮的状态: " <<  this->isEnabled();
}

Widget::~Widget()
{
    delete ui;
}

