#include "darts.h"

namespace darts {
int score(double x, double y) {
    double dist {std::abs(std::sqrt(std::pow(x, 2) + std::pow(y,2)))};
    if (dist > 10)                   { return 0;  }
    else if (dist > 5 && dist <= 10) { return 1;  }
    else if (dist > 1 && dist <= 5)  { return 5;  }
    else                             { return 10; }    
}
}  // namespace darts