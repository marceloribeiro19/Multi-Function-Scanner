#ifndef MLX90614_H
#define MLX90614_H

#include <linux/i2c-dev.h>
#include <linux/i2c.h>

constexpr int MLX90614_I2CADDR=0x5A;
constexpr const char* I2C_DEV_PATH="/dev/i2c-1";
constexpr char command=0x06; // command 0x06 is reading thermopile sensor

class MLX90614{
public:
    MLX90614();
    ~MLX90614();

    int init();
    int exit();
    void readTemperature(); //setter
    double getTemperature() const; //getter

private:
    typedef union i2c_smbus_data i2c_data;
    i2c_data data;
    int fd;
    double temperature=0;

    int openI2C();
    int setSlaveAddress();
    int enableCheckSum();
    int readData(i2c_smbus_data& data, char command);
};
#endif
