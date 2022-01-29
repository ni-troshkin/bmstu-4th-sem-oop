#ifndef LIFT_H
#define LIFT_H

#include <QObject>
#include <panel.h>
#include <cabin.h>

class Lift: public QObject
{
    Q_OBJECT

public:
    Lift();
    void click(int floor);

private:
    Panel panel;
    Cabin cabin;
};

#endif // LIFT_H
