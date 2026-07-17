#ifndef MUSIC_H
#define MUSIC_H

#include<QUrl>
#include <QUuid>
#include <QMediaPlayer>
#include <QCoreApplication>

// 用于管理歌曲
// 保存歌曲名称、歌⼿、⾳乐专辑、歌曲时⻓等
class Music
{
public:
    Music();
    Music(QUrl url);
    void setMusicId(const QString& musicId);
    void setMusicName(const QString& musicName);
    void setMusicSinger(const QString& musicSinger);
    void setMusicAlbum(const QString& musicAlbumn);
    void setMusicDuration(qint64 duration);
    void setIsLike(bool isLike);
    void setIsRecent(bool isRecent);
    void setMusicUrl(QUrl musicUrl);

    QString getMusicName()const;
    QString getMusicSinger()const;
    QString getMusicAlbum()const;
    qint64 getMusicDuration()const;
    bool getIsLike()const;
    bool getIsRecent()const;
    QUrl getMusicUrl()const;
    QString getMusicId()const;

    QString getLrcFilePath()const;

private:
    void parseMediaMetaMusic();

private:
    // 保证歌曲的唯一性，给音乐添加id
    QString musicId;
    // 音乐名称
    QString musicName;
    // 音乐作者
    QString musicSinger;
    // 音乐专辑
    QString musicAlbumn;
    // 持续时长--long long   单位毫秒
    qint64 duration;
    // 是否喜欢
    bool isLike;
    // 是否为历史播放
    bool isRecent;
    // 音乐QUrl
    QUrl musicUrl;
};

#endif // MUSIC_H
