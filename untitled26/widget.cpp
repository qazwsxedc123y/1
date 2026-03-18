#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Widget::updateProgressBar);
    timer->start(100);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateProgressBar()
{
    int value = ui->progressBar->value();
    if(value >= 100)
    {
        timer->stop();
        return;
    }
    ui->progressBar->setValue(value += 2);
}

