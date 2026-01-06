#ifndef DISKSCANNER_HPP
#define DISKSCANNER_HPP

#include <cstdint>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;
struct DiskInfo {
  std::string mount_point;
  std::string device_path;
  std::string filesystem_type;
  uint64_t total_space;
  uint64_t free_space;
  uint64_t available_space;
};

class DiskScanner {
public:
  DiskScanner() = default;
  ~DiskScanner() = default;
  std::vector<DiskInfo> Scan(fs::path path, long long total_mb);
};

#endif // DISKSCANNER_HPP
