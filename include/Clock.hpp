/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** Clock
*/

#include "../ACompenent.hpp"

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

class Clock : public nts::ACompenent {
    public:
        Clock();
        ~Clock();
        nts::Tristate compute(std::size_t pin);
        protected:
        nts::Tristate _pin;
};

#endif /* !CLOCK_HPP_ */
