#pragma once
#include <utility>          
#include <stdexcept>
#include <cmath>
namespace queen_attack {
class chess_board  {    
private:
    std::pair<int, int> white_queen_pos {0,0}; // Both queens given default positions
    std::pair<int, int> black_queen_pos {1,1};

    bool is_valid_pos(const std::pair<int, int>& pos);
    // Made simply to keep things clean below
    bool same_row()      const;
    bool same_column()   const;
    bool same_diagonal() const;
public:
    static constexpr int max_board_size { 7 }; // 0-7 = 8 size
    explicit chess_board(const std::pair<int, int>& white_pos, const std::pair<int, int>& black_pos) : 
    white_queen_pos{ white_pos }, black_queen_pos{ black_pos }
    {
        if (!is_valid_pos(white_queen_pos) || !is_valid_pos(black_queen_pos))
        { throw std::domain_error("Error: Both positions must be within the bounds of the board!"); }
        if (white_queen_pos == black_queen_pos) { throw std::domain_error("Error: 2 Pieces cannot occupy the same space!"); }
    }
    const std::pair<int, int>& white() const;
    const std::pair<int, int>& black() const;
    bool can_attack() const;
};
}  // namespace queen_attack