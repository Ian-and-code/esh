// go.hpp
#pragma once
#include <string>
#include <vector>

struct Go {
    std::vector<std::string> aliases;
    std::vector<std::string> reals;
};

bool contains(const std::vector<std::string>& vec, const std::string& value);
