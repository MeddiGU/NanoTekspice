/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** C4069
*/

#include "../ACompenent.hpp"

#ifndef C4069_HPP_
#define C4069_HPP_

class C4069 : public nts::ACompenent{
    public:
        C4069();
        ~C4069();
        nts::Tristate compute(std::size_t pin);
        nts::Tristate inverter_gate(nts::Tristate pin);


    protected:
    private:
};

#endif /* !C4069_HPP_ */
