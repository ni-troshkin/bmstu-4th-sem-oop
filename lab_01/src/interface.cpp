#include <QGraphicsScene>
#include <QLineEdit>
#include <QMessageBox>
#include <QPen>
#include <QColor>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

void MainWindow::err_handler(err_t error)
{
    switch (error)
    {
        case OK: break;
        case FILE_NOT_FOUND:
            QMessageBox::warning(this, "Ошибка", "Файл не найден"); break;
        case INVALID_FILENAME:
            QMessageBox::warning(this, "Ошибка", "Некорректное имя файла"); break;
        case ALLOC_ERR:
            QMessageBox::warning(this, "Ошибка", "Ошибка выделения памяти"); break;
        case NULL_PTR_ERR:
            QMessageBox::warning(this, "Ошибка", "Ошибка в программе"); break;
        case READ_ERR:
            QMessageBox::warning(this, "Ошибка", "Файл поврежден, неверные данные"); break;
        case SELF_LINK:
            QMessageBox::warning(this, "Ошибка", "Неверные данные: отрезок выродился в точку"); break;
        case POINT_NOT_EXIST:
            QMessageBox::warning(this, "Ошибка", "Неверные данные: ребро в несуществующей точке"); break;
        case INVALID_FUNC:
            QMessageBox::warning(this, "Ошибка", "Ошибка в программе"); break;
        case EMPTY_MODEL:
            QMessageBox::warning(this, "Ошибка", "Модель не загружена"); break;
        case ZERO_SCALE:
            QMessageBox::warning(this, "Ошибка", "Нулевое масштабирование запрещено"); break;
    }
}

void MainWindow::on_load_btn_clicked()
{
    QByteArray tmp = ui->entry_load->text().toLocal8Bit();
    const char *filename = strdup(tmp.data());
    QMessageBox msgBox;
    msgBox.setWindowTitle("Сохранение файла");
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setText("На данный момент у вас загружена другая модель."
                   "Очистить ее, если она не сохранена?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int ret = msgBox.exec();
    if (ret == QMessageBox::Yes)
    {
        args_t args;
        args.action = LOAD;
        args.name = filename;
        model_t model = process(args);
        if (model.error)
            err_handler(model.error);
        else
            MainWindow::draw(model);
    }
    free((void *)filename);
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
    QByteArray tmp = ui->entry_save->text().toLocal8Bit();
    const char *filename = strdup(tmp.data());
    args_t args;
    args.name = filename;
    args.action = SAVE;
    model_t model = process(args);
    err_handler(model.error);
    free((void *)filename);
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

    QByteArray tmp = ex->text().toLocal8Bit();
    const char *csx = strdup(tmp.data());
    x = strtod(csx, &end);
    if (*end)
        error = true;
    tmp = ey->text().toLocal8Bit();
    const char *csy = strdup(tmp.data());
    y = strtod(csy, &end);
    if (*end)
        error = true;
    tmp = ez->text().toLocal8Bit();
    const char *csz = strdup(tmp.data());
    z = strtod(csz, &end);
    if (*end)
        error = true;

    if (error)
        QMessageBox::warning(this, "Error", "Invalid value");
    else
    {
        args_t args;
        args.action = action;
        args.tr_args.x = x;
        args.tr_args.y = y;
        args.tr_args.z = z;
        model_t model = process(args);
        if (model.error)
            err_handler(model.error);
        else
            MainWindow::draw(model);
    }

    free((void *)csx);
    free((void *)csy);
    free((void *)csz);
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
    args_t args;
    args.action = EXIT;
    process(args);
    exit(0);
}
