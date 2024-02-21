/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** Input
*/

#include "include/Input.hpp"

Input::Input()
{
}

Input::~Input()
{
}

nts::Tristate Input::compute(std::size_t pin)
{
    return _pin;
}

nts::Tristate Input::setValue(int value, int tick)
{
    if (value == 1) {
        _pin = nts::Tristate::True;
    } else if (value == 0) {
        _pin = nts::Tristate::False;
    } else {
        _pin = nts::Tristate::Undefined;
    }
    return(_pin);
}

nts::Tristate Input::getValue()
{
    return(_pin);
}
