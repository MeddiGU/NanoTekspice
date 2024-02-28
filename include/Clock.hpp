/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** Clock
*/

#include "ACompenent.hpp"

#pragma once

class Clock : public nts::ACompenent {
    public:
        Clock();
        ~Clock();
        nts::Tristate compute(std::size_t pin);
        nts::Tristate setValue(int value, char *tick);
        nts::Tristate getValue();
        protected:
        nts::Tristate _pin = nts::Tristate::Undefined;
};
