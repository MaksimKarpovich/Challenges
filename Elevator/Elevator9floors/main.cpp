#include "widget.h"
#include "elevator.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    Elevator First =  Elevator(w.ui->Elevator, w.ui->leftDoor, w.ui->rightDoor);
    qDebug() << First.getCurrentFloor();
    First.moveDown();
    First.moveDown();
    First.moveUp();
    First.moveUp();
    First.moveUp();
    First.moveUp();
    First.moveUp();
    First.moveUp();
    First.moveUp();
    First.moveUp();
    First.moveUp();
    First.moveUp();
    First.moveUp();
    First.openDoor();
    First.closeDoor();
    First.moveDown();
    First.openDoor();
    First.closeDoor();
    First.moveDown();
    First.moveDown();

    return a.exec();
}
