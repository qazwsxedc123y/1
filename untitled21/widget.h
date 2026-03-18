#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_pushButton_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_7_clicked();

    void on_radioButton_8_clicked();

private:
    Ui::Widget *ui;
    QString s1, s2, s3;
};
#endif // WIDGET_H
