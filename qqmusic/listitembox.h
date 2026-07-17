#ifndef LISTITEMBOX_H
#define LISTITEMBOX_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class ListItemBox;
}

class ListItemBox : public QWidget
{
    Q_OBJECT
protected:
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
public:
    explicit ListItemBox(QWidget *parent = nullptr);
    ~ListItemBox();

    void setMusicName(const QString& musicName);
    void setMusicSinger(const QString& musicSinger);
    void setMusicAlbum(const QString& musicAlbum);
    void setLikeMusic(bool isLike);
private slots:
    void on_LikeBtn_clicked();
signals:
    void setIsLike(bool); // 点击按钮，发送该信号，该信号响应函数：setLikeMusic
private:
    Ui::ListItemBox *ui;
    bool isLike;
};

#endif // LISTITEMBOX_H
