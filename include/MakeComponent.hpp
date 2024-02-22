/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** MakeComponent
*/

#include "ACompenent.hpp"
#include "C4001.hpp"
#include "C4011.hpp"
#include "C4030.hpp"
#include "C4069.hpp"
#include "C4071.hpp"
#include "C4081.hpp"
#include "True.hpp"
#include "False.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "Clock.hpp"
#include "AndComponent.hpp"
#include "NotComponent.hpp"
#include "XorComponent.hpp"
#include "OrComponent.hpp"

#pragma once

class MakeComponent {
    public:
        MakeComponent();
        ~MakeComponent();
        std::unique_ptr<nts::IComponent> createComponent(const std::string &type);


    protected:
    private:
};
