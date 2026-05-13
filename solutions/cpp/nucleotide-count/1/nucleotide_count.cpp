#include "nucleotide_count.h"

namespace nucleotide_count {
char to_upper(char c) { return static_cast<char>(std::toupper(static_cast<unsigned char>(c))); } // Uppercase conversion, for convenience    
bool valid_nucleotide(char c) { 
    char c_copy {to_upper(c)};
    return c_copy == 'A' || c_copy == 'C' || c_copy == 'G' || c_copy == 'T';
}    
std::map<char, int> count(const std::string& strand) {
    std::map<char, int> counts { {'A', 0 }, {'C', 0 }, {'G', 0 }, {'T', 0 }};
    for (std::size_t i {0}; i < strand.size(); ++i) {
        if (!valid_nucleotide(strand[i])) { throw std::invalid_argument("Invalid nucleotuide contained within strand!"); }  
        counts.emplace(strand[i], ++(counts[strand[i]]));
    }
    return counts;
}
}  // namespace nucleotide_count