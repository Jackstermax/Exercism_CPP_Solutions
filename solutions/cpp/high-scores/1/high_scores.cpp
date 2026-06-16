#include "high_scores.h"

#include <algorithm>

namespace arcade {

std::vector<int> HighScores::list_scores() {
    // Return all scores for this session.
    return this->scores;
}

int HighScores::latest_score() {
    // Return the latest score for this session.
    if (scores.size() <= 0) { return -1; }
    return scores.back();
}

int HighScores::personal_best() {
    // Return the highest score for this session.
    if (scores.size() <= 0) { return -1; } 
    std::vector<int> scores_temp {scores};
    std::sort(scores_temp.begin(), scores_temp.end());
    return scores_temp.back();
}

std::vector<int> HighScores::top_three() {
    // Return the top 3 scores for this session in descending order.
    std::vector<int> scores_temp {scores};    
    std::sort(scores_temp.begin(), scores_temp.end(), [](int a, int b) { return a > b; } );
    if (scores_temp.size() > 3) { scores_temp.resize(3); }    
    return scores_temp;
}
}  // namespace arcade
