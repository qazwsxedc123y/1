#include "widget.h"
#include "ui_widget.h"
#include <chrono>
#include <thread>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建 QTimer 实例
    timer = new QTimer(this);
    // 连接信号槽. QTimer 会每隔⼀定的时间触发⼀个 timeout 信号. 现在把 timeout 信号和 updateTime 连接起来.
    // 此时意味着每次触发 timeout 信号都会伴随 updateTime 函数的执⾏.
    connect(timer, &QTimer::timeout, this, &Widget::updateTime);
    // 启动 QTimer, 并且规定每隔 1000ms 触发⼀次 timeout 信号.
    timer->start(1000);

    int value = ui->lcdNumber->intValue();
    while(true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if(value <= 0)
        {
            break;
        }
        ui->lcdNumber->display(value - 1);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateTime()
{
    int value = ui->lcdNumber->intValue();
    if(value <= 0)
    {
        timer->stop();
        return ;
    }
    ui->lcdNumber->display(value - 1);
}

