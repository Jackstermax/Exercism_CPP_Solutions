#include "bob.h"

namespace bob {
// Removes all whitespace so we can analyze clearly
std::string format_str(const std::string& str) {
    std::string format_str{str};
    format_str.erase(std::remove_if(format_str.begin(), format_str.end(), [](unsigned char c) { return std::isspace(c); }), format_str.end());
    return format_str;
}    
bool is_all_uppercase(const std::string& str) {
    bool hasAlpha {false};
    for (const char& c : str) {
        if (!std::isalpha(c)) { continue; }
        hasAlpha = true;
        if (c != static_cast<char>(std::toupper(static_cast<unsigned char>(c)))) { return false; }
    }
    return hasAlpha;
}
bool is_question(const std::string& str) { 
    if (str.empty()) { return false; }
    return str.back() == '?'; 
}
bool is_empty(const std::string& str) {
     return std::all_of(str.begin(), str.end(), [](unsigned char c) {
        return std::isspace(c);
    });
}
    
std::string hey(const std::string& str) {
    std::string input {format_str(str)};
    if (is_empty(input)) { return responses.at(ResponseType::SILENCE); }

    bool yelling     {is_all_uppercase(input)};
    bool questioning {is_question(input)};

    if (questioning) {
        if (yelling) { return responses.at(ResponseType::YELL_QUESTION); }
        return responses.at(ResponseType::QUESTION);
    }
    else if (yelling) { return responses.at(ResponseType::YELL); }
    
    return responses.at(ResponseType::DEFAULT);
}
}  // namespace bob