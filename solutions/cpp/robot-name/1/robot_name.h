#pragma once
#include <string>
#include <unordered_set>
#include <random>

namespace robot_name {  
std::string generate_name();
    
class robot {
private:
    std::string m_name {};

public:
    robot() {
        m_name = robot_name::generate_name();
    };

    std::string name() const;
    void reset();
};
}  // namespace robot_name