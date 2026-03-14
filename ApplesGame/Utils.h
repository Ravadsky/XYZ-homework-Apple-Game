#pragma once
#include <vector>
#include "SFML/Graphics.hpp"


namespace ApplesGame
{
	template <typename T>
	void sortVector(std::vector<T>& vec)
	{
		for (size_t i = 0; i < vec.size(); ++i)
		{
			size_t maxIndex = i;
			for (size_t j = i + 1; j < vec.size(); ++j)
			{
				if (vec[j] > vec[maxIndex])	maxIndex = j;
			}
			if (maxIndex != i) std::swap(vec[i], vec[maxIndex]);
		}
	}

	void AddStringToText(sf::Text& textRef, std::string newString);

}