/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** C4001
*/

#include "include/C4001.hpp"

C4001::C4001()
{
}

C4001::~C4001()
{
}

nts::Tristate C4001::nor_gate(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::True || b == nts::Tristate::True)
        return nts::Tristate::False;
    if (a == nts::Tristate::False && b == nts::Tristate::False)
        return nts::Tristate::True;
    return nts::Tristate::Undefined;
}


nts::Tristate C4001::compute(std::size_t pin)
{
    return nts::Tristate::Undefined;
}