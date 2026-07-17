#include "music.h"

Music::Music()
    : isLike(false)
    , isRecent(false)
{

}

Music::Music(QUrl url)
    : isLike(false)
    , isRecent(false)
    , musicUrl(url)
{
    // 读取url对应的歌曲文件的信息，解析出元数据
    // 歌曲名称、歌曲作者、歌曲专辑、歌曲持续时长
    musicId = QUuid::createUuid().toString();
    parseMediaMetaMusic();
}

void Music::setMusicId(const QString &musicId)
{
    this->musicId = musicId;
}

void Music::setMusicName(const QString &musicName)
{
    this->musicName = musicName;
}

void Music::setMusicSinger(const QString &musicSinger)
{
    this->musicSinger = musicSinger;
}

void Music::setMusicAlbum(const QString &musicAlbumn)
{
    this->musicAlbumn = musicAlbumn;
}

void Music::setMusicDuration(qint64 duration)
{
    this->duration = duration;
}

void Music::setIsLike(bool isLike)
{
    this->isLike = isLike;
}

void Music::setIsRecent(bool isRecent)
{
    this->isRecent = isRecent;
}

void Music::setMusicUrl(QUrl musicUrl)
{
    this->musicUrl = musicUrl;
}

QString Music::getMusicName()const
{
    return musicName;
}

QString Music::getMusicSinger()const
{
    return musicSinger;
}

QString Music::getMusicAlbum()const
{
    return musicAlbumn;
}

qint64 Music::getMusicDuration()const
{
    return duration;
}

bool Music::getIsLike()const
{
    return isLike;
}

bool Music::getIsRecent()const
{
    return isRecent;
}

QUrl Music::getMusicUrl()const
{
    return musicUrl;
}

QString Music::getMusicId() const
{
    return musicId;
}

QString Music::getLrcFilePath() const
{
    QString LrcPath = musicUrl.toLocalFile();
    QString lrcPath = musicUrl.toLocalFile();
    lrcPath.replace(".mp3", ".lrc");
    lrcPath.replace(".flac", ".lrc");
    lrcPath.replace(".mpga", ".lrc");

    return lrcPath;
}

// 根据url，解析出元数据
void Music::parseMediaMetaMusic()
{
    // 1. 创建媒体播放对象
    QMediaPlayer player;

    // 2.设置媒体元，setMedia方法解析元数据
    player.setMedia(musicUrl);

    // 3.设置阻塞循环
    while(!player.isMetaDataAvailable())
    {
        QCoreApplication::processEvents();
    }

    // 解析获取完成，进行获取有效数据
    if(player.isMetaDataAvailable())
    {
        musicName = player.metaData("Title").toString();
        musicSinger = player.metaData("Author").toString();
        musicAlbumn = player.metaData("AlbumTitle").toString();
        duration = player.metaData("Duration").toLongLong();

        // 处理各个信息为空的问题
        QString fileName = musicUrl.fileName();
        // 歌名 - 歌手.mp3
        // 找到 - 位置
        int index = fileName.indexOf('-');

        // musicName处理
        if(musicName.isEmpty())
        {
            if(index == -1)
            {
                musicName = fileName.mid(0, fileName.indexOf('.')).trimmed(); // 去空白
            }
            else
            {
                musicName = fileName.mid(0, index).trimmed();
            }
        }

        // musicSinger处理
        if(musicSinger.isEmpty())
        {
            if(index == -1)
            {
                musicSinger = "♪ 未知 ♪";
            }
            else
            {
                musicSinger = fileName.mid(index + 1, fileName.indexOf('.') - index - 1).trimmed();
            }
        }

        // musicAlbumn处理
        if(musicSinger.isEmpty())
        {
            musicAlbumn = "♪ 未知 ♪";
        }
        qDebug()<<fileName<<musicSinger<<":"<<musicAlbumn<<":"<<duration;
    }
}

