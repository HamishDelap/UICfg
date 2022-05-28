#pragma once

#include <vector>
#include <string>
#include <filesystem>
#include <JuceHeader.h>
#include "structs.h"
#include "Parser.hpp"

class JUCEConverter
{
public:
	JUCEConverter();
	JUCEConverter(const Components::Components& components);
	~JUCEConverter();
	
	bool Convert();

	bool SetBounds();
	bool Initialise(std::function<void(juce::Component&)> initFunc);

	struct JComponents
	{
		std::vector<juce::Slider*> Sliders;
	};
	JComponents m_JComponents;

private:
	Components::Components m_Components;

};