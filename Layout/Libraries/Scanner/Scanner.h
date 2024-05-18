#ifndef SCANNER_H
#define SCANNER_H

#include <termios.h>
#include <stdint.h>
#include <string>

constexpr const char* SERIAL_PORT_PATH="/dev/ttyAMA0";
constexpr int SCAN_COMMAND_SIZE=9;
constexpr int BUFF_SIZE=256;
constexpr int CODE_SIZE=8;

class Scanner {
public:
    Scanner();
    ~Scanner();
    void init();
    int exit();
    //Scanner Operations
    void readScanner();
    const uint8_t* getCode() const;
    std::string getString() const;
    
private:
    struct termios g_tty;
    int fd;
    uint8_t code[CODE_SIZE];
    //HEAD1 HEAD1 TYPES WRITEOPP ADDRESS ADDRESS DATA NOCRC NOCRC
    uint8_t scan[SCAN_COMMAND_SIZE]={0x7E,0x00,0x08,0x01,0x00,0x02,0x01,0xAB,0xCD};
    int open_config_port();
};
#endif
