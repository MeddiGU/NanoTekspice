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
    for (auto &i : alls) {
        if (components[i]->compute(1) == nts::Tristate::Undefined) {
            std::cout << "  " << i << ": " << "U" << std::endl;
        } else {
            std::cout << "  " << i << ": " << components[i]->compute(1) << std::endl;
        }
    }
    i = 0;
    std::cout << "output(s):\n";
    for (auto &i : outputs) {
        if (components[i]->compute(1) == nts::Tristate::Undefined) {
            std::cout << "  " << i << ": " << "U" << std::endl;
        } else {
            std::cout << "  " << i << ": " << components[i]->compute(1) << std::endl;
        }
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

    while (z < inputs.size()) {
        components[inputs[z]]->compute(1);
        //std::cout << "input: " << inputs[z] << " value: " << components[inputs[z]]->compute(1) << std::endl;
        z++;
    }
    z = 0;
    while (z < clocks.size()) {
        components[clocks[z]]->compute(1);
        //std::cout << "input: " << inputs[z] << " value: " << components[inputs[z]]->compute(1) << std::endl;
        z++;
    }
    z = 1;
    while (z < outputs.size()) {
        components[outputs[z]]->compute(1);
        //std::cout << "output: " << outputs[z] << " value: " << components[outputs[z]]->compute(1) << std::endl;
        z++;
    }

    // clear the egal vector
    egal.clear();

    // increase the tick by 1
    tick += 1;
}
