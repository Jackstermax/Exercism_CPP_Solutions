#include "clock.h"

namespace date_independent {
    void clock::normalize_clock() {
        int total_mins = (hour * minutes_cap) + minute;
        // Handle total minutes to account for wrap-around
        total_mins = (total_mins % minutes_per_cycle + minutes_per_cycle) % minutes_per_cycle;

        hour   = total_mins / minutes_cap;
        minute = total_mins % minutes_cap;
    }

    clock& clock::plus  (const int mins) {
        minute += mins;
        normalize_clock();
        return *this;
    }
    clock& clock::minus (const int mins) {
        minute -= mins;
        normalize_clock();
        return *this;
    }

    clock clock::at(const int hours, const int mins) { 
        return {hours, mins};
    }

    clock::operator std::string() const { 
        int display_hour { _12_hour_format && hour == 0 ? 12 : hour}; // For 12-hour formatting

        std::ostringstream str {};
        str << (display_hour < 10 ? "0" : "") << display_hour;
        str << ":";
        str << (minute < 10 ? "0" : "") << minute;
        return str.str();
    }
    bool clock::operator==(const clock& c2) const { return hour == c2.hour && minute == c2.minute; }
    bool clock::operator!=(const clock& c2) const { return !(*this == c2); }

}  // namespace date_independent