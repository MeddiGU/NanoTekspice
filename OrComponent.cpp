/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** OrComponent
*/

#include "include/OrComponent.hpp"

OrComponent::OrComponent()
{
}

OrComponent::~OrComponent()
{
}

nts::Tristate OrComponent::compute(std::size_t pin)
{
    if (pin == 3) {
        if (_links[1].first->compute(_links[1].second) == nts::Tristate::True
            || _links[2].first->compute(_links[2].second) == nts::Tristate::True)
            return nts::Tristate::True;
        if (_links[1].first->compute(_links[1].second) == nts::Tristate::False
            && _links[2].first->compute(_links[2].second) == nts::Tristate::False)
            return nts::Tristate::False;
        return nts::Tristate::Undefined;
    }
    return nts::Tristate::Undefined;
}
