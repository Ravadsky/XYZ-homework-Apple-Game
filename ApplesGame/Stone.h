#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"

namespace ApplesGame {

struct Stone
{
	Position position;
	sf::Sprite sprite;

};

void InitStone(Stone& stone, const sf::Texture& texture);
void DrawStone(Stone& stone, sf::RenderWindow& window);

}