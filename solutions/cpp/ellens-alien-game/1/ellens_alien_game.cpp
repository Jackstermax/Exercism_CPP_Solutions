#include <cmath>
#include <algorithm>

namespace targets {
// Insert the code for the alien class here
    class Alien {
    private:        
        int  m_health { 3 };
        bool m_shielded { false };
    public:
        // Really didn't wanna make these public, would have preferred Getters or a friend function for the check
        int  x_coordinate{ 0 };
        int  y_coordinate{ 0 }; 
    
        Alien(int x, int y) : x_coordinate{x}, y_coordinate{y}
        {}
        ~Alien() = default;
    
        // Getters
        int  get_health() const { return m_health;     }
        bool is_alive()   const { return m_health > 0; }
    
        bool hit(int damage = 1) // Damage argument is defaulted to 1, but if we want more damage we can specify the damage
        {       
            // checks if shields are up or if damage is negative (we don't want healing to happen here)
            if (damage < 0 || m_shielded) { return false; }  
            m_health -= damage;
            m_health = std::max(0, m_health);

            return true;
        }    

        bool collision_detection(const Alien& target) const
        {
            return x_coordinate == target.x_coordinate && y_coordinate == target.y_coordinate;
        }    
        bool teleport(int newX, int newY) 
        {
            // logically, we would detect collisions here before we teleport
            
            x_coordinate = newX;
            y_coordinate = newY;
            return true;    
        }
    };

}  // namespace targets
