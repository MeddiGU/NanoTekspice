/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** C4069
*/

#include "../include/C4069.hpp"

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
    if (pin == 1 || pin == 3 || pin == 5 || pin == 7 || pin == 9 || pin == 11 || pin == 13)
        return _links[pin].first->compute(_links[pin].second);
    if (pin == 2) {
        return inverter_gate(_links[1].first->compute(_links[1].second));
    }
    if (pin == 4) {
        return inverter_gate(_links[3].first->compute(_links[3].second));
    }
    if (pin == 6) {
        return inverter_gate(_links[5].first->compute(_links[5].second));
    }
    if (pin == 8) {
        return inverter_gate(_links[9].first->compute(_links[9].second));
    }
    if (pin == 10) {
        return inverter_gate(_links[11].first->compute(_links[11].second));
    }
    if (pin == 12) {
        return inverter_gate(_links[13].first->compute(_links[13].second));
    }
    return nts::Tristate::Undefined;
}

nts::Tristate C4069::getValue()
{
    return(_pin);
}
