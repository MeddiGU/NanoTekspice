/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** NotComponent
*/

#include "../ACompenent.hpp"

#pragma once

class NotComponent : public nts::ACompenent {
    public:
        NotComponent();
        ~NotComponent();
        nts::Tristate compute(std::size_t pin);
        nts::Tristate getValue();
        protected:
        nts::Tristate _pin = nts::Tristate::Undefined;
};
