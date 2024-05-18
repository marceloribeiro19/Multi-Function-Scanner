/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>

#define SERIAL_PORT_PATH "/dev/ttyAMA0"
#define BUFF_SIZE 256
    
struct termios g_tty;
int g_fd;

// File operation functions
static int file_open_and_get_descriptor(const char *fname) {
    int fd;

    fd = open(fname, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd < 0) {
        perror("Could not open file");
    }
    return fd;
}

static int file_write_data(int fd, uint8_t *buff, uint32_t len_buff) {
    return write(fd, buff, len_buff);
}

static int file_read_data(int fd, uint8_t *buff, uint32_t len_buff) {
    return read(fd, buff, len_buff);
}

static int file_close(int fd) {
    return close(fd);
}

static void open_serial_port(void) {
    g_fd = file_open_and_get_descriptor(SERIAL_PORT_PATH);
    if (g_fd < 0) {
        perror("Something went wrong while opening the port");
        exit(EXIT_FAILURE);
    }
}

static void configure_serial_port(void) {
    if (tcgetattr(g_fd, &g_tty)) {
        perror("Something went wrong while getting port attributes");
        exit(EXIT_FAILURE);
    }

    cfsetispeed(&g_tty, B115200);
    cfsetospeed(&g_tty, B115200);

    cfmakeraw(&g_tty);
    g_tty.c_cflag |= CREAD;
    if (tcsetattr(g_fd, TCSANOW, &g_tty)) {
        perror("Something went wrong while setting port attributes");
        exit(EXIT_FAILURE);
    }
}
static void perform_loopback_test(void) {
    char tx_buff[BUFF_SIZE];
    char rx_buff[BUFF_SIZE];

    printf("Transmit Buffer:\n");
for (int i = 0; i < BUFF_SIZE; ++i) {
    printf("%02X ", tx_buff[i]);
}
printf("\n");

// Write data to UART
file_write_data(g_fd, tx_buff, BUFF_SIZE);

printf("Waiting for data to be transmitted...\n");
sleep(2); // 100,000 microseconds = 0.1 seconds

tcflush(g_fd, TCIOFLUSH);
// Read data from UART
int bytes_read = file_read_data(g_fd, rx_buff, BUFF_SIZE);
if (bytes_read != BUFF_SIZE) {
    perror("Error reading data from UART");
   //exit(EXIT_FAILURE);
}

printf("Receive Buffer:\n");
for (int i = 0; i < BUFF_SIZE; ++i) {
    printf("%02X ", rx_buff[i]);
}
printf("\n");

}

static void close_serial_port(void) {
    usleep(1000000);  // 1 second delay
    file_close(g_fd);
}

int main(void) {
    printf("Starting UART loopback test...\n");

    open_serial_port();
    if (g_fd < 0) {
    fprintf(stderr, "Invalid file descriptor\n");
    exit(EXIT_FAILURE);
}   
    configure_serial_port();

    perform_loopback_test();

    close_serial_port();

    return 0;
}*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#define SERIAL_PORT_PATH "/dev/ttyAMA0"
#define BUFF_SIZE 256

int main(void) {
    int fd;

    // Open the Port
    fd = open(SERIAL_PORT_PATH, O_RDWR | O_NOCTTY);
    if (fd == -1) {
        perror("open_port: Unable to open /dev/ttyS0 - ");
        return -1;
    }

    // Configure the port
    struct termios options;
    if (tcgetattr(fd, &options)) {
        perror("Something went wrong while getting port attributes");
        close(fd);
        return -1;
    }

    cfsetispeed(&options, B115200);
    cfsetospeed(&options, B115200);

    // Apply the modified options
    if (tcsetattr(fd, TCSANOW, &options)) {
        perror("Something went wrong while setting port attributes");
        close(fd);
        return -1;
    }

    // Write to the port
    const char* data_to_send = "Hello, Loopback Test!\n";
    if (write(fd, data_to_send, strlen(data_to_send)) == -1) {
        perror("Write failed - ");
        close(fd);
        return -1;
    }

    // Read from the port
    char buf[BUFF_SIZE];
    int bytes_read = read(fd, buf, sizeof(buf) - 1);
    if (bytes_read == -1) {
        perror("Read failed - ");
        close(fd);
        return -1;
    } else if (bytes_read == 0) {
        printf("No data received on port\n");
    } else {
        buf[bytes_read] = '\0';
        printf("%i bytes read: %s\n", bytes_read, buf);
    }

    // Closing
    close(fd);
    return 0;
}


