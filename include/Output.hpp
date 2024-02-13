/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** Output
*/

#include "../ACompenent.hpp"

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

class Output : public nts::ACompenent {
    public:
        Output();
        ~Output();
        nts::Tristate compute(std::size_t pin);
};
#endif /* !OUTPUT_HPP_ */
