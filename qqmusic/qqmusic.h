#ifndef QQMUSIC_H
#define QQMUSIC_H
#include "btform.h"
#include "commonpage.h"
#include "volumetool.h"
#include "musiclist.h"
#include <QWidget>
#include <QMouseEvent>
#include <QPoint>
#include <QGraphicsDropShadowEffect>
#include <QString>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QDir>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class QQMusic; }
QT_END_NAMESPACE

class QQMusic : public QWidget
{
    Q_OBJECT
protected:
    // 重写基类QWight类的鼠标单击和鼠标移动事件
    void mousePressEvent(QMouseEvent *event)override;
    void mouseMoveEvent(QMouseEvent *event)override;

public:

    QQMusic(QWidget *parent = nullptr);

    ~QQMusic();

    void initUI();

    // BtForm点击函数，切换界面
    void onBtFormClick(int id);

    // 管理关联信号
    void connectSignalAndSlot();

    // 动画的切换
    void AnimationIdShow(int id);

    // Json串，用于保存信息，并传递用来解析后获取
    QJsonArray randomPiction();

    // 接受处理commonpage发送来的信号的相应函数，更新musiclist中的islike
    void UpdateMusicListLike(bool isLike, QString musicId);
private slots:
    void on_Volume_clicked();

    void on_AddLocal_clicked();

private:
    Ui::QQMusic *ui;
    QPoint dragPosition;
    // 音量调节窗口
    VolumeTool* volumeTool;

    MusicList musicList; // 存放本地音乐列表
};
#endif // QQMUSIC_H

