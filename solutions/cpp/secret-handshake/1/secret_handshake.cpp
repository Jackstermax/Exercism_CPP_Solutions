#include "secret_handshake.h"

namespace secret_handshake {
std::vector<std::string> commands(int x) {
    std::vector<std::string> actions {};
    std::bitset<5> bits { static_cast<unsigned long>(x) }; // Convert to bitmask to extract commands.

    if (x <= 0) { return actions; } // If 0 is passed-in, there is no handshake. :^(
    bool reverse_order { bits.test(4) };
    
    if (bits.test(0)) { actions.emplace_back("wink");            }
    if (bits.test(1)) { actions.emplace_back("double blink");    }
    if (bits.test(2)) { actions.emplace_back("close your eyes"); }
    if (bits.test(3)) { actions.emplace_back("jump");            }    
    
    if (reverse_order) { std::reverse(actions.begin(), actions.end()); }
    return actions;
}
}  // namespace secret_handshake