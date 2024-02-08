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
    tick = 0;
    statement = stat::U;
}

Parser::~Parser()
{
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        std::cout << "./Parser (fichier.nts)" << std::endl;
        return (84);
    }
    Parser nan1;
    nan1.path_into_vector(argv[1]);
    nan1.vector_into_inputs();
    nan1.vector_into_outputs();
    nan1.vector_into_clocks();
    nan1.vector_into_falses();
    nan1.vector_into_trues();
    nan1.vector_into_alls();

    //display_vector(nan1.getVector());
    //nan1.display_vector(nan1.getInputs());
    //nan1.display_vector(nan1.getOutputs());

    size_t len = 0;
    while (1) {
        write(0, "> ", 3);
        if (getline(&nan1.line, &len, stdin) == -1) {
            exit (0);
        }
        if (strcmp(nan1.line, "display\n") == 0) {
            nan1.display();
        }
        if (strcmp(nan1.line, "exit\n") == 0) {
            exit(0);
        }
        if (strcmp(nan1.line, "input\n") == 0) {
            nan1.display_vector(nan1.getInputs());
        }
        if (strcmp(nan1.line, "output\n") == 0) {
            nan1.display_vector(nan1.getOutputs());
        }
        if (strcmp(nan1.line, "clock\n") == 0) {
            nan1.display_vector(nan1.getClock());
        }
        if (strcmp(nan1.line, "true\n") == 0) {
            nan1.display_vector(nan1.getTrue());
        }
        if (strcmp(nan1.line, "false\n") == 0) {
            nan1.display_vector(nan1.getFalse());
        }
        if (strcmp(nan1.line, "all\n") == 0) {
            nan1.display_vector(nan1.getAll());
        }
    }
    return (0);
}
