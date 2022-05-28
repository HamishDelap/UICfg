#pragma once

#include <string>
#include <utility>


namespace Components {
    enum class ComponentType {
        UNKNOWN,
        KNOB
    };

    enum class SliderStyle {
        Vertical,
        Rotary
    };

    struct Colour {
        int Red = 0;
        int Green = 0;
        int Blue = 0;
    };

    struct Knob {
        std::string name;
        int size_x = 0;
        int size_y = 0;
        int pos_x = 0;
        int pos_y = 0;
        int range = 1;
        std::string suffix;
        Colour colour;
        SliderStyle style;
    };

    // Must be at bottom
    struct Components
    {
        std::vector<Knob> knobs;
    };

};