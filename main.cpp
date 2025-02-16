#include "mainwindow.h"
//#include "glvideowidget.h"
#include <QApplication>
#include <QtCore>
#include <QtGui/QImage>
#define YUV_TEST 1
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file(":/style.qss");
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = file.readAll();
        a.setStyleSheet(styleSheet);
        file.close();
        qDebug() << "✅ QSS loading succeed！";

    } else {
        qDebug() << "❌ QSS loading fail：" << file.errorString();
    }

    //with ui
    MainWindow mainWindow;
    mainWindow.setWindowTitle("AySight");
    mainWindow.show();

    return a.exec();
}
