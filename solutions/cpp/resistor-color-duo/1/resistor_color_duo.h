#pragma once
#include <vector>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>  
#include <cmath>
namespace resistor_color_duo {
static const std::map<int, std::string> colour_vals 
{          
    {0, "black" },          
    {1, "brown" },          
    {2, "red"   },          
    {3, "orange"},          
    {4, "yellow"},          
    {5, "green" },          
    {6, "blue"  },          
    {7, "violet"},          
    {8, "grey"  },
    {9, "white" }   
};  
int color_code(const std::string& colour);
int value(const std::vector<std::string>& colours);
}  // namespace resistor_color_duo