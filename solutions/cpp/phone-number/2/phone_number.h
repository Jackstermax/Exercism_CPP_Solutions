#pragma once
#include <string>
#include <algorithm>
#include <stdexcept>
#include <cctype>
namespace phone_number {
class phone_number {
private:
    std::string m_phone_number {};
public:
    phone_number(const std::string& in_num);
    const std::string& number() const;
};
}  // namespace phone_number