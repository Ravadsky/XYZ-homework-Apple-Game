#include "Leaderboard.h"
#include "GameSettings.h"

namespace ApplesGame
{
	LeaderboardRecord::LeaderboardRecord(std::string _name, int _score) : Name(_name), Score(_score) {}

	bool LeaderboardRecord::operator>(const LeaderboardRecord& other) const
	{
		return Score > other.Score;
	}


	void Leaderboard::ResetTableData()
	{
		LeaderboardTable.clear();
		LeaderboardTable.emplace_back("Alina", NUM_APPLES);
		LeaderboardTable.emplace_back("Pudge", NUM_APPLES / 2);
		LeaderboardTable.emplace_back("Guts", NUM_APPLES / 3);
		LeaderboardTable.emplace_back("BaClan", NUM_APPLES / 5);
	}

	void Leaderboard::InitText(const sf::Font& font)
	{
		LeaderboardText.setFont(font);
		LeaderboardText.setCharacterSize(16);
		LeaderboardText.setStyle(sf::Text::Bold);
		LeaderboardText.setFillColor(sf::Color::White);
	}

	void Leaderboard::OrganizePrintableText()
	{
		LeaderboardText.setString(""); int counter = 0;
		AddStringToText(LeaderboardText, "============= LEADER  BOARD ==============");
		for (LeaderboardRecord& Record : LeaderboardTable)
		{
			counter++;
			std::string separator(35 - Record.Name.length(), '-');
			AddStringToText(LeaderboardText, std::to_string(counter) + ". " + Record.Name + " " + separator + " " + std::to_string(Record.Score));
		}
		AddStringToText(LeaderboardText, "==========================================");
	}

	void Leaderboard::AddRecord(std::string&& Name, int& Score)
	{
		LeaderboardTable.emplace_back(Name, Score);
		sortVector(LeaderboardTable);
		OrganizePrintableText();
	}

}