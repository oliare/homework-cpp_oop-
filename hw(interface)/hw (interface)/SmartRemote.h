#pragma once
#include <conio.h>
#include <vector>
#include "TV_AirCond.h"
using std::endl;
using std::cout;
using std::vector;

enum keys
{
    ENTER = 13, UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77, ESC = 27
};

class SmartRemote
{
    vector<IDevice*> devices;
    IDevice* currentDevice;

public:
    SmartRemote(IDevice* device)
        : currentDevice(device)
    {}

    void addDevice(IDevice* newone) {
        devices.push_back(newone);
    }

    void setCurrentDevice(IDevice* newone) {
        currentDevice = newone;
    }

    void printDevice() const {
        if (currentDevice != nullptr) {
            cout << "\nCurrent device >>> " << currentDevice->getName();
            currentDevice->showInfo();
        }
        else {
            cout << "- no device selected -" << endl;
        }
    }

    void testDevice()
    {
        while (true)
        {
            int s = _getch();

            if (s == keys::ESC) {
                break;
            }
            else if (s >= '1' && s <= '3') {
                size_t index = s - '1';
                if (index < devices.size()) {
                    currentDevice = devices[index];
                    printDevice();
                }
            }
            else if (currentDevice != nullptr) {
                switch (s)
                {
                case ENTER:
                    currentDevice->power(); break;
                case UP:
                    currentDevice->next(); break;
                case DOWN:
                    currentDevice->prev(); break;
                case LEFT:
                    currentDevice->minus(); break;
                case RIGHT:
                    currentDevice->plus(); break;
                }
            }
        }
    }
};


