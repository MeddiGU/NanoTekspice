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
    std::cout << "input(s):" << std::endl;
    while (i < getAll().size()) {
        std::cout << "  " << getAll()[i] << ": ";
        if (components[getAll()[i]]->getValue() == nts::Tristate::False) {
            std::cout << "0" << std::endl;
        } else if (components[getAll()[i]]->getValue() == nts::Tristate::True) {
            std::cout << "1" << std::endl;
        } else if (components[getAll()[i]]->getValue() == nts::Tristate::Undefined) {
            std::cout << "U" << std::endl;
        }
        i++;
    }
    i = 0;
    std::cout << "output(s):\n";
    while (i < getOutputs().size()) {
        std::cout << "  " << getOutputs()[i] << ": ";
        if (components[getOutputs()[i]]->getValue() == nts::Tristate::False) {
            std::cout << "0" << std::endl;
        } else if (components[getOutputs()[i]]->getValue() == nts::Tristate::True) {
            std::cout << "1" << std::endl;
        } else if (components[getOutputs()[i]]->getValue() == nts::Tristate::Undefined) {
            std::cout << "U" << std::endl;
        }
        i++;
    }
}

int is_exist(char *debut, std::vector<std::string> inputs, std::vector<std::string> clock)
{
    unsigned int z = 0;
    while (z < inputs.size()) {
        if (strcmp(debut, inputs[z].c_str()) == 0) {
            return (0);
        }
        z++;
    }
    z = 0;
    while (z < clock.size()) {
        if (strcmp(debut, clock[z].c_str()) == 0) {
            return (0);
        }
        z++;
    }
    return (84);
}

void Parser::simulate()
{
    // apply values set with the = sign in egal vector
    unsigned int z = 0;
    char *debut = NULL;
    char *fin = NULL;
    std::string temp;
    while (z < egal.size()) {
        temp = egal[z];
        debut = strtok(const_cast<char*>(temp.data()), "=");
        fin = const_cast<char*>(egal[z].data());
        fin = strtok(NULL, "=");
        if (fin[0] == '1' || fin[0] == '0' || fin[0] == 'U') {
            if (fin[0] == 'U') {
                strcpy(fin, "-1");
            }
            if (is_exist(debut, inputs, clocks) == 0) {
                components[debut]->setValue(atoi(fin), tick);
            }
        }
        z++;
    }
    z = 0;
    size_t pin = 0;
    // compute the output to obtain the result of the gate in the output
    // while (z < outputs.size()) {
    //     std::cout << outputs[z] << std::endl;
    //     pin = atoi(links[z].c_str());
    //     components[outputs[z]]->compute(pin);
    //     z++;
    // }

    // clear the egal vector
    egal.clear();

    // increase the tick by 1
    tick += 1;
}
