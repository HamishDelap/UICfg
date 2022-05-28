#include "JUCEConverter.hpp"

JUCEConverter::JUCEConverter() : m_Components({})
{}

JUCEConverter::JUCEConverter(const Components::Components& components) : m_Components(components)
{}

JUCEConverter::~JUCEConverter()
{
	for (auto& slider : m_JComponents.Sliders)
	{
		delete slider;
	}
}

bool JUCEConverter::Convert()
{
	for (auto& knob : m_Components.knobs)
	{
		m_JComponents.Sliders.push_back(new juce::Slider);
	}
	return true;
}

bool JUCEConverter::SetBounds()
{
	for (int i = 0; i < m_JComponents.Sliders.size(); i++)
	{
		Components::Knob knob = m_Components.knobs[i];
		m_JComponents.Sliders[i]->setBounds(knob.pos_x, knob.pos_y, knob.size_x, knob.size_y);
	}
	return true;
}

bool JUCEConverter::Initialise(std::function<void(juce::Component&)> initFunc)
{
	for (auto& slider : m_JComponents.Sliders)
	{
		initFunc(*slider);
		slider->setColour(juce::Slider::ColourIds::backgroundColourId, juce::Colour(0, 74, 97));
	}
	return true;
}