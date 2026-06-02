#include "matching_brackets.h"

namespace matching_brackets {
    
bool check(const std::string& str) {
    std::stack<char> output {};
    for (char c : str) {
        if (std::isblank(c)) { continue; }
        
        if (brackets.find(c) != brackets.end()) { output.push(c); } // New bracket open sequence.
        else {
            auto closing = std::find_if(brackets.begin(), brackets.end(), [&c](const std::pair<char,char>& pair) {
                return pair.second == c;
            });            

            if(closing != brackets.end()) {
                if (output.empty() || output.top() != closing->first) { return false; }
                output.pop();
            }           
        }
    }
    return output.empty();
}

}  // namespace matching_brackets