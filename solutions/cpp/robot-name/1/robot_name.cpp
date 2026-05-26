#include "robot_name.h"

namespace robot_name {
static std::unordered_set<std::string> robot_registry {}; // Ensures no dupes
static constexpr int prefix_len = 2;
static constexpr int suffix_len = 3;
    
char gen_randchar() {
    std::random_device dev;          
    std::mt19937 rand_gen(dev());

    std::uniform_int_distribution<> char_distr('A', 'Z'); 
    return char_distr(rand_gen);
}
char gen_randnum() {
    std::random_device dev;          
    std::mt19937 rand_gen(dev());

    std::uniform_int_distribution<> digt_distr('0', '9'); 
    return digt_distr(rand_gen);
}

bool in_registry (const std::string& name) { return robot_registry.find(name) == robot_registry.end(); }
void add_name    (const std::string& name) { robot_registry.insert(name); }
void erase_name  (const std::string& name) { robot_registry.erase(name);  }
    
std::string generate_name() {
    std::string generated_name {};
    do {
        generated_name.clear(); // reset each iteration before we append new elements
        for (int i {0}; i < prefix_len; ++i) { generated_name.push_back(gen_randchar()); }
        for (int j {0}; j < suffix_len; ++j) { generated_name.push_back(gen_randnum());  }           
    } while (!(generated_name.empty()) && !in_registry(generated_name));

    add_name(generated_name);
    return generated_name;
}

// robot Class Functions
std::string robot::name() const { return m_name; }
void robot::reset() {         
    erase_name(m_name);
    m_name = generate_name();
}

}  // namespace robot_name