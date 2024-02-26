/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** OrComponent
*/

#include "../include/OrComponent.hpp"

OrComponent::OrComponent()
{
}

OrComponent::~OrComponent()
{
}

nts::Tristate OrComponent::or_gate(nts::Tristate pin1, nts::Tristate pin2)
{
    if (pin1 == nts::Tristate::True || pin2 == nts::Tristate::True)
        return nts::Tristate::True;
    if (pin1 == nts::Tristate::False && pin2 == nts::Tristate::False)
        return nts::Tristate::False;
    return nts::Tristate::Undefined;
}

nts::Tristate OrComponent::compute(std::size_t pin)
{
    if (pin == 3) {
        return or_gate(_links[1].first->compute(_links[1].second), _links[2].first->compute(_links[2].second));
    }
    return nts::Tristate::Undefined;
}

nts::Tristate OrComponent::getValue()
{
    return(_pin);
}
