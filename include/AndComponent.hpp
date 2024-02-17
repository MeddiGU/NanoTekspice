/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** AndComponent
*/

#include "../ACompenent.hpp"

#pragma once

class AndComponent : public nts::ACompenent {
    public:
        AndComponent();
        ~AndComponent();
        nts::Tristate compute(std::size_t pin);

    protected:
    private:
};
