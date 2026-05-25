#include "protein_translation.h"

namespace protein_translation {
std::vector<std::string> proteins(const std::string& protein_str){
    std::vector<std::string> prots_decoded {};
    if (protein_str.empty()) { return prots_decoded; }

    for (std::size_t i{0}; i < protein_str.size(); i += seq_len) {
        std::string prot_str { protein_str.substr(i, seq_len) };
        
        std::string acid_name {}; 
        for (const auto& key_pair : acid_keys) {
            auto found {std::find(key_pair.second.begin(), key_pair.second.end(), prot_str)};
            if (found != key_pair.second.end()) {
                acid_name = key_pair.first;
                break;
            } // If found a value, stop searching for a key             
        }
        if (acid_name.empty() || acid_name == "STOP") { break; } // Break/Disregard thereafter condition key or on bad data
        prots_decoded.emplace_back(acid_name);
    }
    return prots_decoded;
}    
}  // namespace protein_translation