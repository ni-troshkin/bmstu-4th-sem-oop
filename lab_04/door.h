#ifndef DOOR_H
#define DOOR_H

#include <QObject>
#include <QTimer>

class Door: public QObject
{
    Q_OBJECT
    enum doorState
    {
        OPENING,
        OPEN,
        CLOSING,
        CLOSED
    };

public:
    explicit Door(QObject *parent = nullptr);

signals:
    void doors_closed();
    void doors_opened();

public slots:
    void opening();
    void closing();

private slots:
    void open();
    void close();

private:
    doorState state;
    QTimer opening_timer;
    QTimer closing_timer;
    QTimer opened_timer;
};

#endif // DOOR_H
