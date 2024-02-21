/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** True
*/

#include "include/True.hpp"

True::True()
{
}

True::~True()
{
}

nts::Tristate True::compute(std::size_t pin)
{
    return nts::Tristate::True;
}

nts::Tristate True::getValue()
{
    return(_pin);
}