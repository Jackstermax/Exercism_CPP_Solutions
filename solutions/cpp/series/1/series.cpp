#include "series.h"

namespace series {
std::vector<std::string> slice(const std::string& str, int step)    {    
    if (step > static_cast<int>(str.size()) || step <= 0) { throw std::domain_error("Invalid step and/or length parameters"); }     
    std::vector<std::string> series {};
    for (std::size_t i {0}; i <= str.size()-step; ++i) {
        try { // Note: this try/catch is for safety if we go out of bounds (bc I am paranoid), but is probably unnecessary
            std::string sub_str { str.substr(i, step)};
            series.emplace_back(sub_str);
        }
        catch(const std::exception& ex) { break; } 
    }          
    return series;
}
}  // namespace series