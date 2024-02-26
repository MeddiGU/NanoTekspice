#include "my.hpp"

int main(int argc, char **argv)
{
    if (argc == 1) {
        std::cout << "./Parser (fichier.nts)" << std::endl;
        return (84);
    }
    if (argv[1][strlen(argv[1])- 1] != 's' && argv[1][strlen(argv[1])- 2] != 't' && argv[1][strlen(argv[1])- 3] != 'n') {
        std::cout << "Wrong extention, expected '.nts'" << std::endl ;
        return (84);
    }
    Parser nan1;
    nan1.path_into_vector(argv[1]);
    nan1.path_into_skip(argv[1]);
    nan1.parsing_error_before();
    nan1.vector_into_inputs();
    nan1.vector_into_outputs();
    nan1.vector_into_clocks();
    nan1.vector_into_falses();
    nan1.vector_into_trues();
    nan1.vector_into_others();
    nan1.vector_into_alls();
    nan1.vector_into_total();
    nan1.vector_into_links();
    nan1.create_components();
    nan1.parsing_error();
    size_t len = 0;

    nan1.set_links();
    while (1) {
        std::cout << "> ";
        if (getline(&nan1.line, &len, stdin) == -1) {
            exit (0);
        }
        if (strcmp(nan1.line, "display\n") == 0) {
            nan1.display();
        }
        if (strcmp(nan1.line, "exit\n") == 0) {
            exit(0);
        }
        if (strcmp(nan1.line, "simulate\n") == 0) {
            nan1.simulate();
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
        if (strcmp(nan1.line, "others\n") == 0) {
            nan1.display_vector(nan1.getOther());
        }
        if (strcmp(nan1.line, "egal\n") == 0) {
            nan1.display_vector(nan1.getEgal());
        }
        if (strcmp(nan1.line, "map\n") == 0) {
            nan1.display_map();
        }
        nan1.vector_into_egal();
    }
    return (0);
}
