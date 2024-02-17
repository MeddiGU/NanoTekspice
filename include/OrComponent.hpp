/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** OrComponent
*/

#include "../ACompenent.hpp"

#pragma once

class OrComponent : public nts::ACompenent {
    public:
        OrComponent();
        ~OrComponent();
        nts::Tristate compute(std::size_t pin);

    protected:
    private:
};
