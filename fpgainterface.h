#ifndef FPGAINTERFACE_H
#define FPGAINTERFACE_H

#include<Windows.h>
#include <QObject>
#include <QDebug>
#include "CyAPI.h"
#include <condition_variable>
#include <vector>
#include <atomic>
#include <QFile>
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
    bool writeImageData(const QString& inputFilePath);
    void stopTransfer();  // Function to stop the transfer
    // Function to convert grayscale data to YUV format
    // bool convertGrayscaleToYUV(const std::string& inputFilePath, QByteArray& yuvData, int width, int height);
    // Function to convert multiple .bin files to YUV and store results in a single QByteArray
    QByteArray convertMultipleGrayscaleBinsToYUV(const std::vector<std::string>& inputFiles, int width, int height);
    // Set exposure time on FX3
    bool setExposureTimeFX3(CCyUSBDevice *usbDevice, int exposureTime);
    // Read back exposure time from FX3
    bool readBackExposureTimeFX3(CCyUSBDevice *usbDevice, int *readExposureTime);
    bool readImage(unsigned char *data);
    QByteArray readImageAsYUV();

signals:
    void deviceAttached();   // Signal emitted when a device is attached
    void deviceDetached();   // Signal emitted when a device is detached

private:
    CCyUSBDevice *usbDevice; // USB device handler
    bool isDeviceConnected;
    std::mutex bufferMutex;
    std::condition_variable bufferCondition;
    bool bufferReady = false;
    bool useBufferA = true;
    std::vector<UCHAR> bufferA;
    std::vector<UCHAR> bufferB;
    std::atomic<bool> stopFlag{false};  // Stop flag for controlling the transfer
};

#endif // FPGAINTERFACE_H
