/*
** EPITECH PROJECT, 2024
** Tek
** File description:
** ACompenent
*/

#include <iostream>
#include <vector>
#include <map>
#include <memory>

#pragma once

namespace nts {

    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };

    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual void simulate() = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual nts::Tristate setValue(int value, int tick) = 0;
            virtual nts::Tristate getValue() = 0;
            nts::Tristate _pin = nts::Tristate::Undefined;
    };

    class ACompenent : public IComponent {
        public:
            ACompenent();
            ~ACompenent();
            void simulate();
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            std::unique_ptr<nts::IComponent> createComponent(const std::string &type);
            nts::Tristate setValue(int value, int tick);
            nts::Tristate getValue();
            nts::Tristate _pin;
        protected:
            std::map<std::size_t, std::pair<IComponent *, std::size_t>> _links;
    };
}
