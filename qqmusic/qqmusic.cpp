#include "qqmusic.h"
#include "ui_qqmusic.h"

void QQMusic::mousePressEvent(QMouseEvent *event)
{
    // event->globalPos()：⿏标按下事件发⽣时，光标相对于屏幕左上⻆位置
    // frameGeometry().topLeft(): ⿏标按下事件发⽣时，窗⼝左上⻆位置
    // geometry(): 不包括边框及顶部标题区的范围
    // frameGeometry(): 包括边框及顶部标题区的范围
    if(event->button() == Qt::LeftButton)
    {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        return ;
    }
    // 剩余情况
    QWidget::mousePressEvent(event);
}

void QQMusic::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() == Qt::LeftButton)
    {
        // 移动左上角坐标即可
        move(event->globalPos() - dragPosition);
        return ;
    }
    // 剩余情况
    QWidget::mouseMoveEvent(event);
}

QQMusic::QQMusic(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QQMusic)
{
    ui->setupUi(this);
    initUI();
    connectSignalAndSlot();
}

QQMusic::~QQMusic()
{
    delete ui;
}

void QQMusic::initUI()
{
    // 设置无边框窗口，窗口将来为无标题栏
    setWindowFlag(Qt::WindowType::FramelessWindowHint);
    // 窗口背景设置透明
    this->setAttribute(Qt::WA_TranslucentBackground);

    // 窗口设置阴影效果
    QGraphicsDropShadowEffect* shadoweffect = new QGraphicsDropShadowEffect(this);
    shadoweffect->setOffset(0,0); // 设置阴影偏移
    shadoweffect->setColor("#000000"); // 设置阴影颜⾊：⿊⾊
    shadoweffect->setBlurRadius(10); // 设置阴影的模糊半径
    this->setGraphicsEffect(shadoweffect);

    //设置BodyLeft中6个BtForm信息
    ui->Rec->seticon(":/images/rec.png", "推荐", 0);
    ui->Radio->seticon(":/images/radio.png", "电台", 1);
    ui->MusicHall->seticon(":/images/music.png", "⾳乐馆", 2);
    ui->Like->seticon(":/images/like.png", "我喜欢", 3);
    ui->Local->seticon(":/images/local.png", "本地下载", 4);
    ui->Recent->seticon(":/images/recent.png", "最近播放", 5);

    // 推荐设置为初始页，动画默认显示
    ui->Rec->showAnimal();
    ui->stackedWidget->setCurrentIndex(0);
    ui->Rec->setStyleSheet("#BtStyle{ background:rgb(0, 255, 127);} *{color:#F6F6F6;}");

    // 初始化推荐界面
    srand(time(NULL));
    ui->RecMusicBox->initRecBoxUi(randomPiction(), 1);
    ui->SupplyMusicBox->initRecBoxUi(randomPiction(), 2);

    // 设置三个页面基本信息 commonpage
    ui->LikePage->setMusciListType(PageType::LIKE_PAGE);
    ui->LikePage->setCommonPageUI("我喜欢", ":/images/ilikebg.png");
    ui->LocalPage->setMusciListType(PageType::LOCAL_PAGE);
    ui->LocalPage->setCommonPageUI("本地音乐", ":/images/localbg.png");
    ui->RecentPage->setMusciListType(PageType::RECENT_PAGE);
    ui->RecentPage->setCommonPageUI("最近播放", ":/images/recentbg.png");

    // 创建⾳量调节窗⼝对象并挂到对象树
    volumeTool = new VolumeTool(this);
}

void QQMusic::onBtFormClick(int id)
{
    // 切换为索引为id
    // 获取当前所有的BtForm
    // 进行删选出id
    QList<BtForm*> buttonList = this->findChildren<BtForm*>();
    for(BtForm* btitem : buttonList)
    {
        if(id != btitem->getId())
        {
            // qDebug() << btitem->getId();
            btitem->clearBackground(); // 发现实际情况下默认的rec无法清楚
        }
    }
    // 修改页面为id
    ui->stackedWidget->setCurrentIndex(id);
    AnimationIdShow(id);
    // qDebug() << "切换页面" << id;
}

void QQMusic::connectSignalAndSlot()
{
    // 设置关联BtForm的点击
    connect(ui->Rec, &BtForm::btclick, this, &QQMusic::onBtFormClick);
    connect(ui->Radio, &BtForm::btclick, this, &QQMusic::onBtFormClick);
    connect(ui->MusicHall, &BtForm::btclick, this, &QQMusic::onBtFormClick);
    connect(ui->Like, &BtForm::btclick, this, &QQMusic::onBtFormClick);
    connect(ui->Local, &BtForm::btclick, this, &QQMusic::onBtFormClick);
    connect(ui->Recent, &BtForm::btclick, this, &QQMusic::onBtFormClick);

    // 关联commonpage发送来的updateLikeMusic信号
    connect(ui->LikePage, &commonpage::updateLikeMusic, this, &QQMusic::UpdateMusicListLike);
    connect(ui->LocalPage, &commonpage::updateLikeMusic, this, &QQMusic::UpdateMusicListLike);
    connect(ui->RecentPage, &commonpage::updateLikeMusic, this, &QQMusic::UpdateMusicListLike);
}

void QQMusic::AnimationIdShow(int id)
{
    switch(id)
    {
        case 0: ui->Rec->showAnimal(); break;
        case 1: ui->Radio->showAnimal(); break;
        case 2: ui->MusicHall->showAnimal(); break;
        case 3: ui->Like->showAnimal(); break;
        case 4: ui->Local->showAnimal(); break;
        default: ui->Recent->showAnimal(); break;
    }
}

QJsonArray QQMusic::randomPiction()
{
    // 需要设置推荐⽂本 + 推荐图⽚路径
    //       setText     setImage
    QVector<QString> vecImageName;
    vecImageName<<"001.png"<<"003.png"<<"004.png"<<"005.png"<<"006.png"<<"007.png"
                <<"008.png"<<"009.png"<<"010.png"<<"011.png"<<"012.png"<<"013.png"
                <<"014.png"<<"015.png"<<"016.png"<<"017.png"<<"018.png"<<"019.png"
                <<"020.png"<<"021.png"<<"022.png"<<"023.png"<<"024.png"<<"025.png"
                <<"026.png"<<"027.png"<<"028.png"<<"029.png"<<"030.png"<<"031.png"
                <<"032.png"<<"033.png"<<"034.png"<<"035.png"<<"036.png"<<"037.png"
                <<"038.png"<<"039.png"<<"040.png";
    // 乱序获取
    std::random_shuffle(vecImageName.begin(), vecImageName.end());

    // 设定名称
    QJsonArray objArray;
    for(int i = 0; i < vecImageName.size(); ++i)
    {
        QJsonObject obj;
        obj.insert("path", ":/images/rec/"+vecImageName[i]);

        QString strText = QString("推荐-%1").arg(i, 3, 10, QChar('0'));
        obj.insert("text", strText);

        objArray.append(obj);
    }

    return objArray;
}

void QQMusic::UpdateMusicListLike(bool isLike, QString musicId)
{
    // 找到，修改islike属性
    auto it = musicList.findMusicById(musicId);
    if(it != musicList.end()) it->setIsLike(isLike);

    // 通知三个页面修改
    ui->LikePage->reFresh(musicList);
    ui->LocalPage->reFresh(musicList);
    ui->RecentPage->reFresh(musicList);
}

void QQMusic::on_Volume_clicked()
{
    // 先要调整窗⼝的显⽰位置，否则该窗⼝在主窗⼝的左上⻆
    // 1.获取该按钮左上⻆的图标
    QPoint point = ui->Volume->mapToGlobal(QPoint(0, 0));

    // 2. 计算volume窗⼝的左上⻆位置
    QPoint volumeLeftTop = point - QPoint(volumeTool->width()/2, volumeTool->height());

    // 微调窗⼝位置
    volumeLeftTop.setY(volumeLeftTop.y()-10);
    volumeLeftTop.setX(volumeLeftTop.x()+18);

    // 3. 移动窗⼝位置
    volumeTool->move(volumeLeftTop);

    // 4. 将窗⼝显⽰出来
    volumeTool->show();
}

void QQMusic::on_AddLocal_clicked()
{
    // 添加歌曲
    // 1. 创建⼀个⽂件对话框
    QFileDialog fileDialog(this);
    fileDialog.setWindowTitle("添加本地⾳乐");

    // 2. 创建⼀个打开格式的⽂件对话框
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);

    // 3.设置对话框模式
    // 只能选择⽂件，并且⼀次性可以选择多个存在的⽂件
    fileDialog.setFileMode(QFileDialog::ExistingFiles);

    // 4. 设置对话框的MIME过滤器
    QStringList mimeList;
    mimeList<<"application/octet-stream";
    fileDialog.setMimeTypeFilters(mimeList);
    // 5. 设置对话框默认的打开路径,设置⽬录为当前⼯程所在⽬录
    QDir dir(QDir::currentPath());

    // bug
    dir.cdUp();
    dir.cdUp();
    QString musicPath = dir.path()+"/Project/qqmusic/musics";

    fileDialog.setDirectory(musicPath);
    // 6. 显⽰对话框，并接收返回值
    // 模态对话框, exec内部是死循环处理
    if(fileDialog.exec() == QFileDialog::Accepted)
    {
        // 切换到本地⾳乐界⾯，因为加载完的⾳乐需要在本地⾳乐界⾯显⽰
        ui->stackedWidget->setCurrentIndex(4);
        // 获取对话框的返回值
        QList<QUrl> urls = fileDialog.selectedUrls();
        // 拿到后，进行管理
        musicList.addMusicByUrl(urls);
        ui->LocalPage->reFresh(musicList);
    }
}
