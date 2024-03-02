/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** Parser
*/

#pragma once

#include <iostream>
#include <vector>
#include "../src/my.hpp"

class Parser {
    protected:
        std::vector<std::string> vector;
        std::vector<std::string> links;

        std::vector<std::string> inputs;
        std::vector<std::string> inputs_temp;
        std::vector<std::string> outputs;
        std::vector<std::string> clocks;
        std::vector<std::string> trues;
        std::vector<std::string> falses;
        std::vector<std::string> others;
        std::vector<std::string> alls;
        std::vector<std::string> total;
        std::vector<std::string> egal;
        std::map<std::string, std::unique_ptr<nts::IComponent>> components;
        int tick;

    public:
        char *line;
        int skip;

        std::vector<std::string> getVector();
        std::vector<std::string> getLinks();
        std::vector<std::string> getInputs();
        std::vector<std::string> getOutputs();
        std::vector<std::string> getClock();
        std::vector<std::string> getFalse();
        std::vector<std::string> getTrue();
        std::vector<std::string> getOther();
        std::vector<std::string> getAll();
        std::vector<std::string> getTotal();
        std::vector<std::string> getEgal();
        int getTick();

        int path_into_vector(char *path);
        int path_into_skip(char *path);
        int parsing_error_before();
        int vector_into_inputs();
        int vector_into_outputs();
        int vector_into_clocks();
        int vector_into_trues();
        int vector_into_falses();
        int vector_into_others();
        int vector_into_alls();
        int vector_into_links();
        int vector_into_total();
        int vector_into_egal();
        int parsing_error();
        void create_components();
        void set_links();
        void display_vector(std::vector<std::string> vec);
        void display_map();

        void display();
        void simulate();

        Parser();
        ~Parser();

};
void removeSpaces(char *str);
void revstr(char *chaine);
