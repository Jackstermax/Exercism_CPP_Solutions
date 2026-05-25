#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
namespace protein_translation {
const int seq_len  = 3; 
const std::unordered_map<std::string, std::vector<std::string>> acid_keys {
    {"Methionine",    {"AUG"}},
    {"Phenylalanine", {"UUU", "UUC"}},
    {"Leucine",       {"UUA", "UUG"}},
    {"Serine",        {"UCU", "UCC", "UCA", "UCG"}},
    {"Tyrosine",      {"UAU", "UAC"}},
    {"Cysteine",      {"UGU", "UGC"}},
    {"Tryptophan",    {"UGG"}},
    {"STOP",          {"UAA", "UAG", "UGA"}}
};

std::vector<std::string> proteins(const std::string& protein_str);
}  // namespace protein_translation