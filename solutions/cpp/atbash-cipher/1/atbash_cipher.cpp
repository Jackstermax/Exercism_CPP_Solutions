#include "atbash_cipher.h"

namespace atbash_cipher {
char convert_char (char c) { 
    if (std::isalpha(c))  { return 'a' + 'z' - (static_cast<char>(std::tolower(static_cast<unsigned char>(c)))); } // Uniform all lowercase output
    else if (std::isdigit(c)) { return c; }           // Do nothing, keep the same
    else                      { return skip_marker; } // Skip marker, defined in 'atbash_cipher.h'
}
    
std::string encode(const std::string& str) {
    std::string out_str {};

    int chargrp_counter {0};
    for (char c : str)   {
        c = convert_char(c);
        if (c == skip_marker) { continue; } // If a space is encountered, skip
                
        if (chargrp_counter >= max_chars_grouped) { chargrp_counter = 0; out_str.push_back(' '); }  
        ++chargrp_counter; // Space insert to separate groups of encoded chars
        
        out_str.push_back(c);
    }
    return out_str;
}
    
std::string decode(const std::string& str) {
    std::string out_str { };    
    for (char c : str)   {
        c = convert_char(c);
        if (c == skip_marker) { continue; } // If a space is encountered, skip        
        out_str.push_back(c);        
    }
    return out_str;
}
}  // namespace atbash_cipher