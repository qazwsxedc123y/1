#include "commonpage.h"
#include "ui_commonpage.h"

commonpage::commonpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::commonpage)
{
    ui->setupUi(this);

    // 美观 - 不要系统给的水平滚动条
    ui->MusicList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

commonpage::~commonpage()
{
    delete ui;
}

void commonpage::setMusciListType(PageType pageType)
{
    this->pageType = pageType;
}

void commonpage::addMusicToMusicPage(MusicList &musiclist)
{
    // 先清空原本
    musicListOfPage.clear();
    for(auto e : musiclist)
    {
        switch (pageType)
        {
        case(LOCAL_PAGE):
            musicListOfPage.push_back(e.getMusicId());
            break;
        case(LIKE_PAGE):
            if(e.getIsLike())
            {
                musicListOfPage.push_back(e.getMusicId());
            }
            break;
        case(RECENT_PAGE):
            {
                if(e.getIsRecent())
                {
                    musicListOfPage.push_back(e.getMusicId());
                }
                break;
            }
        default:
            qDebug()<<"未知错误：当前不支持此功能";
        }
    }
}

void commonpage::setCommonPageUI(const QString &title, const QString &image)
{
    // 设置标题
    ui->pageTittle->setText(title);

    // 设置图片
    ui->musicImageLable->setPixmap(QPixmap(image));
    // 启用内容缩放功能
    ui->musicImageLable->setScaledContents(true);

//    // debug
//    ListItemBox* listItemBox = new ListItemBox(this);
//    QListWidgetItem* listWidgetItem = new QListWidgetItem(ui->MusicList);
//    listWidgetItem->setSizeHint(QSize(ui->MusicList->width(), 45));
    //    ui->MusicList->setItemWidget(listWidgetItem, listItemBox);
}

// 刷新信息，添加到对应页面
void commonpage::reFresh(MusicList &musicList)
{
    // 因重复问题，需要先清除
    ui->MusicList->clear();

     // 添加新的歌曲到对应的页信息
    addMusicToMusicPage(musicList);

    for(auto musicid : musicListOfPage)
    {
        auto it = musicList.findMusicById(musicid);
        if(it == musicList.end()) continue;

        ListItemBox* listItemBox = new ListItemBox(this);
        listItemBox->setMusicName(it->getMusicName());
        listItemBox->setMusicSinger(it->getMusicSinger());
        listItemBox->setMusicAlbum(it->getMusicAlbum());
        listItemBox->setLikeMusic(it->getIsLike());

        QListWidgetItem* listWidgetItem = new QListWidgetItem(ui->MusicList);
        listWidgetItem->setSizeHint(QSize(ui->MusicList->width(), 45));
        ui->MusicList->setItemWidget(listWidgetItem, listItemBox);

        // 接受listtiembox发送的setIsLike信号
        // 发送信号给qqmusic，让其修改musiclist
        connect(listItemBox, &ListItemBox::setIsLike, this, [=](bool isLike){ emit updateLikeMusic(isLike, it->getMusicId()); });
    }
    // 触发窗口重绘paintEvent
    repaint();     // 立马响应paintEvent事件
}





