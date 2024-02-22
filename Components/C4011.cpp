/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** C4011
*/

#include "../include/C4011.hpp"

C4011::C4011()
{
}

C4011::~C4011()
{
}

nts::Tristate C4011::nand_gate(nts::Tristate pin1, nts::Tristate pin2)
{
    if (pin1 == nts::Tristate::True && pin2 == nts::Tristate::True)
        return nts::Tristate::False;
    if (pin1 == nts::Tristate::False || pin2 == nts::Tristate::False)
        return nts::Tristate::True;
    return nts::Tristate::Undefined;
}

nts::Tristate C4011::compute(std::size_t pin)
{
    if (pin == 1 || pin == 2 || pin == 5 || pin == 6 || pin == 8 || pin == 9 || pin == 12 || pin == 13)
        return _links[pin].first->compute(_links[pin].second);
    if (pin == 3)
        return nand_gate(_links[1].first->compute(_links[1].second), _links[2].first->compute(_links[2].second));
    if (pin == 4)
        return nand_gate(_links[5].first->compute(_links[5].second), _links[6].first->compute(_links[6].second));
    if (pin == 10)
        return nand_gate(_links[8].first->compute(_links[8].second), _links[9].first->compute(_links[9].second));
    if (pin == 11)
        return nand_gate(_links[12].first->compute(_links[12].second), _links[13].first->compute(_links[13].second));
    return nts::Tristate::Undefined;
}

nts::Tristate C4011::getValue()
{
    return(_pin);
}