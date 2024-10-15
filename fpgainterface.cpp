#include "fpgainterface.h"
#include <QFile>
#include <QDebug>
#include <QThread>

FPGAInterface::FPGAInterface(QObject *parent)
    : QObject{parent}, usbDevice(nullptr), isDeviceConnected(false)
{
    usbDevice = new CCyUSBDevice(nullptr, CYUSBDRV_GUID, true);

    if (usbDevice->DeviceCount() > 0) {
        initializeDevice();
    } else {
        qDebug() << "No Devices Attached";
    }
}

bool FPGAInterface::initializeDevice()
{
    if (usbDevice->DeviceCount() > 0) {
        usbDevice->Open(0);  // Open the first available device
        isDeviceConnected = true;
        emit deviceAttached();
        qDebug() << "Device Attached";
        return true;
    } else {
        qDebug() << "Failed to initialize device. No devices found.";
        return false;
    }
}

bool FPGAInterface::configureFPGA(const QString &fwFilePath)
{
    if (!isDeviceConnected) {
        qDebug() << "No FPGA device is connected.";
        return false;
    }

    // Ensure the firmware file exists
    QFile fwFile(fwFilePath);
    if (!fwFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Firmware file not found or could not be opened:" << fwFilePath;
        return false;
    }

    // Get the firmware data from the file
    QByteArray firmwareData = fwFile.readAll();
    fwFile.close();

    // Assume endpoint 0x01 is used for FPGA firmware download. You should verify the correct endpoint.
    CCyUSBEndPoint *outEndpoint = usbDevice->EndPoints[1];  // Index may vary, adjust as needed

    if (outEndpoint == nullptr) {
        qDebug() << "Unable to get the USB endpoint for data transfer.";
        return false;
    }

    // Configure endpoint settings if necessary
    outEndpoint->TimeOut = 5000;  // Set timeout to 5 seconds

    // Transfer data in chunks
    long chunkSize = outEndpoint->MaxPktSize;
    long bytesTransferred = 0;
    long totalSize = firmwareData.size();

    while (bytesTransferred < totalSize) {
        long bytesToTransfer = qMin(chunkSize, totalSize - bytesTransferred);
        UCHAR *dataPtr = reinterpret_cast<UCHAR*>(firmwareData.data() + bytesTransferred);
        long transferred = bytesToTransfer;

        if (!outEndpoint->XferData(dataPtr, transferred)) {
            qDebug() << "Data transfer failed at" << bytesTransferred << "bytes.";
            return false;
        }

        bytesTransferred += transferred;
    }

    qDebug() << "FPGA configuration completed successfully.";
    return true;
}

void FPGAInterface::refreshDeviceList()
{
    int deviceCount = usbDevice->DeviceCount();
    if (deviceCount > 0) {
        qDebug() << "Connected Devices:";
        for (int i = 0; i < deviceCount; ++i) {
            usbDevice->Open(i);
            qDebug() << QString::fromStdString(usbDevice->FriendlyName);
        }
    } else {
        qDebug() << "No Devices Connected";
    }
}
