#pragma once
#include "SFML/Graphics.hpp"

struct GameOptionsState
{
	sf::Text OptionsBaseText;
	sf::Text RandomApplesSelector;
	bool ContinueOptions = false;

	int ApplesNumber = 0;

	bool isRandomNumberApples = false;
	bool isEndlessMode = false;
	bool isAccelerated = false;

	uint8_t GameOptions = 0b00000000;

};

void InitOptionUI(GameOptionsState& OptionsState, const sf::Font& font);
void AddOptionUIText(GameOptionsState& OptionsState, std::string stroke);
void DrawOptionUI(GameOptionsState& OptionsState, sf::RenderWindow& window);