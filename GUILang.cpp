#include "GUILang.hpp"

GUILang::GUILang()
{

}

bool GUILang::Parse(const std::filesystem::path& configFile)
{
	Parser parser(configFile.string());
	m_Components = parser.Parse();
	m_Converter = JUCEConverter(m_Components);
	return true;
}

bool GUILang::Convert()
{
	return m_Converter.Convert();
}

bool GUILang::SetBounds()
{
	return m_Converter.SetBounds();
}

bool GUILang::Initialise(std::function<void(juce::Component&)> initFunc)
{
	return m_Converter.Initialise(initFunc);
}