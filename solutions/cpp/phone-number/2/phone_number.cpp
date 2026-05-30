#include "phone_number.h"

namespace phone_number {
phone_number::phone_number(const std::string& in_num) {
    for (char c : in_num) {
        if (std::isdigit(c)) { m_phone_number.push_back(c); }
    }        

    // Handling invalid phone number lengths, country codes
    if (m_phone_number.size() > 11 || m_phone_number.size() < 10) { throw std::domain_error("Error: Invalid phone number length."); }
    else if (m_phone_number.size() == 11) {
        if (m_phone_number[0] == '1') { m_phone_number.erase(0,1); } // Remove the country code if valid.
        else { throw std::domain_error("Error: Invalid country code."); }        
    }

    // Note: we cut-off the country code before we test area and exchange code so we don't need to differ for 10 or 11 length number cases.   
    std::string area_code     {m_phone_number.substr(0,3)};
    if (area_code[0] == '0' || area_code[0] == '1') { throw std::domain_error("Error: Invalid area code."); }
    
    std::string exchange_code {m_phone_number.substr(3,3)};
    if (exchange_code[0] == '0' || exchange_code[0] == '1') { throw std::domain_error("Error: Invalid exchange code."); }
}

const std::string& phone_number::number() const { return m_phone_number; }
}  // namespace phone_number