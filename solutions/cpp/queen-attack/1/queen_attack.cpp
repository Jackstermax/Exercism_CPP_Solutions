#include "queen_attack.h"

namespace queen_attack {
    //private (chess_board)
    bool chess_board::is_valid_pos(const std::pair<int, int>& pos) { 
        return ((pos.first  >= 0 && pos.first  <= chess_board::max_board_size) 
             && (pos.second >= 0 && pos.second <= chess_board::max_board_size));
    }
    bool chess_board::same_row()      const { return white_queen_pos.first == black_queen_pos.first;   }
    bool chess_board::same_column()   const { return white_queen_pos.second == black_queen_pos.second; }
    bool chess_board::same_diagonal() const { 
        int x_diff {std::abs(white_queen_pos.first - black_queen_pos.first)};
        int y_diff {std::abs(white_queen_pos.second - black_queen_pos.second)};
        return x_diff == y_diff;
    }
    
    //public (chess_board)
    const std::pair<int, int>& chess_board::white() const { return white_queen_pos; }
    const std::pair<int, int>& chess_board::black() const { return black_queen_pos; }
    bool chess_board::can_attack() const {
        return white_queen_pos != black_queen_pos 
            && (same_row() || same_column() || same_diagonal());
    }
}  // namespace queen_attack
