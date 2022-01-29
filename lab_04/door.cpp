#include "door.h"
#include <defines.h>
#include <QDebug>

Door::Door(QObject *parent)
    :QObject(parent), state(CLOSED)
{
    opened_timer.setInterval(WAITING_TIME);
    opened_timer.setSingleShot(true);
    opening_timer.setSingleShot(true);
    closing_timer.setSingleShot(true);

    QObject::connect(&opening_timer, SIGNAL(timeout()), this, SLOT(open()));
    QObject::connect(this, SIGNAL(doors_opened()),
                     &opened_timer, SLOT(start()));
    QObject::connect(&opened_timer, SIGNAL(timeout()),
                     this, SLOT(closing()));
    QObject::connect(&closing_timer, SIGNAL(timeout()), this, SLOT(close()));
}

void Door::opening()
{
    if (state == OPEN || state == OPENING)
        return;

    qDebug() << "Doors are opening...";

    if (state == CLOSED)
        opening_timer.start(DOORS_TIME);
    else
    {
        int remain = closing_timer.remainingTime();
        closing_timer.stop();
        opening_timer.start(DOORS_TIME - remain);
    }

    state = OPENING;
}

void Door::closing()
{
    if (state != OPEN)
        return;

    state = CLOSING;
    qDebug() << "Doors are closing...";
    closing_timer.start(DOORS_TIME);
}

void Door::open()
{
    if (state != OPENING)
        return;

    state = OPEN;
    qDebug() << "Doors are open!";
    emit doors_opened();
}

void Door::close()
{
    if (state != CLOSING)
        return;

    state = CLOSED;
    qDebug() << "Doors are closed!";
    emit doors_closed();
}
