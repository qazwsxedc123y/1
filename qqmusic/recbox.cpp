#include "recbox.h"
#include "ui_recbox.h"

RecBox::RecBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecBox),
    row(1),
    col(4)
{
    ui->setupUi(this);
    // RecBoxItem* item = new RecBoxItem();
    // ui->RecListUpHLayout->addWidget(item);
}

RecBox::~RecBox()
{
    delete ui;
}

void RecBox::initRecBoxUi(QJsonArray data, int row)
{
    if(row == 2)
    {
        this->row = row;
        this->col = 8;
    }
    else
    {
        ui->RecListDown->hide();
    }

    // 保存信息
    imageList = data;
    // 默认为第0组照片
    currentIndex = 0;
    // 计算一共几组照片
    count = ceil(imageList.size()/col);
    // 往RecBox中添加图⽚
    createRecItem();
}

void RecBox::createRecItem()
{
    // 溢出掉之前旧元素s
    QList<RecBoxItem*> recUpList = ui->RecListUp->findChildren<RecBoxItem*>();
    for(auto e : recUpList)
    {
        ui->RecListUpHLayout->removeWidget(e);
        delete(e);
    }
    QList<RecBoxItem*> recDownList = ui->RecListDown->findChildren<RecBoxItem*>();
    for(auto e : recDownList)
    {
        ui->RecListDownHLayout->removeWidget(e);
        delete(e);
    }

    int index = 0;
    // 创建RecBoxItem对象，往RecBox中添加
    for(int i = currentIndex*col; i < col + currentIndex*col; ++i)
    {
        RecBoxItem* item = new RecBoxItem();
        QJsonObject obj = imageList[i].toObject();
        item->setText(obj.value("text").toString());
        item->setImage(obj.value("path").toString());

        // 将RecBoxItem对象添加到RecBox中
        // 0 1 2 3->up
        // 4 5 6 7->down
        if(row == 2 && index >= col / 2)
        {
            ui->RecListDownHLayout->addWidget(item);
        }
        else
        {
            ui->RecListUpHLayout->addWidget(item);
        }
        ++index;
    }
}

void RecBox::on_PageUp_clicked()
{
    // 向上翻页 循环式
    currentIndex--;
    if(currentIndex < 0)
    {
        currentIndex = count - 1;
    }
    // 往RecBox中添加图⽚
    createRecItem();
}

void RecBox::on_PageDown_clicked()
{
    // 向下翻页 循环式
    currentIndex++;
    if(currentIndex >= count)
    {
        currentIndex = 0;
    }
    // 往RecBox中添加图⽚
    createRecItem();
}
