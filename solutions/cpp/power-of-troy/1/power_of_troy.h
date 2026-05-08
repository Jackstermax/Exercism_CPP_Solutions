#ifndef POWER_OF_TROY_H
#define POWER_OF_TROY_H

#include <string>
#include <memory>
#include <utility>

namespace troy {

struct artifact {
    // constructors needed (until C++20)
    artifact(std::string name) : name(name) {}
    std::string name;
};

struct power {
    // constructors needed (until C++20)
    power(std::string effect) : effect(effect) {}
    std::string effect;
};

class human
{
public:
    human() = default;    
    std::unique_ptr<artifact>  possession    {};
    std::shared_ptr<power>     own_power     {};
    std::shared_ptr<power>     influenced_by {};   // This is dangerous! Use std::weak_ptr instead! (I had used that originally to avoid circular dependencies, but the compiler doesn't like that :^[ )
};

void give_new_artifact(human& human, const std::string& artifact_name);
void exchange_artifacts(std::unique_ptr<artifact>& a1, std::unique_ptr<artifact>& a2);
void manifest_power(human& human, const std::string& power_name);
void use_power(human& human1, human& human2);
int power_intensity(human& human);

}  // namespace troy
#endif