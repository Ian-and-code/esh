// cd.cpp
#include "cd.hpp"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <limits.h>
#endif
#include <iostream>

bool cd(const std::wstring& path) {
#ifdef _WIN32
    if (SetCurrentDirectoryW(path.c_str())) return true;
    std::wcerr << L"Error cambiando directorio\n";
    return false;
#else
    if (chdir(std::string(path.begin(), path.end()).c_str()) == 0) return true;
    perror("chdir falló");
    return false;
#endif
}

std::wstring get_current_directory() {
#ifdef _WIN32
    wchar_t buffer[MAX_PATH];
    GetCurrentDirectoryW(MAX_PATH, buffer);
    return std::wstring(buffer);
#else
    char buffer[PATH_MAX];
    getcwd(buffer, sizeof(buffer));
    return std::wstring(buffer, buffer + strlen(buffer));
#endif
}
