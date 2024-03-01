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
    int error = 0, error_chipset = 0, error_links = 0;
    z = 0;
    while (z < vector.size()) {
        //printf("%s / ", vector[z].c_str());
        if (strcmp(vector[z].c_str(), ".chipsets:\n") == 0) {
            error_chipset = 84;
        }
        if (strcmp(vector[z].c_str(), ".links:\n") == 0) {
            error_links = 84;
        }
        z++;
    }
    if (error_chipset == 0) {
        std::cout << "No .chipsets" << std::endl;
    }
    if (error_links == 0) {
        std::cout << "No .links" << std::endl;
    }
    if (skip == 84 || error_chipset == 0 || error_links == 0) {
        exit (84);
    }
    return;
}

int isNum(std::string str)
{
    unsigned int z = 0;
    while (z < str.size()) {
        if (str[z] >= 48 && str[z] <= 57) {
            // Chiffre
        } else {
            // Pas chiffre
            return (84);
        }
        z++;
    }
    return (0);
}

void Parser::parsing_error()
{
    int error = 0;
    unsigned int z = 0, x = 0, nb = 0;
    char str[99];
    int i = 0;

    unsigned int y = 0, t = 0, compt = 0;
    while (y < vector.size()) {
        if (strcmp(vector[y].c_str(), ".links:\n") == 0) {
            y++;
            while (y < vector.size()) {
                while (vector[y][t] != '\0') {
                    if (vector[y][t] == ':') {
                        compt++;
                    }
                    t++;
                }
                if (compt != 2) {
                    std::cout << "No pin" << std::endl;
                    error = 84;
                }
                compt = 0;
                t = 0;
                y++;
            }
        }
        y++;
    }

    for (const auto& element : links) {
        if (std::find(total.begin(), total.end(), element) == total.end() && i%2 == 0) {
            std::cout << "A components name is unknown '" << element << "'" << std::endl;
            error = 84;
        }
        if (isNum(element) == 84 && i%2 != 0) {
            std::cout << "Invalid pin: '" << element << "'" << std::endl;
            error = 84;
        }
        if (element.empty()) {
            std::cout << "Missing Link: No pin" << std::endl;
            error = 84;
        }
        i++;
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
    if (others.size() > 0) {
        if (others[0] == "4001" && (inputs.size() != 8 || outputs.size() != 4)) {
            std::cout << "Crash avoid : 4001 sequenstrial" << std::endl;
            error = 84;
        }
    }
    if (error == 84) {
        exit (84);
    }
    return;
}
