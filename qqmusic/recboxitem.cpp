#include "recboxitem.h"
#include "ui_recboxitem.h"

RecBoxItem::RecBoxItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecBoxItem)
{
    ui->setupUi(this);
    ui->MusicItemBox->installEventFilter(this);
}

RecBoxItem::~RecBoxItem()
{
    delete ui;
}

bool RecBoxItem::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->MusicItemBox)
    {
        int ImgWidget = ui->RecMusicImage->width();
        int ImgHeight = ui->RecMusicImage->height();

        // 如果鼠标进入事件
        if(event->type() == QEvent::Enter)
        {
            // qDebug() << "鼠标进入";
            QPropertyAnimation* animation = new QPropertyAnimation(ui->MusicItemBox, "geometry");
            animation->setDuration(250);
            animation->setStartValue(QRect(9,9,ImgWidget,ImgHeight));
            animation->setEndValue(QRect(9, 0, ImgWidget, ImgHeight));
            animation->start();
            // 注意：动画结束的时候会触发finished信号，拦截到该信号，销毁animation
            connect(animation, &QPropertyAnimation::finished, this, [=](){
                delete animation;
                // qDebug()<<"图片上移动画结束";
            });
            return true;// 注意：动画结束的时候会触发finished信号，拦截到该信号，销毁animation
        }
        else if(event->type() == QEvent::Leave)
        {
            // qDebug() << "鼠标离开";
            QPropertyAnimation* animation = new QPropertyAnimation(ui->MusicItemBox, "geometry");
            animation->setDuration(250);
            animation->setStartValue(QRect(9,0,ImgWidget,ImgHeight));
            animation->setEndValue(QRect(9, 9, ImgWidget, ImgHeight));
            animation->start();
            // 注意：动画结束的时候会触发finished信号，拦截到该信号，销毁animation
            connect(animation, &QPropertyAnimation::finished, this, [=](){
                delete animation;
                // qDebug()<<"图片下移动画结束";
            });
            return true;// 注意：动画结束的时候会触发finished信号，拦截到该信号，销毁animation
        }
    }
    return QObject::eventFilter(watched, event);
}

void RecBoxItem::setText(const QString &text)
{
    ui->RecBoxItemText->setText(text);
}

void RecBoxItem::setImage(const QString &imagePath)
{
    QString Style = "border-image:url("+imagePath+");";
    ui->RecMusicImage->setStyleSheet(Style);
}
