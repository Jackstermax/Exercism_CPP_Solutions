#pragma once

namespace space_age {
    static constexpr double earth_year_sec   { 31557600.0 };
    static constexpr double mercury_year_sec { earth_year_sec * 0.2408467  };
    static constexpr double venus_year_sec   { earth_year_sec * 0.61519726 };    
    static constexpr double mars_year_sec    { earth_year_sec * 1.8808158  };
    static constexpr double jupiter_year_sec { earth_year_sec * 11.862615  };
    static constexpr double saturn_year_sec  { earth_year_sec * 29.447498  };
    static constexpr double uranus_year_sec  { earth_year_sec * 84.016846  };
    static constexpr double neptune_year_sec { earth_year_sec * 164.79132  };
    
    class space_age {
    private:
    long m_time {0};
    
    public:
        explicit space_age(long time_seconds) : m_time{time_seconds}
        {}
    
        long seconds() const;
        double calc_time_normalized(double planet_year_seconds) const;
    
        double on_mercury() const;   
        double on_venus()   const;
        double on_earth()   const;
        double on_mars()    const;
        double on_jupiter() const;
        double on_saturn()  const;
        double on_uranus()  const;
        double on_neptune() const;
    };
}  // namespace space_age