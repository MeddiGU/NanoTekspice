/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** False
*/

#include "../ACompenent.hpp"


#pragma once

class False : public nts::ACompenent {
    public:
        False();
        ~False();
        nts::Tristate compute(std::size_t pin);
};
