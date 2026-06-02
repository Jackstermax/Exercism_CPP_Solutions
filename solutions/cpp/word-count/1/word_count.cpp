#include "word_count.h"

namespace word_count {    
// Erase all unwanted punctuation, convert all to lower-case to make parsing easier
std::string& normalize_text(std::string& str) {   
    for (std::size_t i {0}; i < str.size(); ++i) {
        char& c {str[i]};
        unsigned char uc = static_cast<unsigned char>(c); // Just for ease-of-use when checking

        c = static_cast<char>(std::tolower(uc));
        if (std::isalnum(uc)) { continue; }         
        
        if (c == '\'') {  // Handling single quotes vs. apostrophes
            bool left  = (i > 0 && std::isalnum(static_cast<unsigned char>(str[i - 1])));
            bool right = (i + 1 < str.size() && std::isalnum(static_cast<unsigned char>(str[i + 1])));

            if (left && right) { continue; }                
        }
        c = ' '; 
    }
    return str;
}
    
std::map<std::string, int> words(const std::string& str) {
    std::map<std::string, int> count_log {};
    if (str.empty()) { return count_log; }    
    
    std::string normalized {str};
    normalize_text(normalized);
    
    std::string word{};
    std::stringstream sent_str {normalized};
    while (sent_str >> word) {        
        ++count_log[word];
    }   
    return count_log;
}
}  // namespace word_count