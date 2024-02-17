/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** C4030
*/

#include "../ACompenent.hpp"

#pragma once

class C4030 : public nts::ACompenent{
    public:
        C4030();
        ~C4030();
        nts::Tristate compute(std::size_t pin);
        nts::Tristate xor_gate(nts::Tristate pin1, nts::Tristate pin2);
};
