/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** Clock
*/

#include "include/Clock.hpp"

Clock::Clock()
{
}

Clock::~Clock()
{
}

nts::Tristate Clock::compute(std::size_t pin)
{
    if (_pin == nts::Tristate::True)
        _pin = nts::Tristate::False;
    else
        _pin = nts::Tristate::True;
    return _pin;
}



