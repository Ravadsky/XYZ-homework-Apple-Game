#include "Math.h"

namespace ApplesGame
{   //Функция конвертация в вектор формата SFML
	sf::Vector2f OurVectorToSf(const Vector2D& v)
	{
		return sf::Vector2f(v.x, v.y);
	}
	//Функция получения скейла спрайта
	sf::Vector2f GetSpriteScale(const sf::Sprite& sprite, const Vector2D& desiredSize)
	{
		//получить размер текстуры
		const sf::Vector2u textureSize = sprite.getTexture()->getSize();
		//Поделить реальный размер на размер текстуры, тем самым понять коэффициент скейла этой текстуры.
		const sf::Vector2f spriteScale = { desiredSize.x / textureSize.x, desiredSize.y / textureSize.y };
		return spriteScale;
	}
	//Получить ориджин (пивот поинт)  у спрайта
	sf::Vector2f GetSpriteOrigin(const sf::Sprite& sprite, const Vector2D& relativePosition)
	{ //получаем настоящий размер текстуры
		const sf::Vector2u textureSize = sprite.getTexture()->getSize();
		//Умножаем смещение объекта на размер текстуры
		return { relativePosition.x * textureSize.x, relativePosition.y * textureSize.y };
	}
	//Получить ориджин у текста
	sf::Vector2f GetTextOrigin(const sf::Text& text, const Vector2D& relativePosition)
	{ //получить размер текста по его границам
		sf::FloatRect textSize = text.getLocalBounds();
		return { //вернуть структуру вектора, в которой математички высчитываются левый и верхний координаты текста
			(textSize.left + textSize.width) * relativePosition.x,
			(textSize.top + textSize.height) * relativePosition.y,
		};
	}

	bool CheckBit(uint8_t& mask, int digit)
	{
		return mask & (1 << digit);
	}

	void SetMaskBit(uint8_t& mask, int digit, bool state)
	{
		if (state)
			mask |= (1 << digit);   // установить бит
		else
			mask &= ~(1 << digit);   // сбросить бит
	}

}
