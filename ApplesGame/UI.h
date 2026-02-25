#pragma once
#include "SFML/Graphics.hpp"

namespace ApplesGame
{//Новая структура - в состоянии интерфейса булева переменная конца игры, счетчик очков, подсказка ввода и текст конца игры
	struct UIState
	{
		bool isGameOverTextVisible = false;

		sf::Text scoreText;
		sf::Text inputHintText;
		sf::Text gameOverText;
	};
	//прототипы функций
	void InitUI(UIState& uiState, const sf::Font& font);
	void UpdateUI(UIState& uiState, const struct GameState& gameState, float timeDelta);
	void DrawUI(UIState& uiState, sf::RenderWindow& window);
}
