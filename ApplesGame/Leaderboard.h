#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Utils.h"
#include "GameSettings.h"
#include "Math.h"

namespace ApplesGame
{
	struct LeaderboardRecord
	{
		std::string Name;
		int Score;

		LeaderboardRecord(std::string _name, int _score);
		bool operator>(const LeaderboardRecord& other) const;
	};

	struct Leaderboard
	{
		sf::Text LeaderboardText;
		std::vector<LeaderboardRecord> LeaderboardTable;

		void ResetTableData();
		void InitText(const sf::Font& font);
		void OrganizePrintableText();
		void AddRecord(std::string&& Name, int& Score);
	};
	

}