// Your First C++ Program
#include "parser.hpp"
#include "structs.h"
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) 
{
    if (argc != 2)
    {
        std::cerr << "1 argument required - filename\n";
        return 1;
    }

    std::cout << "Welcome to GUI Lang\n";

    Parser parser = Parser(argv[1]);

    parser.Parse();

    std::vector<Components::Knob> result = parser.GetKnobs();

    for (Components::Knob knob : result)
    {
        fprintf(stdout, "Name: %s, size_x: %i, size_y: %i, pos_x: %i, pos_y: %i \n", knob.name.c_str(), knob.size_x, knob.size_y, knob.pos_x, knob.pos_y);
    }
    // .gui -> struct -> insert into cpp

    return 0;
}
