#include <iostream>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstring>
#include <string>

#include "Parser.hpp"

void Parser::display()
{
    int i = 0;

    std::cout << "tick: " << getTick() << std::endl;

    //components.find("in_1")->second->;

    std::cout << "input(s):" << std::endl;
    while (i < getAll().size()) {
        std::cout << "  " << getAll()[i] << ": ";
        if (getStatement() == 0) {
            std::cout << "0" << std::endl;
        } else if (getStatement() == 1) {
            std::cout << "1" << std::endl;
        } else if (getStatement() == 2) {
            std::cout << "U" << std::endl;
        }
        i++;
    }
    i = 0;
    std::cout << "output(s):\n";
    while (i < getOutputs().size()) {
        std::cout << "  " << getOutputs()[i] << ": ";
        if (getStatement() == 0) {
            std::cout << "0" << std::endl;
        } else if (getStatement() == 1) {
            std::cout << "1" << std::endl;
        } else if (getStatement() == 2) {
            std::cout << "U" << std::endl;
        }
        i++;
    }
}

void Parser::simulate()
{
    // apply values set with the = sign
    unsigned int z = 0;
    char *debut = NULL;
    char *fin = NULL;
    std::string temp;
    while (z < egal.size()) {
        temp = egal[z];
        debut = strtok(const_cast<char*>(temp.data()), "=");
        fin = const_cast<char*>(egal[z].data());
        fin = strtok(NULL, "=");
        if (fin[0] != '1' && fin[0] != '0') {
            strcpy(fin, "U");
        }
        // if (debut != NULL && fin != NULL) {
        //     exit (0);
        // }
        z++;
    }

    // increase the tick by 1
    tick += 1;
}
