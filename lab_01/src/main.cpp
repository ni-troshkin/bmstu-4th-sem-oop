#include "interface.h"

#include <QApplication>

int main(int argc, char *argv[])
{
//    setbuf(stdout, nullptr);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}