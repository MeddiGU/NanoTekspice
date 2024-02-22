/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** C4069
*/

#include "ACompenent.hpp"

#pragma once

class C4069 : public nts::ACompenent{
    public:
        C4069();
        ~C4069();
        nts::Tristate compute(std::size_t pin);
        nts::Tristate inverter_gate(nts::Tristate pin);
        nts::Tristate getValue();
        protected:
        nts::Tristate _pin = nts::Tristate::Undefined;
};
