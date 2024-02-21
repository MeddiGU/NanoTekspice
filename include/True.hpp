/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** True
*/

#include "../ACompenent.hpp"

#pragma once

class True : public nts::ACompenent {
    public:
        True();
        ~True();
        nts::Tristate compute(std::size_t pin);
        nts::Tristate getValue();
        protected:
        nts::Tristate _pin = nts::Tristate::True;
};
