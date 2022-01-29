#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QFileDialog>
#include <memory>

#include "facade.h"
#include "basedrawer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddWIreframeBttnClicked();
    void onRemoveWIreframeBttnClicked();

    void onSetViewerBttnClicked();
    void onAddViewerBttnClicked();
    void onRemoveViewerBttnClicked();
    void onImportViewerBttnClicked();
    void onMoveWIreframeBttnClicked();
    void onScaleWIreframeBttnClicked();
    void onRotateWIreframeBttnClicked();

private:
    Ui::MainWindow *ui;
    void setScene();
    void render();

    Facade facade;
    std::size_t viewers;

    QGraphicsScene *scene;
    std::shared_ptr<BaseDrawer> drawer;
};
#endif // MAINWINDOW_H
