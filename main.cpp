#include "mainwindow.h"
//#include "glvideowidget.h"
#include <QApplication>
#include <QtCore>
#include <QtGui/QImage>
#define YUV_TEST 1
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    //with ui
    MainWindow mainWindow;
    mainWindow.setWindowTitle("AySight");
    mainWindow.show();

    return a.exec();
}
