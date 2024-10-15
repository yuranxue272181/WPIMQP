#ifndef FPGAINTERFACE_H
#define FPGAINTERFACE_H

#include<Windows.h>
#include <QObject>
#include <QDebug>
#include "CyAPI.h"
#pragma comment(lib,"SetupAPI.lib")
#pragma comment(lib,"User32.lib")
#pragma comment(lib,"legacy_stdio_definitions.lib")

class FPGAInterface : public QObject
{
    Q_OBJECT
public:
    explicit FPGAInterface(QObject *parent = nullptr);
    bool initializeDevice();                // Initialize USB Device
    void refreshDeviceList();               // Refresh connected devices
    bool configureFPGA(const QString &fwFilePath); // Configure FPGA using firmware file

signals:
    void deviceAttached();   // Signal emitted when a device is attached
    void deviceDetached();   // Signal emitted when a device is detached

private:
    CCyUSBDevice *usbDevice; // USB device handler
    bool isDeviceConnected;
};

#endif // FPGAINTERFACE_H
