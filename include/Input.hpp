/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** Input
*/

#include "ACompenent.hpp"

#pragma once

class Input : public nts::ACompenent {
    public:
        Input();
        ~Input();
        nts::Tristate compute(std::size_t pin);
        nts::Tristate setValue(int value);
        nts::Tristate getValue();
        protected:
        nts::Tristate _pin = nts::Tristate::Undefined;
};
