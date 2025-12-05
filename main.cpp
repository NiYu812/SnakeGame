#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("贪吃蛇游戏");
    a.setApplicationVersion("1.0");
    
    MainWindow w;
    w.show();
    
    return a.exec();
}