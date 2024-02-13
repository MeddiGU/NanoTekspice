#include <iostream>
#include "ACompenent.hpp"
#include "include/C4081.hpp"
#include "include/C4071.hpp"
#include "include/True.hpp"
#include "include/False.hpp"
#include "include/NotComponent.hpp"
#include "include/AndComponent.hpp"
#include "include/OrComponent.hpp"
#include <memory>

int main(void)
{
    std::unique_ptr<nts::IComponent> gate = std ::make_unique<AndComponent>();
    std::unique_ptr<nts::IComponent> input1 = std ::make_unique<False>();
    std::unique_ptr<nts::IComponent> input2 = std ::make_unique<True>();
    std::unique_ptr<nts::IComponent> inverter = std ::make_unique<NotComponent>();
    gate->setLink(1, *input1, 1);
    gate->setLink(2, *input2, 1);
    inverter->setLink(1, *gate, 3);
    std::cout << " !( " << input1->compute(1) << " && " << input2->compute(1) << " ) ->" << inverter->compute (2) << std::endl;
    std::unique_ptr<nts::IComponent> gate2 = std ::make_unique<AndComponent>();
    std::unique_ptr<nts::IComponent> input12 = std ::make_unique<False>();
    std::unique_ptr<nts::IComponent> input22 = std ::make_unique<False>();
    std::unique_ptr<nts::IComponent> inverter2 = std ::make_unique<NotComponent>();
    gate2->setLink(1, *input12, 1);
    gate2->setLink(2, *input22, 1);
    inverter2->setLink(1, *gate2, 3);
    std::cout << " !( " << input12->compute(1) << " && " << input22->compute(1) << " ) ->" << inverter2->compute (2) << std::endl;
    std::unique_ptr<nts::IComponent> gate3 = std ::make_unique<AndComponent>();
    std::unique_ptr<nts::IComponent> input13 = std ::make_unique<True>();
    std::unique_ptr<nts::IComponent> input23 = std ::make_unique<True>();
    std::unique_ptr<nts::IComponent> inverter3 = std ::make_unique<NotComponent>();
    gate3->setLink(1, *input13, 1);
    gate3->setLink(2, *input23, 1);
    inverter3->setLink(1, *gate3, 3);
    std::cout << " !( " << input13->compute(1) << " && " << input23->compute(1) << " ) ->" << inverter3->compute (2) << std::endl;
    std::unique_ptr<nts::IComponent> gate4 = std ::make_unique<OrComponent>();
    std::unique_ptr<nts::IComponent> input14 = std ::make_unique<True>();
    std::unique_ptr<nts::IComponent> input24 = std ::make_unique<True>();
    std::unique_ptr<nts::IComponent> inverter4 = std ::make_unique<NotComponent>();
    gate4->setLink(1, *input14, 1);
    gate4->setLink(2, *input24, 1);
    inverter4->setLink(1, *gate4, 3);
    std::cout << " !( " << input14->compute(1) << " || " << input24->compute(1) << " ) ->" << inverter4->compute (2) << std::endl;
}