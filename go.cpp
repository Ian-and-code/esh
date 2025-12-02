// go.cpp
#include "go.hpp"

bool contains(const std::vector<std::string>& vec, const std::string& value) {
    for (const auto& v : vec) {
        if (v == value) return true;
    }
    return false;
}
