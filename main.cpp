#include "mainwindow.h"

#include <QApplication>
#include <QFont>
#include <QFontDatabase>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QFontDatabase::addApplicationFont("://font/HuJingLiMaoBiXingShuFan-1.ttf");
    MainWindow w;
    w.show();
    return a.exec();
}
