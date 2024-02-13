/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** Input
*/

#include "../ACompenent.hpp"

#ifndef INPUT_HPP_
#define INPUT_HPP_


class Input : public nts::ACompenent {
    public:
        Input();
        ~Input();
        nts::Tristate compute(std::size_t pin);
        protected:
        nts::Tristate _pin;
};


#endif /* !INPUT_HPP_ */
