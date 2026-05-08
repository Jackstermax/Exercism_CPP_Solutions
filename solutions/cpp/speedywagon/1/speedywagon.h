#pragma once

#include <string>
#include <vector>

namespace speedywagon {

struct pillar_men_sensor {
    int activity{};
    std::string location{};
    std::vector<int> data{};
};
int uv_light_heuristic(const std::vector<int>* data_array);

bool connection_check(const pillar_men_sensor* sensor);
int activity_counter(const pillar_men_sensor* sensor_array, std::size_t size);
bool alarm_control(const pillar_men_sensor* sensor);
bool uv_alarm(pillar_men_sensor* sensor);

}  // namespace speedywagon
