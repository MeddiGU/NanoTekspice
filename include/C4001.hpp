/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** C4001
*/

#include "../ACompenent.hpp"

#pragma once

class C4001 : public nts::ACompenent {
    public:
        C4001();
        ~C4001();
        nts::Tristate compute(std::size_t pin);
        nts::Tristate nor_gate(nts::Tristate a, nts::Tristate b);
        nts::Tristate getValue();
        protected:
        nts::Tristate _pin = nts::Tristate::Undefined;
};
