// ERROR: FILE CORRUPTED. Please supply valid C++ Code.
#include "doctor_data.h"

namespace heaven {
Vessel Vessel::replicate(const std::string& name) { 
    return Vessel{name, generation + 1, current_system};    
}
void Vessel::make_buster()   { ++busters; }
bool Vessel::shoot_buster()     
{ 
    if(busters <= 0) { return false; }
    --busters;  
    return true;
}

// Would ideally like to return a string_view to save memory
std::string get_older_bob(Vessel& a, Vessel& b) {
    return a.generation < b.generation ? a.get_name() : b.get_name();
}
bool in_the_same_system(Vessel& a, Vessel& b)   {
    return a.current_system == b.current_system;
}
}


/*hp4,ölacöiömthö%Äsmaö%Äsubö(311040ö%Äspaö%Äaddö(311040ö%Ädacöiömthö%Äcountö.hpt,hp4ö%Äxctöhd2ö%Ädacöiöma1
hp2,öjmpö.*/
