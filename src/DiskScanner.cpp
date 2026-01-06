#include "DiskScanner.hpp"
#include <cstdint>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

std::vector<DiskInfo> DiskScanner::Scan(fs::path path) {
  std::cout << "INFO: DiskScanner::Scann is running \n";

  std::vector<DiskInfo> disks;
  // fs::path path = "bin/test.txt";

  std::cout << path.string() << std::endl;

  if (fs::exists(path)) {
    DiskInfo disk;
    std::cout << "FILE: " << path.filename() << " : " << fs::file_size(path)
              << std::endl;
  }

  return disks;
}
