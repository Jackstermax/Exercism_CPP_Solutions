#pragma once
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
namespace date_independent {

class clock {
private:
    // Note: I added 12-hour functionality to this clock (minus am/pm) as an added fun-feature, that consideration is totally unnecessary for this exercise, though.
    static constexpr bool _12_hour_format  { false };
    static constexpr int hour_format       { _12_hour_format ? 12 : 24 };
    static constexpr int minutes_cap       { 60 };   
    static constexpr int minutes_per_cycle { hour_format * minutes_cap };

    int hour {};
    int minute {};

    void normalize_clock();
public:    
    // Constructor
    clock(int hours, int mins) : hour{hours}, minute{mins} {
        normalize_clock();
    }

    clock& plus  (const int mins);
    clock& minus (const int mins);
    static clock at(const int hours, const int mins);

    operator std::string() const;
    bool operator==(const clock& c2) const;
    bool operator!=(const clock& c2) const;
};
}  // namespace date_independent