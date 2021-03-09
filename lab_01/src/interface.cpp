#include <QGraphicsScene>
#include <QLineEdit>
#include <QMessageBox>
#include <QPen>
#include <QColor>

#include <stdlib.h>
#include <stdio.h>

#include "interface.h"
#include "ui_interface.h"
#include "processing.h"

QGraphicsScene *scene;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1180, 870);
    ui->canvas->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete scene;

    delete ui;
}

void MainWindow::on_load_btn_clicked()
{
    const char *filename = ui->entry_load->text().toLocal8Bit().data();
    model_t model = process(LOAD, filename);
    if (model.points == NULL)
        QMessageBox::warning(this, "Error", "File not found");
    else
        MainWindow::draw(model);
}

void MainWindow::draw(model_t &model)
{
    scene->clear();
    QPen pen = QPen(QColor(0, 100, 0));
    pen.setWidth(4);
    for (size_t i = 0; i < model.links_count; i++)
        scene->addLine(model.points[model.links[i].from].x,
                model.points[model.links[i].from].y,
                model.points[model.links[i].to].x,
                model.points[model.links[i].to].y, pen);
}

void MainWindow::on_save_btn_clicked()
{
    const char *filename = ui->entry_save->text().toLocal8Bit().data();
    process(SAVE, filename);
    FILE *f = fopen(filename, "r");
    if (!f)
        QMessageBox::warning(this, "Error", "Incorrect name of file");
    else
        fclose(f);
}

void MainWindow::transform(action_t action)
{
    double x, y, z;
    bool error = false;
    char *end = nullptr;

    QLineEdit *ex, *ey, *ez;
    if (action == MOVE)
    {
        ex = ui->entry_dx;
        ey = ui->entry_dy;
        ez = ui->entry_dz;
    }
    else if (action == SCALE)
    {
        ex = ui->entry_kx;
        ey = ui->entry_ky;
        ez = ui->entry_kz;
    }
    else
    {
        ex = ui->entry_thx;
        ey = ui->entry_thy;
        ez = ui->entry_thz;
    }

    const char *csx = ex->text().toLocal8Bit().data();
    x = strtod(csx, &end);
    if (*end)
        error = true;
    const char *csy = ey->text().toLocal8Bit().data();
    y = strtod(csy, &end);
    if (*end)
        error = true;
    const char *csz = ez->text().toLocal8Bit().data();
    z = strtod(csz, &end);
    if (*end)
        error = true;

    if (error)
        QMessageBox::warning(this, "Error", "Invalid value");
    else
    {
        model_t model = process(action, x, y, z);
        if (!model.points)
            QMessageBox::warning(this, "Error", "Model was not uploaded");
        MainWindow::draw(model);
    }
}

void MainWindow::on_move_btn_clicked()
{
    MainWindow::transform(MOVE);
}

void MainWindow::on_scale_btn_clicked()
{
    MainWindow::transform(SCALE);
}

void MainWindow::on_rotate_btn_clicked()
{
    MainWindow::transform(ROTATE);
}

void MainWindow::on_info_btn_clicked()
{
    QMessageBox::information(this, "Информация о программе",
                             "3D-Viewer с ортогональным проецированием\n\n"
                             "Возможности: перенос, масштабирование, поворот, "
                             "загрузка моделей из файла, сохранение в файл.\n"
                             "\nПРИМЕЧАНИЕ: целая часть от дробной отделяется "
                             "запятой в действительных величинах.");
}

void MainWindow::on_exit_btn_clicked()
{
    exit(0);
}

void MainWindow::on_MainWindow_destroyed()
{
    process(EXIT);
}
