#include "grade_school.h"

namespace grade_school {
    void school::add(const std::string& name, const int grade) {
        student_roster[grade].emplace_back(name);  
        // Trigger a sort on the specified grade list when adding a new student
        std::sort(student_roster[grade].begin(), student_roster[grade].end(), 
            [](const std::string& a, const std::string& b) { return a < b; });
    }
    const std::vector<std::string>& school::grade(int grade)        const  { return student_roster.find(grade)->second; }
    const std::map<int, std::vector<std::string>>& school::roster() const  { return student_roster;        }    
}  // namespace grade_school