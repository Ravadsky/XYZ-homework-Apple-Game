#include "Leaderboard.h"
#include "GameSettings.h"

namespace ApplesGame
{

void UpdateLeaderboard(sf::Text& leaderboard, std::vector<std::pair<std::string, int>>& liderboardtable)
{
	sortLeaderboard(liderboardtable);

	leaderboard.setString(""); int counter = 0;
	AddStringToText(leaderboard, "============== LEADER BOARD ==============");
	for (std::pair<std::string, int> leader : liderboardtable)
	{
		counter++;
		std::string separator(35 - leader.first.length(), '-');
		AddStringToText(leaderboard, (std::to_string(counter) + ". " + leader.first + " " + separator + " " + std::to_string(leader.second)));
	}
	AddStringToText(leaderboard, "==========================================");
}

void ResetLeaderboard(std::vector<std::pair<std::string, int>>& liderboardtable)
{
	liderboardtable =
	{
		{"Guts", 1},
		{"Pudge", NUM_APPLES / 2},
		{"Alina", NUM_APPLES},
		{"Bombadil", NUM_APPLES / 3},
	};
}

void AddStringToText(sf::Text& textRef, std::string newString)
{
	textRef.setString(textRef.getString() + newString + "\n");
}

void sortLeaderboard(std::vector<std::pair<std::string, int>>& leaderboard)
{
	for (size_t i = 0; i < leaderboard.size(); ++i)
	{
		size_t maxIndex = i;
		for (size_t j = i + 1; j < leaderboard.size(); ++j)
		{
			if (leaderboard[j].second > leaderboard[maxIndex].second)
			{
				maxIndex = j;
			}
		}

		if (maxIndex != i)
		{
			std::swap(leaderboard[i], leaderboard[maxIndex]);
		}
	}
}
}