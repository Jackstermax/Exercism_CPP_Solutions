#pragma once
#include <map>
#include <algorithm>
#include <string>
#include <cctype>
namespace bob {
enum class ResponseType {
    QUESTION,
    YELL,
    YELL_QUESTION,
    SILENCE,
    DEFAULT
};
inline const std::map<ResponseType, std::string> responses {
    {ResponseType::QUESTION,        "Sure."},
    {ResponseType::YELL,            "Whoa, chill out!"},
    {ResponseType::YELL_QUESTION,   "Calm down, I know what I'm doing!"},
    {ResponseType::SILENCE,         "Fine. Be that way!"},
    {ResponseType::DEFAULT,         "Whatever."}
};

std::string format_str(const std::string& str);
bool is_all_uppercase(const std::string& str);
bool is_question(const std::string& str);
bool is_empty(const std::string& str);    
std::string hey(const std::string& input);
}  // namespace bob
