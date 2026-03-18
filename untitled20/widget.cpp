#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QIcon icon(":/1.png");
    QSize size_ = ui->pushButton->size();
    ui->pushButton->setIcon(icon);
    ui->pushButton->setIconSize(QSize(size_.width(),size_.height()));

    ui->pushButton_up->setIcon(QIcon(":/up.png"));
    ui->pushButton_left->setIcon(QIcon(":/left.png"));
    ui->pushButton_right->setIcon(QIcon(":/right.png"));
    ui->pushButton_down->setIcon(QIcon(":/down.png"));

//    ui->pushButton_up->setShortcut(QKeySequence("w"));
//    ui->pushButton_left->setShortcut(QKeySequence("a"));
//    ui->pushButton_right->setShortcut(QKeySequence("d"));
//    ui->pushButton_down->setShortcut(QKeySequence("s"));


     ui->pushButton_up->setShortcut(QKeySequence(Qt::Key_W));
     ui->pushButton_left->setShortcut(QKeySequence(Qt::Key_A));
     ui->pushButton_right->setShortcut(QKeySequence(Qt::Key_D));
     ui->pushButton_down->setShortcut(QKeySequence(Qt::Key_S));

     ui->pushButton_up->setAutoRepeat(true);
     ui->pushButton_left->setAutoRepeat(true);
     ui->pushButton_right->setAutoRepeat(true);
     ui->pushButton_down->setAutoRepeat(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_up_clicked()
{
    // 先获取原本的位置，然后在修改
    const QRect rect = ui->pushButton->geometry();
    ui->pushButton->setGeometry(rect.x(), rect.y() - 5, rect.width(), rect.height());
}

void Widget::on_pushButton_left_clicked()
{
    const QRect rect = ui->pushButton->geometry();
    ui->pushButton->setGeometry(rect.x() - 5, rect.y(), rect.width(), rect.height());
}

void Widget::on_pushButton_right_clicked()
{
    const QRect rect = ui->pushButton->geometry();
    ui->pushButton->setGeometry(rect.x() + 5, rect.y(), rect.width(), rect.height());
}

void Widget::on_pushButton_down_clicked()
{
    const QRect rect = ui->pushButton->geometry();
    ui->pushButton->setGeometry(rect.x(), rect.y() + 5, rect.width(), rect.height());
}
