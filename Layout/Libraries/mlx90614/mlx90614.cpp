#include "/home/pedro/Desktop/Pthreads/mlx90614/mlx90614.h"

#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Default constructor for the MLX90614 class.
 */
MLX90614::MLX90614(){}

/**
 * @brief Default destructor for the MLX90614 class.
 */
MLX90614::~MLX90614(){}

/**
 * @brief Initializes the MLX90614 sensor by opening the I2C interface, setting the slave address, and enabling checksum.
 * @return 0 on success, non-zero on failure.
 */
int MLX90614::init(){
    if(openI2C()!=0){
        perror("Error opening I2C...\n");
        return 1;
    }
    if(setSlaveAddress()!=0){
        perror("Error defining slave address...\n");
        return 2;
    }
    if(enableCheckSum()!=0){
        perror("Error enabling checksum...\n");
        return 3;
    }
    return 0;
}

/**
 * @brief Cleans up resources and closes the I2C interface.
 * @return 0 on success, -1 on failure.
 */
int MLX90614::exit(){
    if(close(fd)!=0){
        fprintf(stderr, "Failed to close I2C interface %s Error: %s\n", I2C_DEV_PATH, strerror(errno));
        return -1;
    }
    return 0;
}

/**
 * @brief Opens the I2C interface.
 * @return 0 on success, -1 on failure.
 */
int MLX90614::openI2C(){
    fd = open(I2C_DEV_PATH, O_RDWR); // open i2c bus
    if (fd < 0) {
        fprintf(stderr, "Failed to open I2C interface %s Error: %s\n", I2C_DEV_PATH, strerror(errno));
        return -1;
    }
    return 0;
}

/**
 * @brief Sets the slave address for the MLX90614 sensor.
 * @return 0 on success, -1 on failure.
 */
int MLX90614::setSlaveAddress(){
    if (ioctl(fd, I2C_SLAVE, MLX90614_I2CADDR) != 0) {
        fprintf(stderr, "Failed to select I2C slave device! Error: %s\n", strerror(errno));
        return -1;
    }
    return 0;
}

/**
 * @brief Enables checksum for the MLX90614 sensor.
 * @return 0 on success, -1 on failure.
 */
int MLX90614::enableCheckSum(){
    if (ioctl(fd, I2C_PEC, 1) != 0) {
        fprintf(stderr, "Failed to enable SMBus packet error checking, error: %s\n", strerror(errno));
        return -1;
    }
    return 0;
}

/**
 * @brief Reads data from the MLX90614 sensor using I2C_SMBUS transaction.
 * @param data Reference to i2c_smbus_data structure.
 * @param command I2C command to read data.
 * @return 0 on success, -1 on failure.
 */
int MLX90614::readData(i2c_smbus_data& data, char command){
    // Build request structure
    struct i2c_smbus_ioctl_data sdat = {
        .read_write = I2C_SMBUS_READ,
        .command = command,
        .size = I2C_SMBUS_WORD_DATA,
        .data = &data
    };

    // Perform the actual request
    if (ioctl(fd, I2C_SMBUS, &sdat) < 0) {
        return -1;
    }
    return 0;
}

/**
 * @brief Reads the temperature from the MLX90614 sensor.
 */
void MLX90614::readTemperature(){
    if (readData(data, command)!=0) {
        fprintf(stderr, "Failed to perform I2C_SMBUS transaction, error: %s\n", strerror(errno));
        return;
    }
    temperature = (double) data.word;
    temperature = (temperature * 0.02) - 0.01;
    temperature = temperature - 278.15;
}

/**
 * @brief Gets the temperature from the MLX90614 sensor.
 * @return The temperature in Celsius.
 */
double MLX90614::getTemperature() const{
    return temperature;
}
