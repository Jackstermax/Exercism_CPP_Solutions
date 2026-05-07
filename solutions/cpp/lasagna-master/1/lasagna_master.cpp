#include "lasagna_master.h"
#include <vector>
#include <string>

namespace lasagna_master 
{   
    int preparationTime(const std::vector<std::string>& layers, int minsPerLayer) {
        return layers.size() * minsPerLayer;
    }
    
    amount quantities(const std::vector<std::string>& layers) {
        int noodle_scalar {0};
        int sauce_scalar {0};
        for (std::size_t i {0}; i < layers.size(); ++i)
        {
            if (layers[i] == "noodles") { ++noodle_scalar; continue; }
            if (layers[i] == "sauce")   { ++sauce_scalar;  continue; }            
        }        
        
        int noodles_amt  { noodle_scalar * noodle_grams_perLayer };
        double sauce_amt { sauce_scalar * sauce_litres_perLayer };
        return amount{ noodles_amt, sauce_amt };
    }

    void addSecretIngredient(std::vector<std::string>& layers, const std::vector<std::string>& friend_layers) {
        layers.back() = friend_layers.back();
    }
    void addSecretIngredient(std::vector<std::string>& layers, const std::string& grannies_ingredient) {
        layers.back() = grannies_ingredient;
    }

    std::vector<double> scaleRecipe(const std::vector<double>& quantities, int portions)
    {
        double scalar { static_cast<double>(portions / 2.0) }; // Quantities array covers 2 portions so we scale by (portions/2.0)
        
        std::vector<double> new_ingredients {};
        for (double ingredient : quantities) {
            new_ingredients.emplace_back(ingredient * scalar);        
        }
        return new_ingredients;       
    }
    
}  // namespace lasagna_master
