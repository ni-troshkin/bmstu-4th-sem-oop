#include <QDebug>
#include <mainwindow.h>
#include <ui_mainwindow.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    qDebug() << "Stopped at 1 floor, doors are closed.\n"
              "Waiting state...";

    for (std::size_t i = 0; i < ui->cabin_buttons.size(); ++i)
    {
        connect(ui->cabin_buttons[i], &QPushButton::pressed, this,
            [=, this]() {cabin_button_clicked(i + 1); });
    }

    for (std::size_t i = 0; i < ui->cabin_buttons.size(); ++i)
    {
        connect(ui->floor_buttons[i], &QPushButton::pressed, this,
            [=, this]() {floor_button_clicked(i + 1); });
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cabin_button_clicked(int num)
{
    qDebug() << "Cabin pressed button " << num;
    lift.click(num);
}

void MainWindow::floor_button_clicked(int num)
{
    qDebug() << "Floor " << num << " called.";
    lift.click(num);
}
