#ifndef COMMONPAGE_H
#define COMMONPAGE_H

#include <QWidget>
#include "listitembox.h"
#include "musiclist.h"
#include <QListWidgetItem>

namespace Ui {
class commonpage;
}

enum PageType
{
    LIKE_PAGE,       // 我喜欢页面
    LOCAL_PAGE,      // 本地下载页面
    RECENT_PAGE      // 最近播放界面
};

class commonpage : public QWidget
{
    Q_OBJECT

public:
    explicit commonpage(QWidget *parent = nullptr);
    ~commonpage();

    // 设置所属页
    void setMusciListType(PageType pageType);

    // 对musicList按页分配
    void addMusicToMusicPage(MusicList &musiclist);

    // 设置界面信息
    void setCommonPageUI(const QString &title, const QString &image);

    // 刷新
    void reFresh(MusicList& musicList);

signals:
    void updateLikeMusic(bool isLike, QString musicId);

private:
    Ui::commonpage *ui;

    PageType pageType;   // 该页面属于那页面
    QVector<QString> musicListOfPage; // 保存对应页面的歌曲，其保存对应id即可。有id，即可通过musiclist获取所有信息
};

#endif // COMMONPAGE_H
