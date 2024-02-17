/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-alexandre.vittenet
** File description:
** MakeComponent
*/

#include "MakeComponent.hpp"
#include "Parser/Parser.hpp"

MakeComponent::MakeComponent()
{
}

MakeComponent::~MakeComponent()
{
}

std::unique_ptr<nts::IComponent> MakeComponent::createComponent(const std::string &type)
{
    if (type == "4001")
        return std::make_unique<C4001>();
    if (type == "4011")
        return std::make_unique<C4011>();
    if (type == "4030")
        return std::make_unique<C4030>();
    if (type == "4069")
        return std::make_unique<C4069>();
    if (type == "4071")
        return std::make_unique<C4071>();
    if (type == "4081")
        return std::make_unique<C4081>();
    if (type == "input")
        return std::make_unique<Input>();
    if (type == "output")
        return std::make_unique<Output>();
    if (type == "true")
        return std::make_unique<True>();
    if (type == "false")
        return std::make_unique<False>();
    if (type == "clock")
        return std::make_unique<Clock>();
    if (type == "and")
        return std::make_unique<AndComponent>();
    if (type == "or")
        return std::make_unique<OrComponent>();
    if (type == "xor")
        return std::make_unique<XorComponent>();
    if (type == "not")
        return std::make_unique<NotComponent>();
    return nullptr;
}
