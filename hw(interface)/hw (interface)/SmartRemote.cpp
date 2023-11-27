#include "SmartRemote.h"

void SmartRemote::printDevice(IDevice* device) const
{
    if (device != nullptr) {
        cout << "Your device >> " << device->getName() << endl;
    }
    else {
        cout << "No device selected." << endl;
    }

}
