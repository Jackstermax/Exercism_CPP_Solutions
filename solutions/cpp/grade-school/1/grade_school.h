#pragma once

#include <map>
#include <vector>
#include <algorithm>
#include <string>
namespace grade_school {    
    class school {
    private:
        std::map<int, std::vector<std::string>> student_roster{};    
    public: 
        school() = default;
        void add(const std::string& name, const int grade);
        const std::vector<std::string>& grade(int grade) const;
        const std::map<int, std::vector<std::string>>& roster() const;        
    };
}  // namespace grade_school