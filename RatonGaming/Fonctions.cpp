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

void removeSpaces(char *str)
{
    int length = strlen(str);
    int count = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ') {
            str[count++] = str[i];
        }
    }
    str[count] = '\0';
}

void revstr(char *chaine)
{
    int debut = 0;
    int fin = strlen(chaine) - 1;

    while (debut < fin) {
        char temp = chaine[debut];
        chaine[debut] = chaine[fin];
        chaine[fin] = temp;
        debut++;
        fin--;
    }
}

void Parser::display_vector(std::vector<std::string> vec)
{
    unsigned int z = 0;
    while (z < vec.size()) {
        std::cout << vec[z];
        if (z + 1 < vec.size()) {
            std::cout << " / ";
        }
        z++;
    }
    std::cout << "\n";
}
