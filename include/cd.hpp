#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <limits.h>
#endif

// cd
#ifdef _WIN32
bool cd(const std::wstring& path) {
    if (SetCurrentDirectoryW(path.c_str())) {
        return true;
    } else {
        std::wcerr << L"Error cambiando directorio\n";
        return false;
    }
}
#else
bool cd(const std::string& path) {
    if (chdir(path.c_str()) == 0) {
        return true;
    } else {
        perror("chdir falló");
        return false;
    }
}
#endif

// get_current_directory
#ifdef _WIN32
std::wstring get_current_directory() {
    wchar_t buffer[MAX_PATH];
    GetCurrentDirectoryW(MAX_PATH, buffer);
    return std::wstring(buffer);
}
#else
std::string get_current_directory() {
    char buffer[PATH_MAX];
    getcwd(buffer, sizeof(buffer));
    return std::string(buffer);
}
#endif

int main() {
#ifdef _WIN32
    std::wcout << L"Directorio actual: " << get_current_directory() << L"\n";
#else
    std::cout << "Directorio actual: " << get_current_directory() << "\n";
#endif
}
