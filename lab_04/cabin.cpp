#include "cabin.h"
#include <QString>
#include <QDebug>

Cabin::Cabin(QObject *parent)
    : QObject(parent), current_floor(1), target_floor(0),
      dir(STATIC), state(WAIT)
{
    passing_floor_timer.setSingleShot(true);

    QObject::connect(this, SIGNAL(called()), this, SLOT(move()));
    QObject::connect(&door, SIGNAL(doors_closed()), this, SLOT(wait()));
    QObject::connect(&passing_floor_timer, SIGNAL(timeout()),
                     this, SLOT(move()));
    QObject::connect(this, SIGNAL(floor_reached(int)),
                     this, SLOT(stop()));
    QObject::connect(this, SIGNAL(stopped(int)),
                     &door, SLOT(opening()));
}

void Cabin::stop()
{
    if (state != MOVE)
        return;

    state = STOP;
    qDebug() << "Stopped at" << QString::number(current_floor) << "floor.";
    emit stopped(current_floor);
}

void Cabin::wait()
{
    if (state != STOP)
        return;

    state = WAIT;
    emit waiting(current_floor);
}

void Cabin::start(int floor, direction dir)
{
    if (state != WAIT)
        return;

    state = START;
    target_floor = floor;

    this->dir = dir;
    emit called();
}

void Cabin::move()
{
    if (state != START && state != MOVE)
        return;

    if (state == START)
        state = MOVE;
    else
        current_floor += dir;

    if (current_floor == target_floor)
        emit floor_reached(current_floor);
    else
    {
        qDebug() << "Passed floor" << current_floor;
        emit floor_passed(current_floor, dir);
        passing_floor_timer.start(PASSING_FLOOR);
    }
}
