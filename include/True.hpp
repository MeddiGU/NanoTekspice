/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** True
*/

#include "../ACompenent.hpp"

#ifndef TRUE_HPP_
#define TRUE_HPP_

class True : public nts::ACompenent {
    public:
        True();
        ~True();
        nts::Tristate compute(std::size_t pin);
};

#endif /* !TRUE_HPP_ */
