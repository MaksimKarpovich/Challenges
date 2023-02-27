#include "widget.h"
#include "elevator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    Elevator First =  Elevator(w.ui->Elevator);
    return a.exec();
}
