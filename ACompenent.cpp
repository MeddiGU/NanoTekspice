/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** ACompenent
*/

#include "ACompenent.hpp"

nts::ACompenent::ACompenent()
{
}

nts::ACompenent::~ACompenent()
{
}

void nts::ACompenent::simulate()
{
}

void nts::ACompenent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    _links[pin] = std::make_pair(&other, otherPin);
    other._links[otherPin] = std::make_pair(this, pin);
}

nts::Tristate nts::ACompenent::setValue(int value, int tick)
{
    return (_pin);
}

nts::Tristate nts::ACompenent::getValue()
{
    return (_pin);
}

std::map<std::size_t, std::pair<nts::IComponent *, std::size_t>> nts::ACompenent::getLink()
{
    return (_links);
}
