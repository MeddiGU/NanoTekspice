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
    char *stock = NULL;

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
            stock = tmp;
            tmp = strtok(NULL, " ");
            tmp[strlen(tmp) - 1] = '\0';
            others.push_back(stock);
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

int Parser::vector_into_egal()
{
    unsigned int i = 0;
    line[strlen(line) - 1] = '\0';

    while (i < strlen(line)) {
        if (line[i] == '=') {
            egal.push_back(line);
        }
        i++;
    }
    return (0);
}

int Parser::vector_into_links()
{
    int dec = 0;
    int y = 0, t = 0;
    unsigned int z = 0, x = 0;
    int valid = 0;
    char temp[99];

    // skip tant que .links n'es pas trouvé
    while (y < vector.size() && t == 0) {
        if (strcmp(vector[y].c_str(), ".links:\n") == 0) {
            t = 1;
        }
        y++;
    }
    x = y;

    int h = 0;
    char pin[99];
    while (x < vector.size()) {
        while (z < vector[x].size()) {
            if (vector[x][z] == ':') {
                h = 0;
                while (vector[x][z + h + 1] != ' ' && vector[x][z + h + 1] != '\0' && vector[x][z + h + 1] != '\n') {
                    pin[h] = vector[x][z + h + 1];
                    h++;
                }
                pin[h] = '\0';
                while (vector[x][z - dec] != ' ' && z - dec != 0) {
                    temp[dec] = vector[x][z - dec - 1];
                    dec++;
                }
                temp[dec] = '\0';
                removeSpaces(temp);
                revstr(temp);
                links.push_back(temp);
                links.push_back(pin);
            }
            dec = 0;
            z++;
        }
        z = 0;
        x++;
    }
    return (0);
}

void Parser::create_components()
{
    MakeComponent make;
    std::unique_ptr<nts::IComponent> createComponent(const std::string& type);

    // create input coponents
    if (getInputs().size() > 0) {
        const auto& inputComponents = getInputs();
        for (size_t i = 0; i < inputComponents.size(); i += 1) {
            const std::string& componentName = inputComponents[i];

            std::unique_ptr<nts::IComponent> componentPtr = make.createComponent("input");

            if (componentPtr) {
                components[componentName] = std::move(componentPtr);
            } else {
                std::cout << "Un composent (input) n'a pas réussi a etre créé";
                exit (84);
            }
        }
    }

    // create output coponents
    if (getOutputs().size() > 0) {
        const auto& outputComponents = getOutputs();
        for (size_t i = 0; i < outputComponents.size(); i += 1) {
            const std::string& componentName = outputComponents[i];

            std::unique_ptr<nts::IComponent> componentPtr = make.createComponent("output");

            if (componentPtr) {
                components[componentName] = std::move(componentPtr);
            } else {
                std::cout << "Un composent (output) n'a pas réussi a etre créé";
                exit (84);
            }
        }
    }

    // create clock components
    if (getClock().size() > 0) {
        const auto& clockComponents = getClock();
        for (size_t i = 0; i < clockComponents.size(); i += 1) {
            const std::string& componentName = clockComponents[i];

            std::unique_ptr<nts::IComponent> componentPtr = make.createComponent("clock");

            if (componentPtr) {
                components[componentName] = std::move(componentPtr);
            } else {
                std::cout << "Un composent (clock) n'a pas réussi a etre créé";
                exit (84);
            }
        }
    }

    // create false components
    if (getFalse().size() > 0) {
        const auto& falseComponents = getFalse();
        for (size_t i = 0; i < falseComponents.size(); i += 1) {
            const std::string& componentName = falseComponents[i];

            std::unique_ptr<nts::IComponent> componentPtr = make.createComponent("false");

            if (componentPtr) {
                components[componentName] = std::move(componentPtr);
            } else {
                std::cout << "Un composent (false) n'a pas réussi a etre créé";
                exit (84);
            }
        }
    }

    // create true components
    if (getTrue().size() > 0) {
        const auto& trueComponents = getTrue();
        for (size_t i = 0; i < trueComponents.size(); i += 1) {
            const std::string& componentName = trueComponents[i];

            std::unique_ptr<nts::IComponent> componentPtr = make.createComponent("true");

            if (componentPtr) {
                components[componentName] = std::move(componentPtr);
            } else {
                std::cout << "Un composent (false) n'a pas réussi a etre créé";
                exit (84);
            }
        }
    }

    // create other components
    if (getOther().size() > 0) {
        const auto& otherComponents = getOther();
        for (size_t i = 0; i < otherComponents.size(); i += 2) {
            const std::string& componentName = otherComponents[i + 1];
            const std::string& componentType = otherComponents[i];

            std::unique_ptr<nts::IComponent> componentPtr = make.createComponent(componentType);

            if (componentPtr) {
                components[componentName] = std::move(componentPtr);
            } else {
                std::cout << "Un composent (other) n'a pas réussi a etre créé";
                exit (84);
            }
        }
    }
}

void Parser::set_links()
{
    unsigned int z = 0;
    while (z + 3 < links.size()) {
        std::string gate = links[z + 2];
        std::size_t pineTaSoeur = atoi(links[z + 1].c_str());
        nts::IComponent &componentPtr = *components.find(gate)->second;
        std::size_t componentpineTaSoeur = atoi(links[z + 3].c_str());
        //std::cout << links[z] << " : " << links[z + 1] << " : " << links[z + 2] << " : " << links[z + 3] << " : " << std::endl;
        //std::cout << gate << " : " << pineTaSoeur << " : " << components.find(gate)->first << " : " << componentpineTaSoeur << std::endl;
        components[links[z]]->setLink(pineTaSoeur, componentPtr, componentpineTaSoeur);

        std::string comp = links[z];
        nts::IComponent &gatePtr = *components.find(comp)->second;
        components[links[z + 2]]->setLink(componentpineTaSoeur, componentPtr, pineTaSoeur);
        z += 4;
    }

    // auto link = components["in_2"]->getLink()[1];
    // // Accéder aux éléments de la paire
    // std::cout << link.first << " / " << link.second;
}
