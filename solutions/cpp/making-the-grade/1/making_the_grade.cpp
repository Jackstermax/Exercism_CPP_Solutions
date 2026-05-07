#include <array>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    // Implement round_down_scores
    std::vector<int> scoresInt{};
    for (double d : student_scores)
        scoresInt.emplace_back(static_cast<int>(d));
    return scoresInt;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    // Implement count_failed_students
    int failed {0};
    for (int i : student_scores)
        if (i <= 40) {++failed;}
    return failed;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    // Implement letter_grades
    int grade_BracketAmt { (highest_score-40) / 4 };
    assert (grade_BracketAmt > 0);
    
    std::array<int, 4> gradesThresh {
        41, 
        41 + grade_BracketAmt,  
        41 + 2 * grade_BracketAmt, 
        41 + 3 * grade_BracketAmt
    };
    return gradesThresh;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(std::vector<int> student_scores, std::vector<std::string> student_names) {
    // Implement student_ranking
    assert (student_scores.size() == student_names.size()); //for safety, could alternatively be handled via exception
    
    std::vector<std::pair<std::string, int>> reg_Scores{}; // a list of registered scores to their respective students
    for (std::size_t i {0} ; i < student_scores.size(); ++i)    {
        reg_Scores.emplace_back(student_names[i], student_scores[i]);
    }

    // Sort by the score value (descending) while still keeping student name affiliated with the value
    // Using a lambda expression as our sort criteria, using auto to keep it a bit nicer to read, instead of const std::pair<std::string, int>& a...
    std::sort(reg_Scores.begin(), reg_Scores.end(),  
    [](const auto& a, const auto& b)
    {
        return a.second > b.second;
    });

    // Output here conveniently using the pair, after accessing via index
    std::vector<std::string> rankedGrades_Out {};
    for(std::size_t j {0}; j < reg_Scores.size(); ++j)
    {
        rankedGrades_Out.emplace_back(std::to_string(j+1) + ". " + reg_Scores[j].first + ": " + std::to_string(reg_Scores[j].second));
    }    
    return rankedGrades_Out;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names) {
    // Implement perfect_score
    assert (student_scores.size() == student_names.size()); //for safety, could alternatively be handled via exception
        
    for (std::size_t i {0}; i < student_scores.size(); ++i)
        if (student_scores[i] == 100) {return student_names[i];}        
    
    return "";
}
