#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include "processing.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_exit_btn_clicked();

    void on_move_btn_clicked();

    void on_load_btn_clicked();

    void draw(model_t &model);

    void transform(action_t action);

    void on_save_btn_clicked();

    void on_scale_btn_clicked();

    void on_rotate_btn_clicked();

    void on_info_btn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // INTERFACE_H
