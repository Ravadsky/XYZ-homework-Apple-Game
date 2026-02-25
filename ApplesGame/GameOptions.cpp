#include "GameOptions.h"


void InitOptionUI(GameOptionsState& OptionsState, const sf::Font& font)
{
	OptionsState.OptionsBaseText.setFont(font);
	OptionsState.OptionsBaseText.setCharacterSize(32);
	OptionsState.OptionsBaseText.setFillColor(sf::Color::White);
	OptionsState.OptionsBaseText.setPosition(50.f, 50.f);
	AddOptionUIText(OptionsState, "Default variants = No");
	AddOptionUIText(OptionsState, "Random count of apples : 1 - Yes / 2 - No");
	AddOptionUIText(OptionsState, "Endless mode : 3 - Yes / 4 - No");
	AddOptionUIText(OptionsState, "Acceleration after eating apple : 5 - Yes / 6 - No");
	AddOptionUIText(OptionsState, "\n     Start game : Enter");
}

void AddOptionUIText(GameOptionsState& OptionsState, std::string stroke)
{
	OptionsState.OptionsBaseText.setString(OptionsState.OptionsBaseText.getString() + stroke + "\n");
}

void DrawOptionUI(GameOptionsState& OptionsState, sf::RenderWindow& window)
{
	window.clear();
	window.draw(OptionsState.OptionsBaseText);
	window.display();
}