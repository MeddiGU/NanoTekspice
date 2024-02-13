/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** OrComponent
*/

#include "../ACompenent.hpp"

#ifndef ORCOMPONENT_HPP_
#define ORCOMPONENT_HPP_

class OrComponent : public nts::ACompenent {
    public:
        OrComponent();
        ~OrComponent();
        nts::Tristate compute(std::size_t pin);

    protected:
    private:
};

#endif /* !ORCOMPONENT_HPP_ */
