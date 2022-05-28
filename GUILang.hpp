#pragma once

#include <vector>
#include <string>
#include <filesystem>
#include "structs.h"
#include "Parser.hpp"
#include "JUCEConverter.hpp"

class GUILang
{
public:
	GUILang();
	bool Parse(const std::filesystem::path& path);

	bool Convert();
	bool SetBounds();
	bool Initialise(std::function<void(juce::Component&)> initFunc);

	JUCEConverter m_Converter;

private:
	Components::Components m_Components;

	

};