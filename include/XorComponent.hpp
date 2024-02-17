/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** XorComponent
*/

#include "../ACompenent.hpp"

#pragma once

class XorComponent : public nts::ACompenent {
    public:
        XorComponent();
        ~XorComponent();
        nts::Tristate compute(std::size_t pin);

    protected:
    private:
};
