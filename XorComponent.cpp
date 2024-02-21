/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** XorComponent
*/

#include "include/XorComponent.hpp"

XorComponent::XorComponent()
{
}

XorComponent::~XorComponent()
{
}

nts::Tristate XorComponent::compute(std::size_t pin)
{
    if (pin == 3) {
        if (_links[1].first->compute(_links[1].second) == nts::Tristate::True
            && _links[2].first->compute(_links[2].second) == nts::Tristate::False)
            return nts::Tristate::True;
        if (_links[1].first->compute(_links[1].second) == nts::Tristate::False
            && _links[2].first->compute(_links[2].second) == nts::Tristate::True)
            return nts::Tristate::True;
        if (_links[1].first->compute(_links[1].second) == nts::Tristate::True
            && _links[2].first->compute(_links[2].second) == nts::Tristate::True)
            return nts::Tristate::False;
        if (_links[1].first->compute(_links[1].second) == nts::Tristate::False
            && _links[2].first->compute(_links[2].second) == nts::Tristate::False)
            return nts::Tristate::False;
        return nts::Tristate::Undefined;
    }
    return nts::Tristate::Undefined;
}

nts::Tristate XorComponent::getValue()
{
    return(_pin);
}
