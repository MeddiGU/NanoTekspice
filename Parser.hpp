/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** Parser
*/

#pragma once

#include <iostream>
#include <vector>

class Parser {
    protected:
        std::vector<std::string> vector;

        std::vector<std::string> inputs;
        std::vector<std::string> inputs_temp;
        std::vector<std::string> outputs;
        std::vector<std::string> clocks;
        std::vector<std::string> trues;
        std::vector<std::string> falses;
        std::vector<std::string> alls;

        int tick;
        enum stat {zero, un, U};
        stat statement;

    public:
        char *line;

        std::vector<std::string> getVector();
        std::vector<std::string> getInputs();
        std::vector<std::string> getOutputs();
        std::vector<std::string> getClock();
        std::vector<std::string> getFalse();
        std::vector<std::string> getTrue();
        std::vector<std::string> getAll();
        int getTick();
        stat getStatement();

        int path_into_vector(char *path);
        int vector_into_inputs();
        int vector_into_outputs();
        int vector_into_clocks();
        int vector_into_trues();
        int vector_into_falses();
        int vector_into_alls();
        void display_vector(std::vector<std::string> vec);

        void display();
        void simulate();

        Parser();
        ~Parser();

};
