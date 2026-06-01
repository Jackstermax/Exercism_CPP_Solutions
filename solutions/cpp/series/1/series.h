#pragma once
#include <string>
#include <vector>
#include <stdexcept>
namespace series {
std::vector<std::string> slice(const std::string& str, int step);
}  // namespace series