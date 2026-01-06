#include "DiskScanner.hpp"
#include "HealthChecker.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  std::cout << "DiskChecker" << std::endl;

  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " <path>" << std::endl;
    return 1;
  }

  DiskScanner scanner;
  long long total_mb = std::stoll(argv[2]);
  scanner.Scan(argv[1], total_mb);

  return 0;
}
