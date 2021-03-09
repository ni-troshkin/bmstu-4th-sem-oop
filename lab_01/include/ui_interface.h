/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *canvas;
    QPushButton *exit_btn;
    QPushButton *save_btn;
    QPushButton *info_btn;
    QPushButton *load_btn;
    QPushButton *rotate_btn;
    QPushButton *scale_btn;
    QPushButton *move_btn;
    QLineEdit *entry_dx;
    QLineEdit *entry_dy;
    QLineEdit *entry_dz;
    QLineEdit *entry_kx;
    QLineEdit *entry_kz;
    QLineEdit *entry_ky;
    QLineEdit *entry_thx;
    QLineEdit *entry_thz;
    QLineEdit *entry_thy;
    QLabel *label_dx;
    QLabel *label_dy;
    QLabel *label_dz;
    QLabel *label_kx;
    QLabel *label_ky;
    QLabel *label_kz;
    QLabel *label_thx;
    QLabel *label_thy;
    QLabel *label_thz;
    QLineEdit *entry_load;
    QLineEdit *entry_save;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1600, 900);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(223, 172, 207);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        canvas = new QGraphicsView(centralwidget);
        canvas->setObjectName(QString::fromUtf8("canvas"));
        canvas->setGeometry(QRect(10, 10, 1200, 880));
        canvas->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 217, 255);"));
        exit_btn = new QPushButton(centralwidget);
        exit_btn->setObjectName(QString::fromUtf8("exit_btn"));
        exit_btn->setGeometry(QRect(1410, 840, 171, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("KacstTitle"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        exit_btn->setFont(font);
        exit_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(204, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        save_btn = new QPushButton(centralwidget);
        save_btn->setObjectName(QString::fromUtf8("save_btn"));
        save_btn->setGeometry(QRect(1410, 780, 171, 51));
        save_btn->setFont(font);
        save_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);\n"
"color: rgb(255, 255, 255);"));
        info_btn = new QPushButton(centralwidget);
        info_btn->setObjectName(QString::fromUtf8("info_btn"));
        info_btn->setGeometry(QRect(1220, 840, 171, 51));
        info_btn->setFont(font);
        info_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);\n"
"color: rgb(255, 255, 255);"));
        load_btn = new QPushButton(centralwidget);
        load_btn->setObjectName(QString::fromUtf8("load_btn"));
        load_btn->setGeometry(QRect(1410, 720, 171, 51));
        load_btn->setFont(font);
        load_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);\n"
"color: rgb(255, 255, 255);"));
        rotate_btn = new QPushButton(centralwidget);
        rotate_btn->setObjectName(QString::fromUtf8("rotate_btn"));
        rotate_btn->setGeometry(QRect(1220, 650, 361, 51));
        rotate_btn->setFont(font);
        rotate_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 95, 180);\n"
"color: rgb(255, 255, 255);"));
        scale_btn = new QPushButton(centralwidget);
        scale_btn->setObjectName(QString::fromUtf8("scale_btn"));
        scale_btn->setGeometry(QRect(1220, 410, 361, 51));
        scale_btn->setFont(font);
        scale_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 95, 180);\n"
"color: rgb(255, 255, 255);"));
        move_btn = new QPushButton(centralwidget);
        move_btn->setObjectName(QString::fromUtf8("move_btn"));
        move_btn->setGeometry(QRect(1220, 170, 361, 51));
        move_btn->setFont(font);
        move_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 95, 180);\n"
"color: rgb(255, 255, 255);"));
        entry_dx = new QLineEdit(centralwidget);
        entry_dx->setObjectName(QString::fromUtf8("entry_dx"));
        entry_dx->setGeometry(QRect(1430, 10, 151, 41));
        QFont font1;
        font1.setPointSize(15);
        entry_dx->setFont(font1);
        entry_dx->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        entry_dy = new QLineEdit(centralwidget);
        entry_dy->setObjectName(QString::fromUtf8("entry_dy"));
        entry_dy->setGeometry(QRect(1430, 60, 151, 41));
        entry_dy->setFont(font1);
        entry_dy->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        entry_dz = new QLineEdit(centralwidget);
        entry_dz->setObjectName(QString::fromUtf8("entry_dz"));
        entry_dz->setGeometry(QRect(1430, 110, 151, 41));
        entry_dz->setFont(font1);
        entry_dz->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        entry_kx = new QLineEdit(centralwidget);
        entry_kx->setObjectName(QString::fromUtf8("entry_kx"));
        entry_kx->setGeometry(QRect(1430, 250, 151, 41));
        entry_kx->setFont(font1);
        entry_kx->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        entry_kz = new QLineEdit(centralwidget);
        entry_kz->setObjectName(QString::fromUtf8("entry_kz"));
        entry_kz->setGeometry(QRect(1430, 350, 151, 41));
        entry_kz->setFont(font1);
        entry_kz->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        entry_ky = new QLineEdit(centralwidget);
        entry_ky->setObjectName(QString::fromUtf8("entry_ky"));
        entry_ky->setGeometry(QRect(1430, 300, 151, 41));
        entry_ky->setFont(font1);
        entry_ky->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        entry_thx = new QLineEdit(centralwidget);
        entry_thx->setObjectName(QString::fromUtf8("entry_thx"));
        entry_thx->setGeometry(QRect(1430, 490, 151, 41));
        entry_thx->setFont(font1);
        entry_thx->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        entry_thz = new QLineEdit(centralwidget);
        entry_thz->setObjectName(QString::fromUtf8("entry_thz"));
        entry_thz->setGeometry(QRect(1430, 590, 151, 41));
        entry_thz->setFont(font1);
        entry_thz->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        entry_thy = new QLineEdit(centralwidget);
        entry_thy->setObjectName(QString::fromUtf8("entry_thy"));
        entry_thy->setGeometry(QRect(1430, 540, 151, 41));
        entry_thy->setFont(font1);
        entry_thy->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_dx = new QLabel(centralwidget);
        label_dx->setObjectName(QString::fromUtf8("label_dx"));
        label_dx->setGeometry(QRect(1240, 20, 151, 31));
        label_dx->setFont(font);
        label_dy = new QLabel(centralwidget);
        label_dy->setObjectName(QString::fromUtf8("label_dy"));
        label_dy->setGeometry(QRect(1240, 70, 151, 31));
        label_dy->setFont(font);
        label_dz = new QLabel(centralwidget);
        label_dz->setObjectName(QString::fromUtf8("label_dz"));
        label_dz->setGeometry(QRect(1240, 120, 151, 31));
        label_dz->setFont(font);
        label_kx = new QLabel(centralwidget);
        label_kx->setObjectName(QString::fromUtf8("label_kx"));
        label_kx->setGeometry(QRect(1240, 260, 151, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("KacstTitle"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        label_kx->setFont(font2);
        label_ky = new QLabel(centralwidget);
        label_ky->setObjectName(QString::fromUtf8("label_ky"));
        label_ky->setGeometry(QRect(1240, 310, 151, 31));
        label_ky->setFont(font2);
        label_kz = new QLabel(centralwidget);
        label_kz->setObjectName(QString::fromUtf8("label_kz"));
        label_kz->setGeometry(QRect(1240, 360, 151, 31));
        label_kz->setFont(font2);
        label_thx = new QLabel(centralwidget);
        label_thx->setObjectName(QString::fromUtf8("label_thx"));
        label_thx->setGeometry(QRect(1240, 500, 151, 31));
        label_thx->setFont(font2);
        label_thy = new QLabel(centralwidget);
        label_thy->setObjectName(QString::fromUtf8("label_thy"));
        label_thy->setGeometry(QRect(1240, 550, 151, 31));
        label_thy->setFont(font2);
        label_thz = new QLabel(centralwidget);
        label_thz->setObjectName(QString::fromUtf8("label_thz"));
        label_thz->setGeometry(QRect(1240, 600, 151, 31));
        label_thz->setFont(font2);
        entry_load = new QLineEdit(centralwidget);
        entry_load->setObjectName(QString::fromUtf8("entry_load"));
        entry_load->setGeometry(QRect(1220, 720, 171, 51));
        QFont font3;
        font3.setPointSize(12);
        entry_load->setFont(font3);
        entry_load->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        entry_load->setReadOnly(false);
        entry_save = new QLineEdit(centralwidget);
        entry_save->setObjectName(QString::fromUtf8("entry_save"));
        entry_save->setGeometry(QRect(1220, 780, 171, 51));
        entry_save->setFont(font3);
        entry_save->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        exit_btn->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        save_btn->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        info_btn->setText(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        load_btn->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        rotate_btn->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        scale_btn->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        move_btn->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270", nullptr));
        label_dx->setText(QApplication::translate("MainWindow", "\320\241\320\274\320\265\321\211\320\265\320\275\320\270\320\265 \320\245", nullptr));
        label_dy->setText(QApplication::translate("MainWindow", "\320\241\320\274\320\265\321\211\320\265\320\275\320\270\320\265 Y", nullptr));
        label_dz->setText(QApplication::translate("MainWindow", "\320\241\320\274\320\265\321\211\320\265\320\275\320\270\320\265 Z", nullptr));
        label_kx->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 kx", nullptr));
        label_ky->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 ky", nullptr));
        label_kz->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 kz", nullptr));
        label_thx->setText(QApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 \320\262\320\276\320\272\321\200\321\203\320\263 \320\276\321\201\320\270 \320\245", nullptr));
        label_thy->setText(QApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 \320\262\320\276\320\272\321\200\321\203\320\263 \320\276\321\201\320\270 Y", nullptr));
        label_thz->setText(QApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 \320\262\320\276\320\272\321\200\321\203\320\263 \320\276\321\201\320\270 Z", nullptr));
        entry_load->setText(QString());
        entry_save->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
