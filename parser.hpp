#pragma once

#include <vector>
#include <string>
#include "structs.h"

class Parser
{
public:
    Parser(std::string filename);
    Components::Components Parse();

    std::vector<Components::Knob> GetKnobs();

private:
    std::string m_Filename;

    std::vector<Components::Knob> m_Knobs;
};