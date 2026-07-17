#include "musiclist.h"

MusicList::MusicList()
{

}

void MusicList::addMusicByUrl(const QList<QUrl> &urls)
{
    for(auto musicurl : urls)
    {
        // 检测音乐文件，挑出来
        QMimeDatabase t;
        QMimeType type = t.mimeTypeForFile(musicurl.toLocalFile());
        QString typeName = type.name();
        if(typeName == "audio/mpeg" || typeName == "audio/flac" || typeName == "audio/wav")
        {
            // 添加到musicList中
            Music music(musicurl);
            musicList.push_back(music);
        }
    }
}

QVector<Music>::iterator MusicList::begin()
{
    return musicList.begin();
}

QVector<Music>::iterator MusicList::end()
{
    return musicList.end();
}

QVector<Music>::iterator MusicList::findMusicById(const QString &musicid)
{
    for(auto e = begin(); e != end(); ++e)
    {
        if(e->getMusicId() == musicid)
        {
            return e;
        }
    }
    return end();
}
