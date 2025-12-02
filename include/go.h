#include "jsonfile.hpp"
#include "cd.hpp"
#include "simpletypes.h"
#include "wstr-str.h"
#include "includes.h"
#ifdef _WIN32
#include <windows.h>
#endif
bool go(str path) {
    jsonfile f("config.json");
    auto go = f["go"];
    const auto aliases = go["aliases"];
    if(aliases.contains(path)) {
        try {
            wstr alias = utf8_to_wstring(aliases[path]);
            cd(alias);
            return true;
        } catch(const char* _){}
    } else {
        try {
            cd(utf8_to_wstring(path));
            return true;
        } catch(const char* _){}
    }
    #ifdef _WIN32
    std::wcerr << L"alias o ruta no encontado\n";
    #else
    perror("alias o ruta no encontado\n");
    #endif
    return false;
}
