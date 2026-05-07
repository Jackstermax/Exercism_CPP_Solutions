#include "vehicle_purchase.h"
#include <algorithm>

namespace vehicle_purchase {

// needs_license determines whether a license is needed to drive a type of
// vehicle. Only "car" and "truck" require a license.
bool needs_license(std::string kind) {
    // Return true if you need a license for that kind of vehicle.
    return kind == "car" || kind == "truck";
}

// choose_vehicle recommends a vehicle for selection. It always recommends the
// vehicle that comes first in lexicographical order.
std::string choose_vehicle(std::string option1, std::string option2) {
    // Return the final decision in a sentence.
    std::string result {(option1 < option2 ? option1 : option2) + " is clearly the better choice."};
    return result;
}

// calculate_resell_price calculates how much a vehicle can resell for at a
// certain age.
double calculate_resell_price(double original_price, double age) {
    // Return the age-corrected resell price.
    double resell_amt { original_price };                   
    if (age < 3)        { resell_amt *= 0.8; }
    else if (age < 10)  { resell_amt *= 0.7; }
    else                { resell_amt *= 0.5; }
    
    return resell_amt;
}

}  // namespace vehicle_purchase
