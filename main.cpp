#include "mainwindow.h"
//#include "glvideowidget.h"
#include <QApplication>
#include <QtCore>
#include <QtGui/QImage>
#include "fpgainterface.h"

#define YUV_TEST 1
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // //without ui
    // ( if (a.arguments().contains("-angle"))
    //     QApplication::setAttribute(Qt::AA_UseOpenGLES);
    // GLVideoWidget glw;
    // if (!a.arguments().contains("-img")) {

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

    //with ui
    MainWindow mainWindow;
    mainWindow.setWindowTitle("AySight");
    mainWindow.show();

    FPGAInterface fpga;

    // // Open the FX3 device
    // CCyUSBDevice usbDevice;
    // if (!usbDevice.IsOpen()) {
    //     fprintf(stderr, "Failed to open FX3 device.\n");
    //     return -1;
    // }

    // // Set exposure time
    // int exposureTime = 5000; // Example value in milliseconds
    // if (!fpga.setExposureTimeFX3(&usbDevice, exposureTime)) {
    //     fprintf(stderr, "Failed to set exposure time.\n");
    //     return -1;
    // }

    fpga.initializeDevice();

    // // Wait for the FX3 to process the data
    // Sleep(10); // Wait for 10 milliseconds

    // // Read back exposure time
    // int readExposureTime = 0;
    // if (!fpga.readBackExposureTimeFX3(&usbDevice, &readExposureTime)) {
    //     fprintf(stderr, "Failed to read back exposure time.\n");
    //     return -1;
    // }

    return a.exec();
}
