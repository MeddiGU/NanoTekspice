#include <iostream>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstring>

#include "Parser.hpp"

Parser::Parser()
{
    line = nullptr;
    skip = 0;
    tick = 0;
}

Parser::~Parser()
{
}
