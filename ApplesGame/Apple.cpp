#include "Apple.h"
#include "GameSettings.h"

#include <cstdlib>

//сделали новое пространство имен по названию игры
namespace ApplesGame
{
	//функци€ инициализации €блока
	void InitApple(Apple* apple, const sf::Texture& texture)
	{
		// размещение €блока рандомно по ’ и ” от 0 до ширины/высоты экрана
		apple->position.x = (float)(rand() % (SCREEN_WIDTH + 1));
		apple->position.y = (float)(rand() % (SCREEN_HEGHT + 1));

		// ”становить текстуру в спрайт
		apple->sprite.setTexture(texture);
		// ”становка центра спрайта в середине текстурки, чтобы увеличение картинки по скейлу равномерно расшир€ло спрайт в стороны
		apple->sprite.setOrigin(GetSpriteOrigin(apple->sprite, { 0.5f, 0.5f }));
		//”становить увеличение равное константе APPLE_SIZE
		apple->sprite.setScale(GetSpriteScale(apple->sprite, { APPLE_SIZE, APPLE_SIZE }));
		sf::Color appleColor = rand() % 2 ? sf::Color::Red : sf::Color::Yellow;
		apple->sprite.setColor(appleColor);
	}
	void DeleteApple(Apple* apple)
	{
		apple->position.x = -64;
		apple->position.y = -64;
	}
	//функци€ отрисовки €блока в главном окне
	void DrawApple(Apple* apple, sf::RenderWindow& window)
	{
		//установить позицию дл€ спрайта там, где находитс€ само €блоко
		apple->sprite.setPosition(OurVectorToSf(apple->position));
		//Ќариосовать на экране спрайт €блока
		window.draw(apple->sprite);
	}

}
