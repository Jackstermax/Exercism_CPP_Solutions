#include "reverse_string.h"

namespace reverse_string {
std::string reverse_string(const std::string in_str) {
    std::string copy {in_str};
    std::reverse(copy.begin(), copy.end());     
    return copy;
}
    
}  // namespace reverse_string
