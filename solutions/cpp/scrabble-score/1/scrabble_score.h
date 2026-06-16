#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
namespace scrabble_score {

static const std::map<int, std::vector<char>> scores_table {
    {1,  {'A', 'E', 'I', 'O', 'U', 'L', 'N', 'R', 'S', 'T'}},
    {2,  {'D', 'G'}},
    {3,  {'B', 'C', 'M', 'P'}},
    {4,  {'F', 'H', 'V', 'W', 'Y'}},
    {5,  {'K'}},
    {8,  {'J', 'X'}},
    {10, {'Q', 'Z'}}
};

int get_score_val(char c);
int score(const std::string& word);
}  // namespace scrabble_score