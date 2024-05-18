#ifndef RGBDRIVER_H
#define RGBDRIVER_H

//#include "/home/pedro/Desktop/driverRGBLED/utils.h"
#include <termios.h>
#include <stdint.h>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <cstdio>
#include <cerrno>

#define DEVICE_NAME "rgbDevice"
#define CLASS_NAME "rgbledClass"
#define LED_DEVICE_PATH "/dev/rgbDevice"



class rgbDevice {
    public:
        rgbDevice();
        ~rgbDevice();

        int init();
        int exit();
        void writeColor(int color);

    private:
        int LEDfd;
        struct GpioRegisters *s_pGpioRegisters;
        //PINOS LED
        static const int LedGpioPinR = 17;
        static const int LedGpioPinG = 27;
        static const int LedGpioPinB = 22;
};

#endif
