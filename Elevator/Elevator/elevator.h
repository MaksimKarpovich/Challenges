#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QWidget>
#include <QPropertyAnimation>
#include "ui_widget.h"
#include "widget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Elevator;
}
QT_END_NAMESPACE

class Elevator : public Widget
{
    Q_OBJECT

public:
    Elevator(QPushButton *Elevator);
    ~Elevator();

};
#endif // ELEVATOR_H
