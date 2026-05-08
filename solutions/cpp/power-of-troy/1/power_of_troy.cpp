#include "power_of_troy.h"

namespace troy {
    void give_new_artifact(human& human, const std::string& artifact_name) {
        human.possession = std::make_unique<artifact>(artifact_name);
    }

    void exchange_artifacts(std::unique_ptr<artifact>& a1, std::unique_ptr<artifact>& a2) {
        std::swap(a1, a2);       
    }

    void manifest_power(human& human, const std::string& power_name) {
        human.own_power = std::make_shared<power>(power_name);
    }

    void use_power(human& human1, human& human2) {
        if (human1.own_power == nullptr) { return; }
        human2.influenced_by = human1.own_power;
    }

    int power_intensity(human& human) {
        if (human.own_power == nullptr) { return 0; }
        return human.own_power.use_count();
    }
    
}  // namespace troy
