#include <iostream>
#include "DiskScanner.hpp"
#include "HealthChecker.hpp"

int main(int argc, char *argv[]) {
    std::cout << "DiskChecker" << std::endl;

    if(argc < 2) {
        std::cout << "Usage: " << argv[0] << " <path>" << std::endl;
        return 1;
    }

    DiskScanner scanner;
    scanner.Scan(argv[1]);    

    return 0;
}
