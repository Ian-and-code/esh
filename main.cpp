#include <iostream>
#include "jsonfile.hpp"
#include "cd.hpp"
#include "split.h"
#include <vector>
#include "simpletypes.h"
#include "go.h"
int main(int argc, char *argv[]) {
    using std::cout;
    using std::wcout;
    using std::cin;
    if(argc == 1) {
        while (true) {
            str command;
            wcout << get_current_directory() << L" $ " << L'\n';
            cin >> command;
            vector<str> cmd = split(command, ' ');
            if(cmd[0] == (str)"go") {go(cmd[1]);}
            else if(cmd[0] == (str)"ls") {system("ls");}
            else {system(command.c_str());}
        }
    } else {
        std::cerr << "esh no necesita args para ejecutarse\n";
    }
    return 0;
}