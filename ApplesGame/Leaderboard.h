#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

namespace ApplesGame
{

	void UpdateLeaderboard(sf::Text& leaderboard, std::vector<std::pair<std::string, int>>& liderboardtable);

	void ResetLeaderboard(std::vector<std::pair<std::string, int>>& liderboardtable);

	void AddStringToText(sf::Text& textRef, std::string newString);

	void sortLeaderboard(std::vector<std::pair<std::string, int>>& leaderboard);

}