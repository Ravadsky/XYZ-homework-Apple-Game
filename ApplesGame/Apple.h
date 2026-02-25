#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"

namespace ApplesGame
{   //Новая структура Яблоко. В нём лежат позиция по х и у + спрайт
	struct Apple
	{
		Position position;
		sf::Sprite sprite;
	};
	//Прототипы функций из соответствующего cpp
	void InitApple(Apple* apple, const sf::Texture& texture);
	void DeleteApple(Apple* apple);
	void DrawApple(Apple* apple, sf::RenderWindow& window);
}
