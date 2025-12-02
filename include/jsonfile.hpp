#pragma once
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include <string>



class jsonfile {
private:
    using json = nlohmann::json;
    json jdata;
public:
    // Constructor que recibe filepath o nombre de archivo
    jsonfile(const std::string& filepath) {
        std::ifstream file(filepath);
        if (!file.is_open()) {
            std::cerr << "No se pudo abrir el archivo: " << filepath << "\n";
            return;
        }

        try {
            file >> jdata;
        } catch (json::parse_error& e) {
            std::cerr << "Error parseando JSON: " << e.what() << "\n";
        }
    }

    // Operador para acceder a elementos como diccionario
    json& operator[](const std::string& key) {
        return jdata[key];
    }

    // Método para acceder al json completo
    json& data() { return jdata; }

    // Verificar si la clave existe
    bool contains(const std::string& key) {
        return jdata.contains(key);
    }
};