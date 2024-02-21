#include <iostream>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstring>

#include "Parser.hpp"
#include "../my.hpp"

std::vector<std::string> Parser::getVector()
{
    return (vector);
}

std::vector<std::string> Parser::getLinks()
{
    return (links);
}

std::vector<std::string> Parser::getInputs()
{
    return (inputs);
}

std::vector<std::string> Parser::getOutputs()
{
    return (outputs);
}

std::vector<std::string> Parser::getClock()
{
    return (clocks);
}

std::vector<std::string> Parser::getFalse()
{
    return (falses);
}

std::vector<std::string> Parser::getTrue()
{
    return (trues);
}

std::vector<std::string> Parser::getOther()
{
    return (others);
}

std::vector<std::string> Parser::getAll()
{
    return (alls);
}

std::vector<std::string> Parser::getTotal()
{
    return (total);
}

std::vector<std::string> Parser::getEgal()
{
    return (egal);
}

int Parser::getTick()
{
    return (tick);
}
