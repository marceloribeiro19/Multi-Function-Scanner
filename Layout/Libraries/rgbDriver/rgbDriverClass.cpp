#include "/home/pedro/Desktop/driverRGBLED/rgbDriver.h"
using namespace std;
#include <stdio.h>
#include <iostream>

int main(){
    rgbDevice rgb;
    if(rgb.init()==0){
         cout << "Openned Device" << endl;
    }
    else { cout << "ERROR !" << endl;};
    sleep(2);
    rgb.writeColor(0);  //off
    sleep(2);
    rgb.writeColor(1);  //todas on
    sleep(2);
    rgb.writeColor(2);  //vermelho
    sleep(2);
    rgb.writeColor(3);  //verde
    sleep(2);
    rgb.writeColor(4);  //azul
    
    rgb.exit();
    return 0;
}