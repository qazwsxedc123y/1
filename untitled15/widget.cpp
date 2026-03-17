#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QDir>
#include <QIcon>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    this->setWindowTitle("这是一个被修改的标题");
//    qDebug() << this->windowTitle();

//    QIcon icon("E:/code/1.png");

//    // 设置图标
//    this->setWindowIcon(icon);

//    qDebug() << this->windowIcon();
//    QString currentpath = QDir::currentPath();

//    ui->label->setText(currentpath);

    QIcon icon(":/1.png");

    this->setWindowIcon(icon);

}

Widget::~Widget()
{
    delete ui;
}

