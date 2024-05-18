#include "/home/pedro/Desktop/Pthreads/Scanner/Scanner.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string>

using namespace std;
int main() {
    Scanner myScanner;

    // Initialize the scanner
    myScanner.init();
   // myScanner.configPort();
   // sleep(1);
    // Read from the scanner
    myScanner.readScanner(); 
    // Get and print the code
    /*const uint8_t* code = myScanner.getCode();
    std::string barcode = myScanner.getString();
    
    std::cout << "Code: ";
    for (int i = 0; i < CODE_SIZE; ++i) {
        std::cout << std::hex << static_cast<int>(code[i]) << " ";
    }
    std::cout << std::endl;

    std::cout << "Barcode: " << barcode << std::endl;*/

    // Exit and close the scanner
    string stringMinha = myScanner.getString();
    cout << "String: " << stringMinha << endl;
    const uint8_t* codigo = myScanner.getCode();

		cout << "CODIGO ";
for (size_t i = 0; i < CODE_SIZE; ++i) {
    	cout << static_cast<char>(codigo[i]);
}
		cout << endl;
   myScanner.exit();

    return 0;
}
