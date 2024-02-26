/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** NotComponent
*/

#include "../include/NotComponent.hpp"

NotComponent::NotComponent()
{
}

NotComponent::~NotComponent()
{
}

nts::Tristate NotComponent::not_gate(nts::Tristate pin)
{
    if (pin == nts::Tristate::True)
        return nts::Tristate::False;
    if (pin == nts::Tristate::False)
        return nts::Tristate::True;
    return nts::Tristate::Undefined;
}

nts::Tristate NotComponent::compute(std::size_t pin)
{
    if (pin == 2) {
        return not_gate(_links[1].first->compute(_links[1].second));
    }
    return nts::Tristate::Undefined;
}

nts::Tristate NotComponent::getValue()
{
    return(_pin);
}
