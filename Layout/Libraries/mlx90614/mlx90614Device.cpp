#include "/home/pedro/Desktop/Pthreads/mlx90614/mlx90614.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

using namespace std;


int main(void) {
    MLX90614 mlx90614Device;
    double temperature;
    mlx90614Device.init();
    //sleep(5);
    mlx90614Device.readTemperature();
    temperature=mlx90614Device.getTemperature();
    cout << "Temp Value: " << mlx90614Device.getTemperature() << endl;
    return 0;
}
