#include "elevator.h"

#include "QDebug"

Elevator::Elevator(QPushButton *Elevator)
{
    QPropertyAnimation *animation = new QPropertyAnimation(Elevator, "geometry");
    animation->setDuration(5000);
    animation->setStartValue(Elevator->geometry());
    qDebug() << Elevator->geometry();
    int x, y, w, h;
    Elevator->geometry().getRect(&x, &y, &w, &h);
    qDebug() << x << " " << y << " " << w << " " << h;
    qDebug() << Elevator->geometry();
    animation->setEndValue(QRect(x, y - 100, w, h));

    animation->start();
    qDebug() << "Hehee";
}

Elevator::~Elevator()
{

}

