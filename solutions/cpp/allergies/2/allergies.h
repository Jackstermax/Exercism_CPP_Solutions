#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cctype>
namespace allergies {
class allergy_test {
private:   
    std::unordered_set<std::string> allergies_set {};
    
    static const std::unordered_map<std::string, int> allergen_names;
public:
    allergy_test(int score) {
        for (auto allergen : allergen_names)   {
             if ((score & allergen.second) == allergen.second) { allergies_set.insert(allergen.first); }    
        }            
    }    
    const std::unordered_set<std::string>& get_allergies() const;
    bool is_allergic_to(const std::string& allergen) const;
};    
}  // namespace allergies