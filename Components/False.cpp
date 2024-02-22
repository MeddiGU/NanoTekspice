/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** False
*/

#include "../include/False.hpp"

False::False()
{
}

False::~False()
{
}

nts::Tristate False::compute(std::size_t pin)
{
    return nts::Tristate::False;
}

nts::Tristate False::getValue()
{
    return(_pin);
}
