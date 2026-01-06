#include "DiskScanner.hpp"
#include <chrono>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace fs = std::filesystem;

std::vector<DiskInfo> DiskScanner::Scan(fs::path path, long long total_mb) {
  std::cout << "INFO: DiskScanner::Scann is running \n";

  std::vector<DiskInfo> disks;
  // fs::path path = "bin/test.txt";

  std::cout << path.string() << std::endl;

  if (fs::exists(path)) {
    DiskInfo disk;
    std::cout << "FILE: " << path.filename() << " : " << fs::file_size(path)
              << std::endl;
  }

  std::string filename{path};

  long long bytes_per_mb = 1024 * 1024;

  std::vector<char> buffer(bytes_per_mb, 'A');

  std::cout << "INFO : Writing " << total_mb << "MB to " << filename
            << "... \n";

  auto start = std::chrono::high_resolution_clock::now();

  std::ofstream outFile(filename, std::ios::binary);
  if (!outFile) {
    throw std::runtime_error("ERROR: Could not open file " + filename);
  }

  for (int i = 0; i < total_mb; ++i) {
    outFile.write(buffer.data(), buffer.size());
  }

  outFile.flush();
  outFile.close();

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;

  double seconds = diff.count();
  double speed = total_mb / seconds;

  std::cout << "Finished in : " << seconds << " seconds. \n";
  std::cout << "Write speed : " << speed << " MB/s" << "\n";
  return disks;
}
