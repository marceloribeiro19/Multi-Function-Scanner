#include "/home/pedro/Desktop/Pthreads/Scanner/Scanner.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <sys/select.h>
#include <cstring>

/**
 * @brief Default constructor for the Scanner class.
 */
Scanner::Scanner(){}

/**
 * @brief Default destructor for the Scanner class.
 */
Scanner::~Scanner(){}

/**
 * @brief Initializes the scanner by opening the corresponding serial port file.
 * @return 0 on success, -1 on failure.
 */
void Scanner::init(){
    if(open_config_port()!=0){
        perror("Error opening file...\n");
        return;
    }
}

/**
 * @brief Exits and cleans up resources by closing the serial port file.
 * @return 0 on success, -1 on failure.
 */
int Scanner::exit(){
    if(close(fd)!=0){
        perror ("Error closing device ... \n");
        return -1;
    }
    return 0;
}

/**
 * @brief Opens and configures the serial port.
 * @return 0 on success, -1 on failure.
 */
int Scanner::open_config_port() {
    fd = open(SERIAL_PORT_PATH, O_RDWR | O_NOCTTY);
    if(fd < 0) {
        printf("Could not open file %s...%d\r\n",SERIAL_PORT_PATH,fd);
        return fd;
    }
    //Configure Serial Port
    if(tcgetattr(fd, &g_tty)) {
        perror("Something went wrong while getting port attributes...\r\n");
        close(fd);
        return -1;
    }
    //configure the input and output baudrate
    cfsetispeed(&g_tty,B9600);
    cfsetospeed(&g_tty,B9600);
    //raw mode
    cfmakeraw(&g_tty);

    //minimum character read and wait time
    g_tty.c_cc[VMIN] = 0;
    g_tty.c_cc[VTIME] = 60;

    //stop bits, no rts/cts, ignore CD signal ,enable receive.
    g_tty.c_cflag &= ~CSTOPB;
    g_tty.c_cflag &= ~CRTSCTS;
    g_tty.c_cflag |= CLOCAL | CREAD;
    //apply the changes to the serial port
    if(tcsetattr(fd,TCSANOW,&g_tty) < 0) {
        perror("Something went wrong while setting port attributes...\r\n");
        close(fd);
        return -1;
    }
    return 0;
}

/**
 * @brief Reads data from the scanner, including the scan command and actual code.
 */
void Scanner::readScanner() {
    uint8_t buff[BUFF_SIZE];
    //write the scan command
    if (write(fd, scan, SCAN_COMMAND_SIZE) < 0) {
        perror("Error writing to UART1");
        return;
    }
    //read the scanner's response
    memset(buff, 0, BUFF_SIZE);
    if (read(fd, buff, BUFF_SIZE) < 0){
        perror("Error reading from UART2");
        return;
    }
    // read the 256 byte buffer
    memset(buff, 0, BUFF_SIZE);
    if (read(fd, buff, BUFF_SIZE) < 0){
        perror("Error reading from UART3");
        return;
    }
    //get the actual code
    for (int i = 0; i < CODE_SIZE; ++i) {
        code[i] = buff[i];
    }
}

/**
 * @brief Getter function for the scanner code.
 * @return Pointer to constant data representing the scanner code.
 */
const uint8_t* Scanner::getCode() const{
    return code;
}

/**
 * @brief Getter function for the scanner code as a string.
 * @return String representation of the scanner code.
 */
std::string Scanner::getString() const{
    std::string barcode((char*)code, CODE_SIZE);
    return barcode;
}
