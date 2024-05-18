#include "/home/pedro/Desktop/driverRGBLED/rgbDriver.h"

rgbDevice::rgbDevice(){}

rgbDevice::~rgbDevice(){}

int rgbDevice::init(){
        LEDfd=open(LED_DEVICE_PATH, O_WRONLY);
        if(LEDfd<0){
                perror("Failed to open LED Device !\n");
                return -1;
        }
        return 0;
}

int rgbDevice::exit(){
        if(close(LEDfd)!=0){
                perror("Failed to close LED Device !\n");
                return -1;
        }
        return 0;
}

void rgbDevice::writeColor(int color){
        char buffer[2];
        buffer[0] = static_cast<char>(color + '0');
        buffer[1] = '\0';
        if(LEDfd<0){
                perror("Device not open !\n");
        }
        write(LEDfd,buffer,1);
}        

