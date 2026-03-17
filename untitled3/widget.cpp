#include "widget.h"
#include "ui_widget.h"

#include <QLineEdit>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QLineEdit* edit = new QLineEdit(this);
    edit->setText("hello world");

    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::handleClick);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::handleClick()
{
    if(ui->pushButton->text() == QString("hello world"))
    {
        ui->pushButton->setText("hello qt");
    }
    else
    {
        ui->pushButton->setText("hello world");
    }
}

