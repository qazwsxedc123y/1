#include "myqlabel.h"
#include <QLabel>
#include <QDebug>
myqlabel::myqlabel(QWidget* parent) :QLabel(parent)
{

}

myqlabel::~myqlabel()
{
    qDebug() << "正常输出";
}
