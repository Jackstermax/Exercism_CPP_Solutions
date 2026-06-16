#include "scrabble_score.h"

namespace scrabble_score {
int get_score_val(char c) {
    char c_upper = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
    auto iter {std::find_if(scores_table.begin(), scores_table.end(), 
    [&c_upper](const std::pair<int, std::vector<char>>pair)
    {
        return std::find(pair.second.begin(), pair.second.end(), c_upper) != pair.second.end(); 
    })};
    return iter->first;
}
    
int score(const std::string& word) {
    int total {0};
    for (const char c : word) {
        int letter_score {get_score_val(c)};
        if (letter_score <= 0) { continue; }
        total += letter_score;
    }
    return total;
}
}  // namespace scrabble_score