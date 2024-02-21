/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** C4069
*/

#include "include/C4069.hpp"

C4069::C4069()
{
}

C4069::~C4069()
{
}

nts::Tristate C4069::inverter_gate(nts::Tristate pin)
{
    if (pin == nts::Tristate::True)
        return nts::Tristate::False;
    if (pin == nts::Tristate::False)
        return nts::Tristate::True;
    return nts::Tristate::Undefined;
}

nts::Tristate C4069::compute(std::size_t pin)
{
    if (pin == 1 || pin == 3 || pin == 5 || pin == 7 || pin == 9 || pin == 11)
        return inverter_gate(_links[pin].first->compute(_links[pin].second));
    if (pin == 2 || pin == 4 || pin == 6 || pin == 8 || pin == 10 || pin == 12)
        return _links[pin].first->compute(_links[pin].second);
    return nts::Tristate::Undefined;
}

nts::Tristate C4069::getValue()
{
    return(_pin);
}
