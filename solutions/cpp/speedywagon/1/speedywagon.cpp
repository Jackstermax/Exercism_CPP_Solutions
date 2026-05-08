#include "speedywagon.h"

namespace speedywagon {

// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

// Enter your code below:
bool connection_check(const pillar_men_sensor* sensor) { return sensor != nullptr; }
int activity_counter(const pillar_men_sensor* sensor_array, std::size_t size)
{
    int activity_count {0};
    for (std::size_t i{0}; i < size; ++i)    {
        activity_count += sensor_array[i].activity;
    }
    return activity_count;
}

bool alarm_control(const pillar_men_sensor* sensor)
{
    if (sensor == nullptr) { return false; }
    return sensor->activity > 0;
}

bool uv_alarm(pillar_men_sensor* sensor)
{
    if (sensor == nullptr) { return false; }    
    return  uv_light_heuristic(&sensor->data) > sensor->activity;  
}

}  // namespace speedywagon
