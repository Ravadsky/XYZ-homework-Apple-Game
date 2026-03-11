#pragma once
#include "SFML/Graphics.hpp"
#include "GameSettings.h"
#include <vector>

namespace ApplesGame
{//Новая структура - в состоянии интерфейса булева переменная конца игры, счетчик очков, подсказка ввода и текст конца игры
	struct UIState
	{
		bool isGameOverTextVisible = false;

		sf::Text scoreText;
		sf::Text inputHintText;
		sf::Text gameOverText;
		std::vector<std::pair<std::string, int>> Leaderboard{
			{"Guts", 1},
			{"Pudge", NUM_APPLES / 2},
			{"Alina", NUM_APPLES},
			{"Bombadil", NUM_APPLES / 3},
		};

		sf::Text leaderboardText;
	};
	//прототипы функций
	void InitUI(UIState& uiState, const sf::Font& font);
	void UpdateUI(UIState& uiState, const struct GameState& gameState, float timeDelta);
	void DrawUI(UIState& uiState, sf::RenderWindow& window);
	//void AddStringToText(sf::Text& textRef, std::string newString);
	//void sortLeaderboard(std::vector<std::pair<std::string, int>>& leaderboard);
}
