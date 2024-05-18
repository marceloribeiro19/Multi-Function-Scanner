#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>


#define SERIAL_PORT_PATH        "/dev/ttyAMA0"
#define SCAN_COMMAND_SIZE 9
#define BUFF_SIZE 256
#define CODE_SIZE 8

struct termios g_tty;
int g_fd;

// FILE OPERATION
static int file_open_and_get_descriptor(const char *fname) {
    int fd;

    fd = open(fname, O_RDWR | O_NONBLOCK);
    if(fd < 0) {
        printf("Could not open file %s...%d\r\n",fname,fd);
    }
    return fd;
}

static int file_write_data(int fd, uint8_t *buff, uint32_t len_buff) {
    return write(fd,buff,len_buff);
}

static int file_read_data(int fd, uint8_t *buff, uint32_t len_buff) {
    return read(fd,buff,len_buff);
}

static int file_close(int fd) {
    return close(fd);
}


static void open_serial_port(void) {
    g_fd = file_open_and_get_descriptor(SERIAL_PORT_PATH);
    if(g_fd < 0) {
        printf("Something went wrong while opening the port...\r\n");
        exit(EXIT_FAILURE);
    }
}

static void configure_serial_port(void) {
    if(tcgetattr(g_fd, &g_tty)) {
        printf("Something went wrong while getting port attributes...\r\n");
        exit(EXIT_FAILURE);
    }

    cfsetispeed(&g_tty,B9600);
    cfsetospeed(&g_tty,B9600);

    cfmakeraw(&g_tty);

    if(tcsetattr(g_fd,TCSANOW,&g_tty)) {
        printf("Something went wrong while setting port attributes...\r\n");
        exit(EXIT_FAILURE);
    }
}

static void perform_demo(void) {
    uint8_t l_buff[256];
    uint32_t l_len_buff = 256;
    uint32_t l_looper;
    
    for(l_looper=0; l_looper<l_len_buff; ++l_looper)
        l_buff[l_looper] = l_looper;

    file_write_data(g_fd,l_buff,l_len_buff);
    sleep(1);
    memset(l_buff,0,l_len_buff);
    file_read_data(g_fd,l_buff,l_len_buff);

    for(l_looper=0; l_looper<l_len_buff; ++l_looper) {
        printf("%02x",l_buff[l_looper]);
        if(l_buff[l_looper] != l_looper) {
        printf("\r\nSomething went wrong in the loopback data check...%d and %d\r\n",l_buff[l_looper],l_looper) ;
            exit(EXIT_FAILURE);
        }
    }
    printf("\r\nThe data loopback was successful!\r\n");
}

static void close_serial_port(void) {
    file_close(g_fd);
}
/*
void readScanner(){
 uint8_t buff[BUFF_SIZE];
uint8_t code[8];
uint8_t scan[SCAN_COMMAND_SIZE]={0x7E,0x00,0x08,0x01,0x00,0x02,0x01,0xAB,0xCD}; //HEAD1 HEAD1 TYPES WRITEOPP ADDRESS ADDRESS DATA NOCRC NOCRC
     /*for(int l_looper=0; l_looper<=9; l_looper++) {
        printf("%x",scan[l_looper]);
        if(scan[l_looper] != l_looper) {
        printf("\r\nSomething went wrong in the loopback data check...%d and %d\r\n",scan[l_looper],l_looper) ;
            exit(EXIT_FAILURE);
        }
    //WRITE SCAN COMMAND
    write(g_fd,scan, SCAN_COMMAND_SIZE);
    usleep(10000);
    //READ THE RESPONSE 
    memset(buff,0,BUFF_SIZE);
    usleep(10000);
    read(g_fd,buff,BUFF_SIZE);

    sleep(5);

    //READ THE CODE VALUE
    memset(buff,0,BUFF_SIZE);
    usleep(10000);
    if (read(g_fd, buff, CODE_SIZE) != CODE_SIZE) {
    perror("Error reading from serial port");
    exit(EXIT_FAILURE);
    }

    
    for(int l_looper=0; l_looper<256; ++l_looper) {
        printf("%02x\n",buff[l_looper]);
    }
    
    for (int i = 0, j = 7; i < 8 && j < BUFF_SIZE; ++i, ++j) {
        code[i] = buff[j];
        printf("%x", buff[j]);
        }  

    printf("NOW THE CODE\n");
        for (int i = 0; i < CODE_SIZE; ++i) {
            //std::cout << std::hex << static_cast<int>(code[i]) << " ";
            printf("%02x\n", code[i]);
            //printf("%x", buff[i]);
        }
}
*/
void readScanner() {
    uint8_t buff[BUFF_SIZE];
    uint8_t code[CODE_SIZE];
    uint8_t scan[SCAN_COMMAND_SIZE] = {0x7E, 0x00, 0x08, 0x01, 0x00, 0x02, 0x01, 0xAB, 0xCD};

    // WRITE SCAN COMMAND
    if (write(g_fd, scan, SCAN_COMMAND_SIZE) != SCAN_COMMAND_SIZE) {
        perror("Error writing to serial port");
        exit(EXIT_FAILURE);
    }

    // SLEEP OR ADD DELAY HERE IF NEEDED

    // READ THE RESPONSE
    memset(buff, 0, BUFF_SIZE);
    ssize_t bytesRead = 0;
    while (bytesRead < BUFF_SIZE) {
        ssize_t result = read(g_fd, buff + bytesRead, BUFF_SIZE - bytesRead);
        if (result == -1) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                // No data available yet, continue the loop or sleep and retry
                usleep(10000);  // Adjust the sleep duration as needed
                continue;
            } else {
                // Handle other errors
                perror("Error reading from serial port");
                exit(EXIT_FAILURE);
            }
        } else if (result == 0) {
            // End of file reached (e.g., if the serial port is closed)
            perror("End of file reached");
            exit(EXIT_FAILURE);
        } else {
            // Successfully read some data
            bytesRead += result;
        }
    }

    // SLEEP OR ADD DELAY HERE IF NEEDED

    // READ THE CODE VALUE
    memset(buff, 0, BUFF_SIZE);
    bytesRead = 0;
    while (bytesRead < CODE_SIZE) {
        ssize_t result = read(g_fd, buff + bytesRead, CODE_SIZE - bytesRead);
        if (result == -1) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                // No data available yet, continue the loop or sleep and retry
                usleep(10000);  // Adjust the sleep duration as needed
                continue;
            } else {
                // Handle other errors
                perror("Error reading from serial port");
                exit(EXIT_FAILURE);
            }
        } else if (result == 0) {
            // End of file reached (e.g., if the serial port is closed)
            perror("End of file reached");
            exit(EXIT_FAILURE);
        } else {
            // Successfully read some data
            bytesRead += result;
        }
    }

    // Process the received data as needed
    // ...

    // Print or use the received data
    for (int i = 0; i < CODE_SIZE; ++i) {
        printf("%02x\n", buff[i]);
    }
}




int main(void) {
    printf("Starting the loopback application...\r\n");

    open_serial_port();

    configure_serial_port();

    sleep(5);
    //readScanner();

    perform_demo();

    close_serial_port();

    return 0;
}