#include "space_age.h"

namespace space_age {    
    long   space_age::seconds()    const { return m_time; }
    // v Standard calculation function, plug n' play. :)
    double space_age::calc_time_normalized(double planet_year_seconds) const { return m_time / planet_year_seconds; }  
    
    double space_age::on_mercury() const { return calc_time_normalized(mercury_year_sec); }   
    double space_age::on_venus()   const { return calc_time_normalized(venus_year_sec);   }
    double space_age::on_earth()   const { return calc_time_normalized(earth_year_sec);   }
    double space_age::on_mars()    const { return calc_time_normalized(mars_year_sec);    }
    double space_age::on_jupiter() const { return calc_time_normalized(jupiter_year_sec); }
    double space_age::on_saturn()  const { return calc_time_normalized(saturn_year_sec);  }
    double space_age::on_uranus()  const { return calc_time_normalized(uranus_year_sec);  }
    double space_age::on_neptune() const { return calc_time_normalized(neptune_year_sec); }    
}  // namespace space_age