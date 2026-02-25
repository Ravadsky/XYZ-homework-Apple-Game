#include "Stone.h"
#include "GameSettings.h"

namespace ApplesGame
{

	void InitStone(Stone& stone, const sf::Texture& texture)
	{
		stone.position.x = (float)(rand() % (SCREEN_WIDTH + 1));
		stone.position.y = (float)(rand() % (SCREEN_HEGHT + 1));

		stone.sprite.setTexture(texture);
		stone.sprite.setOrigin(GetSpriteOrigin(stone.sprite, { 0.5f, 0.5f }));

		stone.sprite.setScale(GetSpriteScale(stone.sprite, { STONE_SIZE, STONE_SIZE }));
	}

	void DrawStone(Stone& stone, sf::RenderWindow& window)
	{
		stone.sprite.setPosition(OurVectorToSf(stone.position));
		//Нариосовать на экране спрайт яблока
		window.draw(stone.sprite);
	}


}
