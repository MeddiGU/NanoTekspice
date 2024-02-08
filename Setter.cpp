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

int Parser::path_into_vector(char *path)
{
    char buff;
    char stock[999];
    std::ifstream inFile;
    inFile.open(path);
    int i = 0;
    if (inFile.fail()) {
        std::cerr << "Parser: " << path << ": No such file or directory" << std::endl;
        exit (84);
    } else {
        buff = inFile.get();
        while (inFile.good()) {
            if (buff == '#') {
                while (buff != '\n' && buff != '\0') {
                    buff = inFile.get();
                }
            }
            stock[i] = buff;
            if (buff == '\n') {
                stock[i + 1] = '\0';
                i = -1;
                if (stock[1] != '\0' && stock[0] != '\0') {
                    vector.push_back(stock);
                }
            }
            buff = inFile.get();
            i++;
        }
    }
    return (0);
}

int Parser::vector_into_inputs()
{
    unsigned int i = 0;
    int z = 0;
    char token[99];
    char in[99];
    char *tmp = NULL;
    while (i < vector.size()) {
        strcpy(token, getVector()[i].c_str());
        tmp = strtok(token, " ");
        if (strcmp(tmp, "input") == 0) {
            tmp = strtok(NULL, " ");
            tmp[strlen(tmp) - 1] = '\0';
            inputs.push_back(tmp);
            inputs_temp.push_back(tmp);
        }
        i++;
    }
    std::sort(inputs.begin(), inputs.end());
    std::sort(inputs_temp.begin(), inputs_temp.end());
    return (0);
}

int Parser::vector_into_outputs()
{
    unsigned int i = 0;
    int z = 0;
    char token[99];
    char in[99];
    char *tmp = NULL;
    while (i < vector.size()) {
        strcpy(token, getVector()[i].c_str());
        tmp = strtok(token, " ");
        if (strcmp(tmp, "output") == 0) {
            tmp = strtok(NULL, " ");
            tmp[strlen(tmp) - 1] = '\0';
            outputs.push_back(tmp);
        }
        i++;
    }
    std::sort(outputs.begin(), outputs.end());
    return (0);
}

int Parser::vector_into_clocks()
{
    unsigned int i = 0;
    int z = 0;
    char token[99];
    char in[99];
    char *tmp = NULL;
    while (i < vector.size()) {
        strcpy(token, getVector()[i].c_str());
        tmp = strtok(token, " ");
        if (strcmp(tmp, "clock") == 0) {
            tmp = strtok(NULL, " ");
            tmp[strlen(tmp) - 1] = '\0';
            clocks.push_back(tmp);
        }
        i++;
    }
    std::sort(clocks.begin(), clocks.end());
    return (0);
}

int Parser::vector_into_falses()
{
    unsigned int i = 0;
    int z = 0;
    char token[99];
    char in[99];
    char *tmp = NULL;
    while (i < vector.size()) {
        strcpy(token, getVector()[i].c_str());
        tmp = strtok(token, " ");
        if (strcmp(tmp, "false") == 0) {
            tmp = strtok(NULL, " ");
            tmp[strlen(tmp) - 1] = '\0';
            falses.push_back(tmp);
        }
        i++;
    }
    std::sort(falses.begin(), falses.end());
    return (0);
}

int Parser::vector_into_trues()
{
    unsigned int i = 0;
    int z = 0;
    char token[99];
    char in[99];
    char *tmp = NULL;
    while (i < vector.size()) {
        strcpy(token, getVector()[i].c_str());
        tmp = strtok(token, " ");
        if (strcmp(tmp, "true") == 0) {
            tmp = strtok(NULL, " ");
            tmp[strlen(tmp) - 1] = '\0';
            trues.push_back(tmp);
        }
        i++;
    }
    std::sort(trues.begin(), trues.end());
    return (0);
}

int Parser::vector_into_alls()
{
    alls.insert(alls.end(), inputs.begin(), inputs.end());
    alls.insert(alls.end(), clocks.begin(), clocks.end());
    alls.insert(alls.end(), falses.begin(), falses.end());
    alls.insert(alls.end(), trues.begin(), trues.end());

    std::sort(alls.begin(), alls.end());
    return (0);
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
