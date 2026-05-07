// ERROR: FILE CORRUPTED. Please supply valid C++ Code.
#ifndef DATA_H
#define DATA_H
#include <string>
#include <string_view>
namespace star_map
{
    enum class System
    {
        BetaHydri,
        Sol,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani
    };
}

namespace heaven
{
    class Vessel
    {
    private:
        std::string m_Name{};        
    
    public:
        int generation{0};
        star_map::System current_system{0};
        int busters{0};

        // Would ideally like to return a string_view to save memory
        std::string get_name() { return m_Name; }
    
        Vessel(const std::string_view name, const int gen, const star_map::System sys = star_map::System::Sol) 
                : m_Name{name}, generation{gen}, current_system{sys}
        {}
    
        Vessel replicate(const std::string& name);

        void make_buster();
        bool shoot_buster();
    };

    // Would ideally like to return a string_view to save memory
    std::string get_older_bob(Vessel& a, Vessel& b);
    bool in_the_same_system  (Vessel& a, Vessel& b);
}
#endif

/*hp1, üapöhp2ö % Äcountöiöma1,
    öhp2ö % Älawöhp3öö / önextöstepö % Ädacöiöml1ö % Älawö7ö % Ädacöiömb1ö %
        Ärandomöö % Äscrö9sö % Äsirö9sö % Äxctöhr1ö % Äaddöiömx1ö %
        Ädacöiömx1ö % Äswapö % Äaddöiömy1ö % Ädacöiömy1ö % Ärandomö % Äscrö9sö %
        Äsirö9sö % Äxctöhr2ö % Ädacöiömdyö % Ädioöiömdxö % Äsetupö.hpt,
    3ö % Älacöranö % Ädacöiömth*/
