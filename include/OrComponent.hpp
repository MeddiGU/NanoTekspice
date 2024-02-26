/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** OrComponent
*/

#include "ACompenent.hpp"

#pragma once

class OrComponent : public nts::ACompenent {
    public:
        OrComponent();
        ~OrComponent();
        nts::Tristate compute(std::size_t pin);
        nts::Tristate getValue();
        nts::Tristate or_gate(nts::Tristate pin1, nts::Tristate pin2);
        protected:
        nts::Tristate _pin = nts::Tristate::Undefined;
};
