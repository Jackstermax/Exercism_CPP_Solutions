#include "kindergarten_garden.h"

namespace kindergarten_garden {
std::array<Plants, 4> plants(const std::string& rows, const std::string& name) {    
    auto iter {std::find(class_list.begin(), class_list.end(), name)};    
    if (iter == class_list.end()) { throw std::domain_error("Error: Student not found in class"); }
    std::size_t index {static_cast<std::size_t>(pots_per_row * std::abs(std::distance(iter, class_list.begin())))}; // Corrects for pots per row if kept adjacent
    
    std::string line {};
    std::stringstream s_str {rows};
    std::string plants_symbols {};
    while (s_str >> line) { 
        plants_symbols += (line.substr(index, pots_per_row)); 
    }        

    std::array<Plants, 4> student_plants {};
    for (std::size_t i{0}; i < student_plants.size(); ++i) {
        char c = plants_symbols[i];
        student_plants[i] = (plants_dict.at(c));
    }
    return student_plants;
}    
}  // namespace kindergarten_garden