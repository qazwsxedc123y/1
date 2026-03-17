#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton *button = new QPushButton("按钮", this);
    resize(800, 600);
    connect(button, &QPushButton::clicked, this, [=](){
        this->setWindowTitle("xxxxxx");
    });
}

Widget::~Widget()
{
    delete ui;
}

