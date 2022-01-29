#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <lift.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void cabin_button_clicked(int num);

private slots:
    void floor_button_clicked(int num);

private:
    Ui::MainWindow *ui;
    Lift lift;
};
#endif // MAINWINDOW_H
