#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qtfactory.h"
#include "cameracommand.h"
#include "modelcommand.h"
#include "scenecommand.h"
#include "point.h"
#include <iostream>

void MainWindow::setScene() {
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    auto cont = ui->graphicsView->contentsRect();
    scene->setSceneRect(0, 0, cont.width(), cont.height());
    std::shared_ptr<AbstractGraphicsFactory> factory(new QTFactory(std::shared_ptr<QGraphicsScene>(scene)));
    drawer = factory->createGraphics();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setScene();

    connect(ui->addWIreframeBttn, &QPushButton::clicked, this,
              &MainWindow::onAddWIreframeBttnClicked);
    connect(ui->removeWIreframeBttn, &QPushButton::clicked, this,
              &MainWindow::onRemoveWIreframeBttnClicked);
    connect(ui->setViewerBttn, &QPushButton::clicked, this,
              &MainWindow::onSetViewerBttnClicked);
    connect(ui->addViewerBttn, &QPushButton::clicked, this,
              &MainWindow::onAddViewerBttnClicked);
    connect(ui->removeViewerBttn, &QPushButton::clicked, this,
              &MainWindow::onRemoveViewerBttnClicked);
    connect(ui->importViewerBttn, &QPushButton::clicked, this,
              &MainWindow::onImportViewerBttnClicked);

    connect(ui->moveWIreframeBttn, &QPushButton::clicked, this,
            &MainWindow::onMoveWIreframeBttnClicked);
    connect(ui->scaleWireframeBttn, &QPushButton::clicked, this,
            &MainWindow::onScaleWIreframeBttnClicked);
    connect(ui->rotateWireframeBttn, &QPushButton::clicked, this,
            &MainWindow::onRotateWIreframeBttnClicked);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::render() {
  std::shared_ptr<BaseCommand> command(new RenderSceneCommand(drawer));
//  try {
  std::cout << "EXECUTE";
    facade.execute(command);
//  } catch (BaseException &exc) {
//    QMessageBox::warning(this, "Ошибка", QString(exc.what()));
//  }
}

void MainWindow::onAddWIreframeBttnClicked() {
  auto file = QFileDialog::getOpenFileName();
  std::shared_ptr<BaseCommand> command(
      new LoadModelCommand(file.toStdString().data()));
//  try {
    facade.execute(command);
    ui->wireframeBox->addItem(
        QString("Модель_" + QString::number(ui->wireframeBox->count())));

    render();
//  } catch (BaseException &exc) {
//    QMessageBox::warning(this, "Ошибка", QString(exc.what()));
//  }
}

void MainWindow::onRemoveWIreframeBttnClicked() {
  std::shared_ptr<BaseCommand> command(
      new RemoveModelCommand(ui->wireframeBox->currentIndex()));
//  try {
    facade.execute(command);
    ui->wireframeBox->removeItem(ui->wireframeBox->currentIndex());
    render();
//  } catch (BaseException &ex) {
//    QMessageBox::warning(this, "Ошибка", QString(ex.what()));
//  }
}
void MainWindow::onSetViewerBttnClicked() {
  std::shared_ptr<BaseCommand> command(
      new SetCameraCommand(ui->viewerBox->currentIndex()));
//  try {
    facade.execute(command);
    render();
//  } catch (BaseException &ex) {
//    QMessageBox::warning(this, "Ошибка", QString(ex.what()));
//  }
}
void MainWindow::onAddViewerBttnClicked() {
  auto cont = ui->graphicsView->contentsRect();
//  Point pos(cont.width() / 2.0, cont.height() / 2.0, 0.0);
  std::shared_ptr<BaseCommand> command(new AddCameraCommand(0.0, 0.0, 0.0));
//  try {
    facade.execute(command);
    ui->viewerBox->addItem(
        QString("Камера_" + QString::number(ui->viewerBox->count())));
//  } catch (BaseException &ex) {
//    QMessageBox::warning(this, "Ошибка", QString(ex.what()));
//  }
}
void MainWindow::onRemoveViewerBttnClicked() {
  std::shared_ptr<BaseCommand> command(
      new RemoveCameraCommand(ui->viewerBox->currentIndex()));

//  try {
    facade.execute(command);
    ui->viewerBox->removeItem(ui->viewerBox->currentIndex());
    render();
//  } catch (BaseException &ex) {
//    QMessageBox::warning(this, "Ошибка", QString(ex.what()));
//  }
}
void MainWindow::onImportViewerBttnClicked() {
  auto file = QFileDialog::getOpenFileName();
  std::shared_ptr<BaseCommand> command(
      new LoadCameraCommand(file.toStdString().data()));
  std::cout << "here";
//  try {
    facade.execute(command);
    ui->viewerBox->addItem(
        QString("Камера_" + QString::number(ui->wireframeBox->count())));
//  } catch (BaseException &exc) {
//    QMessageBox::warning(this, "Ошибка", QString(exc.what()));
//  }

}

void MainWindow::onMoveWIreframeBttnClicked()
{
    std::shared_ptr<BaseCommand> command(
                new MoveModelCommand(ui->moveWIreframeXBox->value(), ui->moveWIreframeYBox->value(),
                                     ui->moveWIreframeZBox->value(), ui->wireframeBox->currentIndex()));
    facade.execute(command);
    render();
}

void MainWindow::onScaleWIreframeBttnClicked()
{
    std::shared_ptr<BaseCommand> command(
                new ScaleModelCommand(ui->scaleWireframeXBox->value(), ui->scaleWireframeYBox->value(),
                                     ui->scaleWireframeZBox->value(), ui->wireframeBox->currentIndex()));
    facade.execute(command);
    render();
}

void MainWindow::onRotateWIreframeBttnClicked()
{
    std::shared_ptr<BaseCommand> command(
                new RotateModelCommand(ui->rotateWireframeXBox->value(), ui->rotateWireframeYBox->value(),
                                     ui->rotateWireframeZBox->value(), ui->wireframeBox->currentIndex()));
    facade.execute(command);
    render();
}
