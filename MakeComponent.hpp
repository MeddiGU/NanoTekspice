/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** MakeComponent
*/

#include "ACompenent.hpp"
#include "include/C4001.hpp"
#include "include/C4011.hpp"
#include "include/C4030.hpp"
#include "include/C4069.hpp"
#include "include/C4071.hpp"
#include "include/C4081.hpp"
#include "include/True.hpp"
#include "include/False.hpp"
#include "include/Input.hpp"
#include "include/Output.hpp"
#include "include/Clock.hpp"
#include "include/AndComponent.hpp"
#include "include/NotComponent.hpp"
#include "include/XorComponent.hpp"
#include "include/OrComponent.hpp"

#pragma once

class MakeComponent {
    public:
        MakeComponent();
        ~MakeComponent();
        std::unique_ptr<nts::IComponent> createComponent(const std::string &type);


    protected:
    private:
};
