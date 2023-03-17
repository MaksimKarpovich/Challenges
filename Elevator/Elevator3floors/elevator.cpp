#include "elevator.h"

#include "QDebug"

#define MOVE_DURATION 5000
#define FLOOR_HIGH 100
#define FLOORS_NUM 3
#define LOWEST_POINT 380
#define HIGHEST_POINT (LOWEST_POINT - FLOORS_NUM * FLOOR_HIGH + FLOOR_HIGH)

Elevator::Elevator(QPushButton *Elevator, QPushButton *LeftDoor, QPushButton *RightDoor)
{
    elevator = Elevator;
    leftDoor = LeftDoor;
    rightDoor = RightDoor;
}

Elevator::~Elevator()
{

}

void Elevator::moveUp()
{
    int xElevator, yElevator, wElevator, hElevator;
    elevator->geometry().getRect(&xElevator, &yElevator, &wElevator, &hElevator);
    if(yElevator > HIGHEST_POINT)
    {
        QPropertyAnimation *animationElevator = new QPropertyAnimation(elevator, "geometry");
        animationElevator->setDuration(MOVE_DURATION);
        animationElevator->setStartValue(elevator->geometry());
        animationElevator->setEndValue(QRect(xElevator, yElevator - FLOOR_HIGH, wElevator, hElevator));

        int xLeftDoor, yLeftDoor, wLeftDoor, hLeftDoor;
        leftDoor->geometry().getRect(&xLeftDoor, &yLeftDoor, &wLeftDoor, &hLeftDoor);
        QPropertyAnimation *animationLeftDoor = new QPropertyAnimation(leftDoor, "geometry");
        animationLeftDoor->setDuration(MOVE_DURATION);
        animationLeftDoor->setStartValue(leftDoor->geometry());
        animationLeftDoor->setEndValue(QRect(xLeftDoor, yLeftDoor - FLOOR_HIGH, wLeftDoor, hLeftDoor));

        int xRightDoor, yRightDoor, wRightDoor, hRightDoor;
        rightDoor->geometry().getRect(&xRightDoor, &yRightDoor, &wRightDoor, &hRightDoor);
        QPropertyAnimation *animationRightDoor = new QPropertyAnimation(rightDoor, "geometry");
        animationRightDoor->setDuration(MOVE_DURATION);
        animationRightDoor->setStartValue(rightDoor->geometry());
        animationRightDoor->setEndValue(QRect(xRightDoor, yRightDoor - FLOOR_HIGH, wRightDoor, hRightDoor));

        animationElevator->start();
        animationLeftDoor->start();
        animationRightDoor->start();
        while (animationLeftDoor->state() == QAbstractAnimation::Running)
            QCoreApplication::processEvents();;
        while (animationRightDoor->state() == QAbstractAnimation::Running)
            QCoreApplication::processEvents();;
        while (animationElevator->state() == QAbstractAnimation::Running)
            QCoreApplication::processEvents();;
    }
}

void Elevator::moveDown()
{
    int xElevator, yElevator, wElevator, hElevator;
    elevator->geometry().getRect(&xElevator, &yElevator, &wElevator, &hElevator);
    if(yElevator < LOWEST_POINT)
    {
        qDebug() << yElevator << "<" << LOWEST_POINT;
        QPropertyAnimation *animationElevator = new QPropertyAnimation(elevator, "geometry");
        animationElevator->setDuration(MOVE_DURATION);
        animationElevator->setStartValue(elevator->geometry());
        animationElevator->setEndValue(QRect(xElevator, yElevator + FLOOR_HIGH, wElevator, hElevator));

        int xLeftDoor, yLeftDoor, wLeftDoor, hLeftDoor;
        leftDoor->geometry().getRect(&xLeftDoor, &yLeftDoor, &wLeftDoor, &hLeftDoor);
        QPropertyAnimation *animationLeftDoor = new QPropertyAnimation(leftDoor, "geometry");
        animationLeftDoor->setDuration(MOVE_DURATION);
        animationLeftDoor->setStartValue(leftDoor->geometry());
        animationLeftDoor->setEndValue(QRect(xLeftDoor, yLeftDoor + FLOOR_HIGH, wLeftDoor, hLeftDoor));

        int xRightDoor, yRightDoor, wRightDoor, hRightDoor;
        rightDoor->geometry().getRect(&xRightDoor, &yRightDoor, &wRightDoor, &hRightDoor);
        QPropertyAnimation *animationRightDoor = new QPropertyAnimation(rightDoor, "geometry");
        animationRightDoor->setDuration(MOVE_DURATION);
        animationRightDoor->setStartValue(rightDoor->geometry());
        animationRightDoor->setEndValue(QRect(xRightDoor, yRightDoor + FLOOR_HIGH, wRightDoor, hRightDoor));

        animationElevator->start();
        animationLeftDoor->start();
        animationRightDoor->start();
        while (animationLeftDoor->state() == QAbstractAnimation::Running)
            QCoreApplication::processEvents();;
        while (animationRightDoor->state() == QAbstractAnimation::Running)
            QCoreApplication::processEvents();;
        while (animationElevator->state() == QAbstractAnimation::Running)
            QCoreApplication::processEvents();;
    }
}

void Elevator::openDoor()
{
    int xLeftDoor, yLeftDoor, wLeftDoor, hLeftDoor;
    leftDoor->geometry().getRect(&xLeftDoor, &yLeftDoor, &wLeftDoor, &hLeftDoor);
    int xRightDoor, yRightDoor, wRightDoor, hRightDoor;
    rightDoor->geometry().getRect(&xRightDoor, &yRightDoor, &wRightDoor, &hRightDoor);

    if((xRightDoor - xLeftDoor) < (wLeftDoor + wRightDoor))
    {
        QPropertyAnimation *animationLeftDoor = new QPropertyAnimation(leftDoor, "geometry");
        animationLeftDoor->setDuration(MOVE_DURATION);
        animationLeftDoor->setStartValue(leftDoor->geometry());
        animationLeftDoor->setEndValue(QRect(xLeftDoor - wLeftDoor + 1, yLeftDoor, wLeftDoor, hLeftDoor));

        QPropertyAnimation *animationRightDoor = new QPropertyAnimation(rightDoor, "geometry");
        animationRightDoor->setDuration(MOVE_DURATION);
        animationRightDoor->setStartValue(rightDoor->geometry());
        animationRightDoor->setEndValue(QRect(xRightDoor + wRightDoor - 1, yRightDoor, wRightDoor, hRightDoor));

        animationLeftDoor->start();
        animationRightDoor->start();
        while (animationLeftDoor->state() == QAbstractAnimation::Running)
            QCoreApplication::processEvents();;
        while (animationRightDoor->state() == QAbstractAnimation::Running)
            QCoreApplication::processEvents();;
    }
}

void Elevator::closeDoor()
{
    int xLeftDoor, yLeftDoor, wLeftDoor, hLeftDoor;
    leftDoor->geometry().getRect(&xLeftDoor, &yLeftDoor, &wLeftDoor, &hLeftDoor);
    int xRightDoor, yRightDoor, wRightDoor, hRightDoor;
    rightDoor->geometry().getRect(&xRightDoor, &yRightDoor, &wRightDoor, &hRightDoor);

    if((xRightDoor - xLeftDoor) > (wLeftDoor + wRightDoor))
    {
        QPropertyAnimation *animationLeftDoor = new QPropertyAnimation(leftDoor, "geometry");
        animationLeftDoor->setDuration(MOVE_DURATION);
        animationLeftDoor->setStartValue(leftDoor->geometry());
        animationLeftDoor->setEndValue(QRect(xLeftDoor + wLeftDoor - 1, yLeftDoor, wLeftDoor, hLeftDoor));

        QPropertyAnimation *animationRightDoor = new QPropertyAnimation(rightDoor, "geometry");
        animationRightDoor->setDuration(MOVE_DURATION);
        animationRightDoor->setStartValue(rightDoor->geometry());
        animationRightDoor->setEndValue(QRect(xRightDoor - wRightDoor + 1, yRightDoor, wRightDoor, hRightDoor));

        animationLeftDoor->start();
        animationRightDoor->start();
        while (animationLeftDoor->state() == QAbstractAnimation::Running)
            QCoreApplication::processEvents();;
        while (animationRightDoor->state() == QAbstractAnimation::Running)
            QCoreApplication::processEvents();;
    }
}

uint8_t Elevator::getCurrentFloor()
{
    int xElevator, yElevator, wElevator, hElevator;
    elevator->geometry().getRect(&xElevator, &yElevator, &wElevator, &hElevator);
    return (LOWEST_POINT - yElevator + FLOOR_HIGH) / FLOOR_HIGH;
}
