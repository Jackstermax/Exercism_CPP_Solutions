#include "rna_transcription.h"

namespace rna_transcription {
char to_upper(char c) { return static_cast<char>(std::toupper(static_cast<unsigned char>(c))); } // For data filtering, probably not needed here. (Saftety measure)
char to_rna(const char c) {
    switch (to_upper(c)){
    case 'G': return 'C';
    case 'C': return 'G';
    case 'T': return 'A';
    case 'A': return 'U';  
    default: throw std::domain_error("No valid counterpart for neucleotide " + to_upper(c)); 
    }
}
std::string to_rna(const std::string& strand) {
    std::string rna (strand);
    for (char& c : rna)
        { c = to_rna(c); }
    return rna;
}
}  // namespace rna_transcription