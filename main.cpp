#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    // 设置应用程序信息
    app.setApplicationName("贪吃蛇游戏");
    app.setApplicationVersion("1.0");
    app.setOrganizationName("Qt Examples");
    
    MainWindow mainWindow;
    mainWindow.show();
    
    return app.exec();
}