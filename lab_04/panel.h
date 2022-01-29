#ifndef PANEL_H
#define PANEL_H

#include <QObject>
#include <defines.h>
#include <QVector>

class Panel: public QObject
{
    Q_OBJECT
    enum panelState
    {
        BUSY,
        READY
    };

public:
    explicit Panel(QObject *parent = nullptr);
    void set_new_target(int floor);

signals:
    void found_new_target(int floor, direction dir);

public slots:
    void busy(int floor, direction direction);
    void ready(int floor);

private:
    int current_floor;
    int target_floor;
    QVector<bool> is_target;
    panelState state;
    direction dir;

    bool next_floor();
    void find_new_target();
};

#endif // PANEL_H
