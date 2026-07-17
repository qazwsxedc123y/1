#ifndef MUSICLIST_H
#define MUSICLIST_H
#include <QVector>
#include <QList>
#include <QUrl>
#include <QSet>
#include <QMimeDatabase>
#include <QMimeType>
#include <iterator>

#include "music.h"

// 用于歌曲对象的存储与管理
class MusicList
{
public:
    MusicList();
    // 将页面读取到的文件，检测为音乐文件后后添加到musicList中
    void addMusicByUrl(const QList<QUrl>& urls);
    QVector<Music>::iterator begin();
    QVector<Music>::iterator end();
    QVector<Music>::iterator findMusicById(const QString& musicid);
private:
    QVector<Music> musicList; // 歌曲存储
};

#endif // MUSICLIST_H
