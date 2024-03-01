/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** Clock
*/

#include "../include/Clock.hpp"

Clock::Clock()
{
}

Clock::~Clock()
{
}

nts::Tristate Clock::compute(std::size_t pin)
{
    if (_pin == nts::Undefined) {
        _pin = nts::Undefined;
    } else if (_pin == nts::False) {
        _pin = nts::True;
    } else if (_pin == nts::True) {
        _pin = nts::False;
    }
    return (_pin);
}

nts::Tristate Clock::setValue2(int value, char *tick)
{
    if (tick[0] == '-' && tick[1] == '1') {
        _pin = nts::Undefined;
    } else if (tick[0] == '0') {
        _pin = nts::False;
    } else if (tick[0] == '1') {
        _pin = nts::True;
    }
    return (_pin);
}

nts::Tristate Clock::getValue()
{
    return(_pin);
}
