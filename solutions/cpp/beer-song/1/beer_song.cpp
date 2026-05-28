#include "beer_song.h"

namespace beer_song {
// Value replacement helper function
std::string& replace_value(std::string& phrase, const std::string& target, const std::string& value) {
    if (target.empty()) { return phrase; } // Safeguard against infinite looping
    
    std::size_t pos{0};
    while ((pos = phrase.find(target, pos)) != std::string::npos) {
        phrase.replace(pos, target.length(), value);
        pos += value.length();
    }
    return phrase;
}
    
std::string verse(const int verse_num) {
    int bottles { std::clamp(verse_num , 0, max_bottles_from_da_liqa_sto)};   

    // Verse First part:
    std::string verse_part1  {"# bottles of beer on the wall, # bottles of beer.\n"};
    std::string number_part1 { bottles > 0 ? std::to_string(bottles) : "no more" };
    
    verse_part1 = replace_value(verse_part1, "#", number_part1);
    
    if (bottles == 1) { replace_value(verse_part1, "bottles", "bottle"); }
    if (bottles <= 0) { verse_part1[0] = std::toupper(verse_part1[0]); } // Uppercase first replacement for 0 bottles case

    // Verse Second Part
    std::string verse_part2 { bottles > 0 ? "Take # down and pass it around, " : "Go to the store and buy some more, "};
    std::string noun_part2 { bottles > 1 ? "one" : "it"};
    verse_part2 = replace_value(verse_part2, "#", noun_part2);

    // Verse Third Part
    int new_bottles { bottles-1 >= 0 ? bottles-1 : max_bottles_from_da_liqa_sto };
    std::string verse_part3 { "# bottles of beer on the wall.\n" };
    std::string number_part3 { new_bottles > 0 ? std::to_string(new_bottles) : "no more" };
    
    verse_part3 = replace_value(verse_part3, "#", number_part3);
    if (new_bottles == 1) { replace_value(verse_part3, "bottles", "bottle"); }   

    return verse_part1 + verse_part2 + verse_part3;
}

std::string sing(const int start, const int end) {
    std::string result {};
    
    int i {start};
    while (i >= end) {
        if (i < start) { result += "\n"; } 
        result += verse(i);
        --i;
    }
    return result;
}
}  // namespace beer_song