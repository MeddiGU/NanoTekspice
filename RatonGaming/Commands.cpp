#include <iostream>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstring>

#include "Parser.hpp"

void Parser::display()
{
    int i = 0;

    std::cout << "tick: " << getTick() << std::endl;
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
    tick += 1;
}