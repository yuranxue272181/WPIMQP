#include "fpgainterface.h"
#include <QFile>
#include <QDebug>
#include <QThread>
#include <cstdint>
#include <QByteArray>

struct ImageHeader {
    uint32_t width;       // Image width
    uint32_t height;      // Image height
};

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

// Function to stop the transfer
void FPGAInterface::stopTransfer() {
    stopFlag = true;
    bufferCondition.notify_all();  // Notify all waiting threads to proceed and stop
}

bool FPGAInterface::writeImageData(const QString &inputFilePath)
{
    if (!isDeviceConnected) {
        qDebug() << "No FPGA device is connected.";
        return false;
    }

    // Assume endpoint 0x01 is used for FPGA data transfer (OUT)
    CCyUSBEndPoint *outEndpoint = usbDevice->EndPoints[1];  // OUT endpoint at index 1

    if (outEndpoint == nullptr) {
        qDebug() << "Unable to get the USB endpoint for data transfer.";
        return false;
    }

    // Configure endpoint settings if necessary
    outEndpoint->TimeOut = 5000;  // Set timeout to 5 seconds

    // Open the input file for reading data to be written to the FPGA
    QFile inFile(inputFilePath);
    if (!inFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open input file for reading:" << inputFilePath;
        return false;
    }

    bool stopButtonPressed = false; // Replace with actual stop button press detection logic

    while (!inFile.atEnd() && !stopButtonPressed) {
        QByteArray fileData = inFile.read(1024);  // Read 1024 bytes at a time
        long dataSize = fileData.size();

        if (dataSize > 0) {
            UCHAR *dataPtr = reinterpret_cast<UCHAR*>(fileData.data());
            long transferred = dataSize;

            // Write data to FPGA
            if (!outEndpoint->XferData(dataPtr, transferred)) {
                qDebug() << "Data transfer failed.";
                return false;
            }

            qDebug() << "Transferred" << transferred << "bytes to FPGA.";
        }
    }

    inFile.close();
    qDebug() << "Image data successfully written.";
    return true;
}

// bool FPGAInterface::convertGrayscaleToYUV(const std::string& inputFilePath, QByteArray& yuvData, int width, int height) {
//     // Open the input binary file
//     QFile file(QString::fromStdString(inputFilePath));
//     if (!file.open(QIODevice::ReadOnly)) {
//         qDebug() << "Error opening input file:" << file.errorString();
//         return false;
//     }

//     // Calculate the size of the YUV data
//     size_t ySize = width * height;
//     size_t uSize = (width / 2) * (height / 2);
//     size_t vSize = (width / 2) * (height / 2);
//     size_t totalSize = ySize + uSize + vSize;

//     // Resize QByteArray to hold all YUV data
//     yuvData.resize(totalSize);

//     // Read grayscale data from the file
//     QByteArray grayscaleData = file.readAll();
//     if (grayscaleData.size() != ySize) {
//         qDebug() << "Error: Expected grayscale data size does not match. Expected:" << ySize << "but got:" << grayscaleData.size();
//         return false;
//     }

//     // Pointers for Y, U, and V data
//     uint8_t* yPlane = reinterpret_cast<uint8_t*>(yuvData.data());
//     uint8_t* uPlane = yPlane + ySize;
//     uint8_t* vPlane = uPlane + uSize;

//     // Process grayscale data to generate YUV data
//     for (int j = 0; j < height; j++) {
//         for (int i = 0; i < width; i++) {
//             // Read grayscale value (assuming each byte represents a grayscale value)
//             uint8_t grayscaleValue = static_cast<uint8_t>(grayscaleData[j * width + i]);

//             // Set Y value directly from the grayscale value
//             yPlane[j * width + i] = grayscaleValue;

//             // Set U and V to neutral values (128)
//             if (j % 2 == 0 && i % 2 == 0) { // Subsample for U and V
//                 uPlane[(j / 2) * (width / 2) + (i / 2)] = 128; // U
//                 vPlane[(j / 2) * (width / 2) + (i / 2)] = 128; // V
//             }
//         }
//     }

//     file.close();
//     return true;
// }

QByteArray FPGAInterface::convertMultipleGrayscaleBinsToYUV(const std::vector<std::string>& inputFiles, int width, int height) {
    QByteArray combinedYuvData;

    for (const auto& inputFile : inputFiles) {
        // Open the input binary file
        QFile file(QString::fromStdString(inputFile));
        if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << "Error opening input file:" << file.errorString();
            continue; // Skip this file and proceed to the next one
        }

        // Calculate the size of the YUV data for this frame
        size_t ySize = width * height;
        size_t uSize = (width / 2) * (height / 2);
        size_t vSize = (width / 2) * (height / 2);
        size_t totalSize = ySize + uSize + vSize;

        // Read grayscale data from the file
        QByteArray grayscaleData = file.readAll();
        if (grayscaleData.size() != ySize) {
            qDebug() << "Error: Expected grayscale data size does not match for file:" << QString::fromStdString(inputFile);
            file.close();
            continue; // Skip this file if size does not match
        }

        // Prepare a QByteArray for the current YUV data
        QByteArray yuvData;
        yuvData.resize(totalSize);

        // Pointers for Y, U, and V data
        uint8_t* yPlane = reinterpret_cast<uint8_t*>(yuvData.data());
        uint8_t* uPlane = yPlane + ySize;
        uint8_t* vPlane = uPlane + uSize;

        // Process grayscale data to generate YUV data
        for (int j = 0; j < height; j++) {
            for (int i = 0; i < width; i++) {
                // Read grayscale value
                uint8_t grayscaleValue = static_cast<uint8_t>(grayscaleData[j * width + i]);

                // Set Y value directly from the grayscale value
                yPlane[j * width + i] = grayscaleValue;

                // Set U and V to neutral values (128)
                if (j % 2 == 0 && i % 2 == 0) { // Subsample for U and V
                    uPlane[(j / 2) * (width / 2) + (i / 2)] = 128; // U
                    vPlane[(j / 2) * (width / 2) + (i / 2)] = 128; // V
                }
            }
        }

        file.close();

        // Append the current YUV data to the combined YUV data
        combinedYuvData.append(yuvData);
    }

    return combinedYuvData; // Return the combined YUV data
}

bool FPGAInterface::setExposureTimeFX3(CCyUSBDevice *usbDevice, int exposureTime) {
    if (!usbDevice || !usbDevice->IsOpen()) {
        fprintf(stderr, "FX3 device not connected or not open.\n");
        return false;
    }

    // Find the Bulk OUT endpoint (Address: 0x01)
    CCyBulkEndPoint *bulkOut = (CCyBulkEndPoint *)usbDevice->EndPointOf(0x01);
    if (!bulkOut) {
        fprintf(stderr, "Bulk OUT endpoint (0x01) not found.\n");
        return false;
    }

    // Prepare exposure time data (4 bytes)
    unsigned char data[4];
    data[0] = (exposureTime >> 24) & 0xFF;
    data[1] = (exposureTime >> 16) & 0xFF;
    data[2] = (exposureTime >> 8) & 0xFF;
    data[3] = exposureTime & 0xFF;

    long bytesTransferred = sizeof(data);

    // Send data to FX3
    if (!bulkOut->XferData(data, bytesTransferred) || bytesTransferred != sizeof(data)) {
        fprintf(stderr, "Failed to send exposure time to FX3. Bytes transferred: %ld\n", bytesTransferred);
        return false;
    }

    printf("Exposure time set to FX3: %d\n", exposureTime);
    fflush(stdout);

    return true;
}

bool FPGAInterface::readBackExposureTimeFX3(CCyUSBDevice *usbDevice, int *readExposureTime) {
    if (!usbDevice || !usbDevice->IsOpen()) {
        fprintf(stderr, "FX3 device not connected or not open.\n");
        return false;
    }

    // Find the Bulk IN endpoint (0x81)
    CCyBulkEndPoint *bulkIn = (CCyBulkEndPoint *)usbDevice->EndPointOf(0x81);
    if (!bulkIn) {
        fprintf(stderr, "Bulk IN endpoint (0x81) not found.\n");
        return false;
    }

    bulkIn->Reset();  // Reset Bulk IN endpoint before reading

    unsigned char data[4] = {0};
    long bytesTransferred = sizeof(data);
    int maxRetries = 10;
    bool success = false;

    // Introduce a delay before polling to give FX3 firmware time to respond
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Delay to ensure firmware processes the OUT request

    for (int i = 0; i < maxRetries; ++i) {
        if (bulkIn->XferData(data, bytesTransferred)) {
            success = true;
            break;
        }
        fprintf(stderr, "Polling attempt %d: bytesTransferred=%ld\n", i + 1, bytesTransferred);
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Wait before retrying
    }

    if (!success) {
        fprintf(stderr, "Failed to read data from FX3. Endpoint: 0x81\n");
        return false;
    }

    // Convert received data to an integer
    *readExposureTime = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
    fprintf(stdout, "Read exposure time from FX3: %d\n", *readExposureTime);
    return true;
}
