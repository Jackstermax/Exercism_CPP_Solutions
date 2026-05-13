#pragma once
#include <map>
#include <string>
#include <stdexcept>
namespace nucleotide_count {
char to_upper(char c);
bool valid_nucleotide(char c);   
std::map<char, int> count(const std::string& strand);
}  // namespace nucleotide_count