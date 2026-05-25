#include "allergies.h"

namespace allergies {
const std::unordered_map<std::string, int> allergy_test::allergen_names {
    {"eggs", 1},
    {"peanuts", 2},
    {"shellfish", 4},
    {"strawberries", 8},
    {"tomatoes", 16},
    {"chocolate", 32},
    {"pollen", 64},
    {"cats", 128}
};

const std::unordered_set<std::string>& allergy_test::get_allergies() const { return allergies_set; }    
bool allergy_test::is_allergic_to(const std::string& allergen) const {        
     // Convert input allergy word to lowercase for data uniformity 
    std::string allergen_lower { allergen };
    std::transform(allergen_lower.begin(), allergen_lower.end(), allergen_lower.begin(), [](unsigned char c) { return std::tolower(c); });

    return  allergies_set.find(allergen_lower) != allergies_set.end();  
}  
}  // namespace allergies