#ifndef CABIN_H
#define CABIN_H

#include <QObject>
#include <QTimer>
#include <door.h>
#include <defines.h>

class Cabin: public QObject
{
    Q_OBJECT

    enum cabinState
    {
        MOVE,
        STOP,
        WAIT,
        START
    };

public:
    explicit Cabin(QObject *parent = nullptr);

public slots:
    void move();
    void stop();
    void wait();
    void start(int floor, direction dir);

signals:
    void stopped(int floor);
    void floor_passed(int floor, direction dir);
    void called();
    void floor_reached(int floor);
    void waiting(int floor);

private:
    Door door;
    QTimer passing_floor_timer;
    int current_floor;
    int target_floor;
    direction dir;
    cabinState state;
};

#endif // CABIN_H
