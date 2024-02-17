/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** C4081
*/

#include "../ACompenent.hpp"

#pragma once

class C4081 : public nts::ACompenent {
    public:
        C4081();
        ~C4081();
        nts::Tristate compute(std::size_t pin);
        nts::Tristate and_gate(nts::Tristate pin1, nts::Tristate pin2);
};
