/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** AndComponent
*/

#include "include/AndComponent.hpp"

AndComponent::AndComponent()
{
}

AndComponent::~AndComponent()
{
}

nts::Tristate AndComponent::compute(std::size_t pin)
{
    if (pin == 3) {
        if (_links[1].first->compute(_links[1].second) == nts::True &&
            _links[2].first->compute(_links[2].second) == nts::True)
            return nts::True;
        else
            return nts::False;
    }
    return nts::Undefined;
}