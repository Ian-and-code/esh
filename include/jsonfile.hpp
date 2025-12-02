
#pragma once
#include <string>
#include <nlohmann/json.hpp>

class jsonfile {
private:
    nlohmann::json j;
public:
    jsonfile(const std::string& filename);
    nlohmann::json& get();
};
