#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pushButton_2->setCursor(QCursor(Qt::DragMoveCursor));

    // 创建一个位图对象，加载自定义光标图片
    QPixmap pixmap(":/s.jpg");
    // 将图片缩放为64 * 64尺寸
    pixmap = pixmap.scaled(64, 64);
    // 创建QCursor对象，并指定”热点“为(2，2)坐标位置
    // 所谓”热点“就是鼠标点击时生效的位置
    QCursor cursor(pixmap, 2, 2);
    this->setCursor(cursor);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    float ans = this->windowOpacity();
    if(ans >= 1.0)
    {
        return ;
    }
    qDebug() << ans;
    ans += 0.1;
    if(ans >= 1.0) ans = 1.0;
    this->setWindowOpacity(ans);
}

void Widget::on_pushButton_2_clicked()
{
    float ans = this->windowOpacity();
    if(ans <= 0)
    {
        return ;
    }
    qDebug() << ans;
    ans -= 0.1;
    if(ans <= 0) ans = 0;
    this->setWindowOpacity(ans);
}
