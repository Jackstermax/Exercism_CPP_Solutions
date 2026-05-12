#include "raindrops.h"

namespace raindrops {
    std::string convert(int number) {
        bool div3 { false }; 
        bool div5 { false }; 
        bool div7 { false };

        std::string result {""};
        if (number % 3 == 0) { result += "Pling"; div3 = true; }
        if (number % 5 == 0) { result += "Plang"; div5 = true; }
        if (number % 7 == 0) { result += "Plong"; div7 = true; } 

        if (!div3 && !div5 && !div7) { result = std::to_string(number); }
        return result;
    }
}  // namespace raindrops