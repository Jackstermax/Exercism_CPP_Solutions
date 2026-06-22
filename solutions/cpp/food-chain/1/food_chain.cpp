#include "food_chain.h"

namespace food_chain {    
std::string verse(int startNum) {
    std::string verse {};
    
    auto iter = lyrics.end();
    std::advance(iter, -startNum); // Iterate forwards, but push backwards based on verse number

    bool first_lyr {true};
    auto prev_iter {iter};
    while (iter != lyrics.end()) {    
        std::string lyric {};

        // Prefix and Subject
        lyric += first_lyr ? "I know an old lady who swallowed a " : "She swallowed the ";       
        lyric += (iter != prev_iter ? (prev_iter->first + " to catch the " + iter->first) : (iter->first));        
        
        // Suffix
        bool print_suffix {first_lyr || iter->second.always_print}; 
        bool spider_fix {!first_lyr && iter == (lyrics.end()-2)}; 
        lyric += spider_fix ? " " : ".\n";
        if (print_suffix) { 
            std::string suffix {iter->second.suffix};
            suffix = (spider_fix ? "that" + suffix.substr(2) : suffix);
            lyric += suffix + "\n"; 
        } 
        verse += lyric; 

        if (!first_lyr) { ++prev_iter; } // Keeps previous iteration one step behind  
        if (iter <= lyrics.begin()) { break; } // Handles horse case, end of the line.
        ++iter;
        first_lyr = false;        
    } 
    return verse;
}

std::string verses(int startNum, int endNum) {  
    if (startNum < 1 || startNum > static_cast<int>(lyrics.size())) { throw std::domain_error("Error: Lyric start point outside acceptable parameters."); }    
    if (endNum < 1 || endNum > static_cast<int>(lyrics.size()))     { throw std::domain_error("Error: Lyric end point outside acceptable parameters.");   } 
    if (endNum < startNum) { std::swap(startNum, endNum); }
    
    std::string result {};
    for (int i {startNum}; i <= endNum; ++i) {
        result += verse(i);
        result += "\n";
    }
    return result;
}

std::string sing() {
    return verses(1, 8);
}
}  // namespace food_chain