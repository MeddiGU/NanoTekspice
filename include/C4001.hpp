/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** C4001
*/

#include "../ACompenent.hpp"

#ifndef C4001_HPP_
#define C4001_HPP_

class C4001 : public nts::ACompenent {
    public:
        C4001();
        ~C4001();
        nts::Tristate compute(std::size_t pin);
        nts::Tristate nor_gate(nts::Tristate a, nts::Tristate b);
};

#endif /* !C4001_HPP_ */
