#include <iostream>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstring>
#include <algorithm>

#include "Parser.hpp"

void Parser::parsing_error_before()
{
    unsigned int z = 0, x = 0;
    int error = 0;
    while (z < vector.size()) {
        while (x < vector[z].size()) {
            if (vector[z][x] == ' ' || vector[z][x] == '.') {
                error = 84;
            }
            x++;
        }
        if (error == 0) {
            error = 84;
            break;
        }
        error = 0;
        x = 0;
        z++;
    }
    
    if (error == 84) {
        std::cout << "Invalid Syntax" << std::endl;
        exit (84);
    }
    return;
}

void Parser::parsing_error()
{
    int error = 0;
    unsigned int z = 0, x = 0, nb = 0;
    char str[99];
    for (const auto& element : links) {
        if (std::find(total.begin(), total.end(), element) == total.end()) {
            std::cout << "A components name is unknown '" << element << "'" << std::endl;
            error = 84;
        }
    }

    while (z < total.size()) {
        while (x < total.size()) {
            if (total[z] == total[x]) {
                strcpy(str, total[x].c_str());
                nb++;
            }
            x++;
        }
        if (nb > 1) {
            std::cout << "Several components share the same name :'" << str << "'" << std::endl;
            error = 84;
            break;
        }
        nb = 0;
        x = 0;
        z++;
    }
    
    if (error == 84) {
        exit (84);
    }
    return;
}
