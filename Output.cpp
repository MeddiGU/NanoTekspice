/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** Output
*/

#include "include/Output.hpp"

Output::Output()
{
}

Output::~Output()
{
}

nts::Tristate Output::compute(std::size_t pin)
{
    return(_links[pin].first->compute(_links[pin].second));
}