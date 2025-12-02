// jsonfile.cpp
#include "jsonfile.hpp"
#include <fstream>
#include <iostream>

jsonfile::jsonfile(const std::string& filename) {
    std::ifstream f(filename);
    if (!f.is_open()) {
        std::cerr << "No se pudo abrir el archivo JSON: " << filename << "\n";
        return;
    }
    try {
        f >> j;
    } catch (std::exception& e) {
        std::cerr << "Error parseando JSON: " << e.what() << "\n";
    }
}

nlohmann::json& jsonfile::get() {
    return j;
}
