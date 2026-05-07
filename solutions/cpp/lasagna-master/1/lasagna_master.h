#pragma once

#include <vector>
#include <string>

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

constexpr int noodle_grams_perLayer     { 50 };
constexpr double sauce_litres_perLayer  { 0.2 };

int preparationTime(const std::vector<std::string>& layers, int minsPerLayer = 2);
amount quantities  (const std::vector<std::string>& layers);

void addSecretIngredient(std::vector<std::string>& layers, const std::vector<std::string>& friend_layers);
void addSecretIngredient(std::vector<std::string>& layers, const std::string& grannies_ingredient);

std::vector<double> scaleRecipe(const std::vector<double>& quantities, int portions = 2);

}  // namespace lasagna_master
