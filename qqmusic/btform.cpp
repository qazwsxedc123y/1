#include "btform.h"
#include "ui_btform.h"

void BtForm::mousePressEvent(QMouseEvent *event)
{
    // 告诉编译器不要出发警告
    (void)event;
    // 鼠标点击后，将背景变为绿色，病将文字变为白色
    ui->BtStyle->setStyleSheet("#BtStyle{ background:rgb(0, 255, 127);} *{color:#F6F6F6;}");
    emit btclick(this->id);
}

BtForm::BtForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BtForm)
{
    ui->setupUi(this);
    initBtForm();
}

BtForm::~BtForm()
{
    delete ui;
}

void BtForm::seticon(QString btIcon, QString content, int mid)
{
    ui->BtIcon->setPixmap(QPixmap(btIcon));
    ui->BtText->setText(content);
    this->id = mid;
}

int BtForm::getId()
{
    return id;
}

void BtForm::clearBackground()
{
    ui->BtStyle->setStyleSheet(
        "#BtStyle { background: #F0F0F0;} *{color:#000000;}"
        "#BtStyle:hover { background-color:rgb(0, 255, 127);}"
    );
    ui->LineBox->hide();
}

void BtForm::initBtForm()
{
    ui->LineBox->hide();
    // 动画设置
    animationLine1 = new QPropertyAnimation(ui->line1, "geometry", this);
    animationLine1->setDuration(1500);
    animationLine1->setKeyValueAt(0, QRect(4, 35, 2, 0));
    animationLine1->setKeyValueAt(0.5, QRect(4, 10, 2, 25));
    animationLine1->setKeyValueAt(1, QRect(4, 35, 2, 0));
    animationLine1->setLoopCount(-1);
    animationLine1->start();

    animationLine2 = new QPropertyAnimation(ui->line2, "geometry", this);
    animationLine2->setDuration(1600);
    animationLine2->setKeyValueAt(0, QRect(10, 35, 2, 0));
    animationLine2->setKeyValueAt(0.5, QRect(10, 10, 2, 25));
    animationLine2->setKeyValueAt(1, QRect(10, 35, 2, 0));
    animationLine2->setLoopCount(-1);
    animationLine2->start();

    animationLine3 = new QPropertyAnimation(ui->line3, "geometry", this);
    animationLine3->setDuration(1700);
    animationLine3->setKeyValueAt(0, QRect(16, 35, 2, 0));
    animationLine3->setKeyValueAt(0.5, QRect(16, 10, 2, 25));
    animationLine3->setKeyValueAt(1, QRect(16, 35, 2, 0));
    animationLine3->setLoopCount(-1);
    animationLine3->start();

    animationLine4 = new QPropertyAnimation(ui->line4, "geometry", this);
    animationLine4->setDuration(1800);
    animationLine4->setKeyValueAt(0, QRect(22, 35, 2, 0));
    animationLine4->setKeyValueAt(0.5, QRect(22, 10, 2, 25));
    animationLine4->setKeyValueAt(1, QRect(22, 35, 2, 0));
    animationLine4->setLoopCount(-1);
    animationLine4->start();
}

void BtForm::showAnimal()
{
    ui->LineBox->show();
}
