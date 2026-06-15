#include "crypto_square.h"

namespace crypto_square {
    std::string cipher::format_lower_depunctuate(std::string str) {
    str.erase(std::remove_if(str.begin(), str.end(), [](char c) { return !std::isalnum(c); }), str.end());
    for (char& c : str) { c = static_cast<char>(std::tolower(static_cast<unsigned char>(c))); }
    return str;
}
std::vector<std::vector<char>> cipher::box_message(const std::string& msg, int dim_x) {
    std::vector<std::vector<char>> boxed {}; 
    for (std::size_t i {0}; i < msg.size(); i+=dim_x) {
        std::string substr {msg.substr(i, dim_x)};             
        boxed.emplace_back(substr.begin(), substr.end());
    }        
    return boxed;
} 

std::string cipher::normalized_cipher_text() {
    std::string message_clean {message_raw};
    message_clean = format_lower_depunctuate(message_clean);
    if (message_clean.empty()) { return ""; }

    int limit_len {static_cast<int>(std::ceil(std::sqrt(message_clean.size())))};        

    std::string result {};
    std::vector<std::vector<char>> boxed_message {box_message(message_clean, limit_len)}; 

    for (std::size_t col{0}; col < static_cast<std::size_t>(limit_len); ++col) {
        std::string new_line {};
        for (std::size_t row{0}; row < boxed_message.size(); ++row) {
            bool has_char {col < boxed_message[row].size()};
            new_line.push_back(has_char ? boxed_message[row][col] : ' ');
        }
        if (col > 0) { result += " "; }
        result += new_line;
    }        
    return result;
}
}  // namespace crypto_square
