#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "Parser.hpp"
#include "structs.h"

Parser::Parser(std::string filename)
{
    m_Filename = filename;
}

static std::vector<std::string> ParseLine(std::string lineString)
{
    if (lineString.size() == 0) { return {}; }
    std::vector<std::string> lineVector;
    std::string word;
    size_t index = 0;
    for (char c : lineString)
    {
        index++;
        if (c == ' ' || c == '\r' || c == '\n')
        {
            if (!word.empty())
            {
                lineVector.push_back(word);
                word = "";
            }
        }
        else if (index == lineString.size())
        {
            if (!word.empty())
            {
                word += c;
                lineVector.push_back(word);
                word = "";
            }
        }
        else
        {
            word += c;
        }
    }

    return lineVector;
}

Components::Components Parser::Parse()
{
    std::ifstream file(m_Filename);

    std::string block;
    std::vector<std::string> lineVector;

    Components::ComponentType currentComponent = Components::ComponentType::UNKNOWN;

    while (std::getline(file, block))
    {
        lineVector = ParseLine(block);

        if ( lineVector.size() >= 2 && lineVector[0] == "KNOB" )
        {
            currentComponent = Components::ComponentType::KNOB;
            m_Knobs.push_back({lineVector[1].substr(0, lineVector[1].size()-1)});
        }
        else if ( lineVector.size() >= 3 && lineVector[0] == "size:" )
        {
            if (currentComponent == Components::ComponentType::KNOB)
            {
                auto& knob = m_Knobs.back();
                knob.size_x = std::stoi(lineVector[1].substr(0, lineVector[1].size()-1));
                knob.size_y = std::stoi(lineVector[2]);
            }
        }
        else if ( lineVector.size() >= 3 && lineVector[0] == "pos:" )
        {
            if (currentComponent == Components::ComponentType::KNOB)
            {
                auto& knob = m_Knobs.back();
                knob.pos_x = std::stoi(lineVector[1].substr(0, lineVector[1].size()-1));
                knob.pos_y = std::stoi(lineVector[2]);
            }
        }
    }
    
    file.close();
    return {m_Knobs};
}

std::vector<Components::Knob> Parser::GetKnobs()
{
    return m_Knobs;
}