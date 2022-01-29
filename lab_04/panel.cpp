#include <panel.h>
#include <QDebug>

Panel::Panel(QObject *parent)
    : QObject(parent), current_floor(1), target_floor(0),
      is_target(NUM_FLOORS, false), state(READY), dir(STATIC)
{
    QObject::connect(this, SIGNAL(found_new_target(int, direction)), this, SLOT(busy(int, direction)));
}

void Panel::set_new_target(int floor)
{
    if (target_floor != floor)
        is_target[floor - 1] = true;

    if (!target_floor)
        target_floor = floor;

    else if (dir != DOWN && floor > target_floor)
        target_floor = floor;

    else if (dir != UP && floor < target_floor)
        target_floor = floor;

    if (state == READY)
        next_floor();
}

void Panel::busy(int floor, direction dir)
{
    if (state == READY)
    {
        is_target[floor - 1] = false;
        qDebug() << "Found target..." << floor;
        state = BUSY;
        this->dir = dir;
    }
    else
        current_floor += dir;
}

void Panel::ready(int floor)
{
    state = READY;
    current_floor = floor;

    if (current_floor == target_floor)
        find_new_target();

    next_floor();
}

void Panel::find_new_target()
{
    bool found = false;
    target_floor = 0;

    if (dir == UP)
    {
        for (size_t i = NUM_FLOORS; i >= 1 && !found; i--)
            if (is_target[i - 1])
            {
                target_floor = i;
                found = true;
            }
        return;
    }

    for (size_t i = 1; i <= NUM_FLOORS && !found; i++)
        if (is_target[i - 1])
        {
            target_floor = i;
            found = true;
        }
}

bool Panel::next_floor()
{
    if (is_target[current_floor - 1])
    {
        emit found_new_target(current_floor, STATIC);
        return true;
    }

    bool found = false;
    if (target_floor > current_floor)
    {
        for (int i = current_floor; i <= NUM_FLOORS && !found; i++)
            if (is_target[i - 1])
            {
                emit found_new_target(i, UP);
                found = true;
            }
    }
    else
        for (int i = current_floor; i >= 1 && !found; i--)
            if (is_target[i - 1])
            {
                emit found_new_target(i, DOWN);
                found = true;
            }

    return found;
}
