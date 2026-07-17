#include "listitembox.h"
#include "ui_listitembox.h"

void ListItemBox::enterEvent(QEvent *event)
{
    (void)event;
    setStyleSheet("background-color:#EFEFEF");
}

void ListItemBox::leaveEvent(QEvent *event)
{
    (void)event;
    setStyleSheet("");
}

ListItemBox::ListItemBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListItemBox),
    isLike(false)
{
    ui->setupUi(this);
}

ListItemBox::~ListItemBox()
{
    delete ui;
}

void ListItemBox::setMusicName(const QString &musicName)
{
    ui->MusicNameLable->setText(musicName);
}

void ListItemBox::setMusicSinger(const QString &musicSinger)
{
    ui->MusicSingerLable->setText(musicSinger);
}

void ListItemBox::setMusicAlbum(const QString &musicAlbum)
{
    ui->MusicAlbumLable->setText(musicAlbum);
}

void ListItemBox::setLikeMusic(bool isLike)
{
    this->isLike = isLike;
    if(isLike)
    {
        ui->LikeBtn->setIcon(QIcon(":/images/like_2.png"));
    }
    else
    {
        ui->LikeBtn->setIcon(QIcon(":/images/like_3.png"));
    }
}

void ListItemBox::on_LikeBtn_clicked()
{
    qDebug() << "点击喜欢";
    isLike = !isLike;
    setLikeMusic(isLike);
    emit setIsLike(isLike);
}
