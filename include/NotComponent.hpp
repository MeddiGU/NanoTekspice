/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** NotComponent
*/

#include "../ACompenent.hpp"

#ifndef NOTCOMPONENT_HPP_
#define NOTCOMPONENT_HPP_

class NotComponent : public nts::ACompenent {
    public:
        NotComponent();
        ~NotComponent();
        nts::Tristate compute(std::size_t pin);


    protected:
    private:
};

#endif /* !NOTCOMPONENT_HPP_ */
