#include "widget.h"
#include "ui_widget.h"

#include "QDebug"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    QPropertyAnimation *animation = new QPropertyAnimation(ui->Elevator, "geometry");
//    animation->setDuration(5000);
//    animation->setStartValue(ui->Elevator->geometry());
//    qDebug() << ui->Elevator->geometry();
//    int x, y, w, h;
//    ui->Elevator->geometry().getRect(&x, &y, &w, &h);
//    qDebug() << x << " " << y << " " << w << " " << h;
//    qDebug() << ui->Elevator->geometry();
//    animation->setEndValue(QRect(x, y - 100, w, h));

//    animation->start();
}

Widget::~Widget()
{
    delete ui;
}

