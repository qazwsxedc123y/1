#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QDebug>
#include "myqlabel.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    myqlabel* label = new myqlabel(this);
    label->setText("hello world");
}

Widget::~Widget()
{
    delete ui;
}

