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

int Parser::vector_into_others()
{
    unsigned int i = 0;
    int z = 0, y = 0, t = 0, error = 0;
    char token[99];
    char in[99];
    char *tmp = NULL;
    char *temp = NULL;

    while (y < vector.size() && t == 0) {
        if (strcmp(vector[y].c_str(), ".chipsets:\n") == 0) {
            t = 1;
        }
        y++;
    }
    i = y;

    while (i < vector.size()) {
        strcpy(token, getVector()[i].c_str());
        tmp = strtok(token, " ");
        if (vector[i][0] == '.') {
            break;
        }
        if (strcmp(tmp, "and") == 0 || strcmp(tmp, "or") == 0 || strcmp(tmp, "xor") == 0 || strcmp(tmp, "not") == 0 || strcmp(tmp, "logger") == 0 ||
            strcmp(tmp, "4001") == 0 || strcmp(tmp, "4011") == 0 || strcmp(tmp, "4030") == 0 || strcmp(tmp, "4069") == 0 || strcmp(tmp, "4071") == 0 ||
            strcmp(tmp, "4081") == 0 || strcmp(tmp, "4008") == 0 || strcmp(tmp, "4013") == 0 || strcmp(tmp, "4017") == 0 || strcmp(tmp, "4040") == 0 ||
            strcmp(tmp, "4094") == 0 || strcmp(tmp, "4512") == 0 || strcmp(tmp, "4514") == 0 || strcmp(tmp, "4801") == 0 || strcmp(tmp, "2716") == 0) {
            tmp = strtok(NULL, " ");
            tmp[strlen(tmp) - 1] = '\0';
            others.push_back(tmp);
        } else if (strcmp(tmp, "input") == 0 || strcmp(tmp, "output") == 0 || strcmp(tmp, "clock") == 0 || strcmp(tmp, "false") == 0 || strcmp(tmp, "true") == 0) {
            // empty
        } else {
            std::cout << "A components type is unknown '" << tmp << "'" << std::endl;
            error = 84;
        }
        i++;
    }
    if (error == 84) {
        exit (84);
    }
    std::sort(others.begin(), others.end());
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

int Parser::vector_into_total()
{
    total.insert(total.end(), alls.begin(), alls.end());
    total.insert(total.end(), outputs.begin(), outputs.end());
    total.insert(total.end(), others.begin(), others.end());

    std::sort(total.begin(), total.end());
    return (0);
}

int Parser::vector_into_links()
{
    int dec = 0;
    int y = 0, t = 0;
    unsigned int z = 0, x = 0;
    int valid = 0;
    char temp[99];

    while (y < vector.size() && t == 0) {
        if (strcmp(vector[y].c_str(), ".links:\n") == 0) {
            t = 1;
        }
        y++;
    }
    x = y;

    while (x < vector.size()) {
        while (z < vector[x].size()) {
            if (vector[x][z] == ':') {
                while (vector[x][z - dec] != ' ' && z - dec != 0) {
                    temp[dec] = vector[x][z - dec - 1];
                    dec++;
                }
                temp[dec] = '\0';
                removeSpaces(temp);
                revstr(temp);
                links.push_back(temp);
            }
            dec = 0;
            z++;
        }
        z = 0;
        x++;
    }
    std::sort(links.begin(), links.end());
    return (0);
}
