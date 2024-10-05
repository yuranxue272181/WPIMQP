#include "usbinterface.h"
#include <iostream>

//Constructor
USBInterface::USBInterface(uint16_t vendor_id, uint16_t product_id, uint8_t endpoint_in)
    : vendor_id(vendor_id), product_id(product_id), endpoint_in(endpoint_in), device(nullptr), bulkIn(nullptr) {}

// Destructor
USBInterface::~USBInterface() {
    closeUSB();  // Ensure USB connection is closed when the object is destroyed
}

// Initialize USB communication with the FPGA
bool USBInterface::initializeUSB() {
    // Initialize the Cypress USB device
    device = new CCyUSBDevice(NULL);

    // Open the Cypress USB device
    if (device->DeviceCount() > 0) {
        device->Open(0);  // Open the first connected device

        if (!device->IsOpen()) {
            std::cerr << "Could not open Cypress USB device." << std::endl;
            return false;
        }

        // Get the bulk IN endpoint
        bulkIn = device->BulkInEndPt;
        if (!bulkIn) {
            std::cerr << "Bulk IN endpoint not found." << std::endl;
            return false;
        }

        return true;
    } else {
        std::cerr << "No Cypress USB device found." << std::endl;
        return false;
    }
}
