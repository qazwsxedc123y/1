#include "volumetool.h"
#include "ui_volumetool.h"

VolumeTool::VolumeTool(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VolumeTool)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);

    // 透明背景设置
    // 在Windows上，如果使用了 Qt::FramelessWindowHint 但没有透明背景，没有控件的区域会显示为黑色
    setAttribute(Qt::WA_TranslucentBackground);

    // 自定义阴影效果
    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setOffset(0, 0);        // 阴影偏移量（x=0, y=0）
    shadowEffect->setColor("#646464");    // 阴影颜色（灰色）
    shadowEffect->setBlurRadius(10);      // 模糊半径（10px）
    setGraphicsEffect(shadowEffect);

    // 设置静音按钮的图片
    ui->SilenceBtn->setIcon(QIcon(":/images/volumn.png"));
    // ⾳量的默认⼤⼩是20
    ui->outSlider->setGeometry(ui->outSlider->x(), 180 - 36 + 25, ui->outSlider->width(), 36);
    ui->sliderBtn->move(ui->sliderBtn->x(), ui->outSlider->y() - ui->sliderBtn->height()/2);
    ui->VolumeRatio->setText("20%");
}

VolumeTool::~VolumeTool()
{
    delete ui;
}
