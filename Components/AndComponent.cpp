/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** AndComponent
*/

#include "../include/AndComponent.hpp"

AndComponent::AndComponent()
{
}

AndComponent::~AndComponent()
{
}

nts::Tristate AndComponent::and_gate(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::True && b == nts::Tristate::True) {
        return nts::Tristate::True;
    } else if (a == nts::Tristate::False && b == nts::Tristate::Undefined) {
        return nts::Tristate::False;
    } else if (a == nts::Tristate::Undefined && b == nts::Tristate::False) {
        return nts::Tristate::False;
    } else if (a == nts::Tristate::Undefined && b == nts::Tristate::True) {
        return nts::Tristate::Undefined;
    } else if (a == nts::Tristate::True && b == nts::Tristate::Undefined) {
        return nts::Tristate::Undefined;
    } else if (a == nts::Tristate::Undefined && b == nts::Tristate::Undefined) {
        return nts::Tristate::Undefined;
    } else if (a == nts::Tristate::False && b == nts::Tristate::False) {
        return nts::Tristate::False;
    } else if (a == nts::Tristate::True && b == nts::Tristate::False) {
        return nts::Tristate::False;
    } else if (a == nts::Tristate::False && b == nts::Tristate::True) {
        return nts::Tristate::False;
    } else {
        return nts::Tristate::Undefined;
    }
}

nts::Tristate AndComponent::compute(std::size_t pin)
{
    if (pin == 3) {
        return (and_gate(_links[1].first->compute(_links[1].second), _links[2].first->compute(_links[2].second)));
    }
    return nts::Undefined;
}

nts::Tristate AndComponent::getValue()
{
    return(_pin);
}
