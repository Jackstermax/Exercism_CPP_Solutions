#pragma once
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
namespace rna_transcription {
char to_upper(char c);
char to_rna(const char c);
std::string to_rna(const std::string& strand);
}  // namespace rna_transcription