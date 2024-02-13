/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** C4071
*/

#include "../ACompenent.hpp"

#ifndef C4071_HPP_
#define C4071_HPP_

class C4071 : public nts::ACompenent {
    public:
        C4071();
        ~C4071();
        nts::Tristate compute(std::size_t pin);
        nts::Tristate or_gate(nts::Tristate a, nts::Tristate b);
};

#endif /* !C4071_HPP_ */
