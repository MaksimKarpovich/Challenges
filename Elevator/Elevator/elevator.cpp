#include "elevator.h"

#include "QDebug"

#define MOVE_DURATION 5000
#define FLOOR_HIGH 100

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
    QPropertyAnimation *animationElevator = new QPropertyAnimation(elevator, "geometry");
    animationElevator->setDuration(MOVE_DURATION);
    animationElevator->setStartValue(elevator->geometry());
    int xElevator, yElevator, wElevator, hElevator;
    elevator->geometry().getRect(&xElevator, &yElevator, &wElevator, &hElevator);
    animationElevator->setEndValue(QRect(xElevator, yElevator - FLOOR_HIGH, wElevator, hElevator));

    QPropertyAnimation *animationLeftDoor = new QPropertyAnimation(leftDoor, "geometry");
    animationLeftDoor->setDuration(MOVE_DURATION);
    animationLeftDoor->setStartValue(leftDoor->geometry());
    int xLeftDoor, yLeftDoor, wLeftDoor, hLeftDoor;
    leftDoor->geometry().getRect(&xLeftDoor, &yLeftDoor, &wLeftDoor, &hLeftDoor);
    animationLeftDoor->setEndValue(QRect(xLeftDoor, yLeftDoor - FLOOR_HIGH, wLeftDoor, hLeftDoor));

    QPropertyAnimation *animationRightDoor = new QPropertyAnimation(rightDoor, "geometry");
    animationRightDoor->setDuration(MOVE_DURATION);
    animationRightDoor->setStartValue(rightDoor->geometry());
    int xRightDoor, yRightDoor, wRightDoor, hRightDoor;
    rightDoor->geometry().getRect(&xRightDoor, &yRightDoor, &wRightDoor, &hRightDoor);
    animationRightDoor->setEndValue(QRect(xRightDoor, yRightDoor - FLOOR_HIGH, wRightDoor, hRightDoor));

    animationElevator->start();
    animationLeftDoor->start();
    animationRightDoor->start();
}

void Elevator::moveDown()
{
    QPropertyAnimation *animationElevator = new QPropertyAnimation(elevator, "geometry");
    animationElevator->setDuration(MOVE_DURATION);
    animationElevator->setStartValue(elevator->geometry());
    int xElevator, yElevator, wElevator, hElevator;
    elevator->geometry().getRect(&xElevator, &yElevator, &wElevator, &hElevator);
    animationElevator->setEndValue(QRect(xElevator, yElevator + FLOOR_HIGH, wElevator, hElevator));

    QPropertyAnimation *animationLeftDoor = new QPropertyAnimation(leftDoor, "geometry");
    animationLeftDoor->setDuration(MOVE_DURATION);
    animationLeftDoor->setStartValue(leftDoor->geometry());
    int xLeftDoor, yLeftDoor, wLeftDoor, hLeftDoor;
    leftDoor->geometry().getRect(&xLeftDoor, &yLeftDoor, &wLeftDoor, &hLeftDoor);
    animationLeftDoor->setEndValue(QRect(xLeftDoor, yLeftDoor + FLOOR_HIGH, wLeftDoor, hLeftDoor));

    QPropertyAnimation *animationRightDoor = new QPropertyAnimation(rightDoor, "geometry");
    animationRightDoor->setDuration(MOVE_DURATION);
    animationRightDoor->setStartValue(rightDoor->geometry());
    int xRightDoor, yRightDoor, wRightDoor, hRightDoor;
    rightDoor->geometry().getRect(&xRightDoor, &yRightDoor, &wRightDoor, &hRightDoor);
    animationRightDoor->setEndValue(QRect(xRightDoor, yRightDoor + FLOOR_HIGH, wRightDoor, hRightDoor));

    animationElevator->start();
    animationLeftDoor->start();
    animationRightDoor->start();
}
