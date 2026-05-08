#include "leap.h"

namespace leap 
{
    bool is_leap_year(int year)  {
        int abs_year { std::abs(year) }; // For case of negative number inserted
        switch(abs_year % 100 == 0)  {
            case true: return abs_year % 400 == 0;                
            default:   return abs_year % 4 == 0;               
        }
    }
}  // namespace leap