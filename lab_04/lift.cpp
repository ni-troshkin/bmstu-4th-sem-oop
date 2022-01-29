#include "lift.h"
#include <QDebug>

Lift::Lift()
{
    QObject::connect(&panel, SIGNAL(found_new_target(int, direction)),
                     &cabin, SLOT(start(int, direction)));
    QObject::connect(&cabin, SIGNAL(floor_passed(int, direction)),
                     &panel, SLOT(busy(int, direction)));
    QObject::connect(&cabin, SIGNAL(waiting(int)),
                     &panel, SLOT(ready(int)));
}

void Lift::click(int floor)
{
    panel.set_new_target(floor);
}
