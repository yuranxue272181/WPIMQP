#ifndef USBINTERFACE_H
#define USBINTERFACE_H

//#include <libusb-1.0/libusb.h>
#include <CyAPI.h>
#include <vector>
#include <cstdint>

class USBInterface {
public:
    // Constructor and destructor
    USBInterface(uint16_t vendor_id, uint16_t product_id, uint8_t endpoint_in);
    ~USBInterface();

    // Method to initialize the USB connection
    bool initializeUSB();

    // Method to pull image data from the FPGA
    // bool pullImageData(std::vector<unsigned char>& buffer, int timeout = 1000);
    bool pullImageData(std::vector<UCHAR>& buffer, UCHAR endpointAddr, int timeout = 1000);

    // Method to close the USB connection
    void closeUSB();

private:
    uint16_t vendor_id;
    uint16_t product_id;
    uint8_t endpoint_in;

    CCyUSBDevice* device;  // CyAPI device handle
    CCyBulkEndPoint* bulkIn;  // Bulk IN endpoint for data transfer
};

#endif // USBINTERFACE_H
