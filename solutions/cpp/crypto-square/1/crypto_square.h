#ifndef CRYPTO_SQUARE_H
#define CRYPTO_SQUARE_H

#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <vector>
namespace crypto_square {
class cipher {
private:
    std::string message_raw {};
    
    std::string format_lower_depunctuate(std::string str);
    std::vector<std::vector<char>> box_message(const std::string& msg, int dim_x); 
public:
    cipher(const std::string& msg) : message_raw{msg} {}
    std::string normalized_cipher_text();
};
}  // namespace crypto_square
#endif