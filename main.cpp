#include "mainwindow.h"
//#include "glvideowidget.h"
#include "usbinterface.h"
#include <QApplication>
#include <QtCore>
#include <QtGui/QImage>
#define YUV_TEST 1
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // //without ui
    // ( if (a.arguments().contains("-angle"))
    //     QApplication::setAttribute(Qt::AA_UseOpenGLES);
    // GLVideoWidget glw;
    // if (!a.arguments().contains("-img")) {

    //     //sample1 1280x720
    //     // QFile f(":/1280x720.yuv");
    //     // f.open(QIODevice::ReadOnly);
    //     // QByteArray data(f.readAll());
    //     // qDebug("data size: %lld", data.size());
    //     // const int w = 1280, h = 720;

    //     //sample2 176x144
    //     QFile f(":/akiyo_qcif.yuv");
    //     f.open(QIODevice::ReadOnly);
    //     QByteArray data(f.readAll());
    //     qDebug("data size: %lld", data.size());
    //     const int w = 176, h = 144;

    //     glw.setYUV420pParameters(w, h); //call once
    //     glw.setFrameData(data);
    // } else {
    //     QImage img = QImage(":/test.png").convertToFormat(QImage::Format_RGB888);
    //     glw.setQImageParameters(img.format(), img.width(), img.height(), img.bytesPerLine()); //call once
    //     glw.setImage(img);
    // }
    // glw.show();

    uint16_t vendor_id = 0x04B4;  // Example Vendor ID
    uint16_t product_id = 0x00F1; // Example Product ID
    uint8_t endpoint_in = 0x01;

    USBInterface usb(vendor_id, product_id, endpoint_in);

    usb.initializeUSB();

    //with ui
    MainWindow mainWindow;
    mainWindow.setWindowTitle("Image & Video Viewer");
    mainWindow.show();

    return a.exec();
}
