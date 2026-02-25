#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "GameSettings.h"

namespace ApplesGame
{//Перечисление направлений для удобного свича
	enum class PlayerDirection
	{
		Up = 0,
		Right,
		Down,
		Left
	};
	//Новая структура - игрок, в ней позиция, текущая скорость, направление и спрайт
	struct Player
	{
		Position position;
		float speed = 0.f; // Pixels per second
		PlayerDirection direction = PlayerDirection::Up;
		sf::Sprite sprite;
	};
	//прототипы функций
	void InitPlayer(Player& player, const sf::Texture& texture);
	void UpdatePlayer(Player& player, float timeDelta);

	bool HasPlayerCollisionWithScreenBorder(const Player& player);
	bool HasPlayerCollisionWithApple(const Player& player, const struct Apple* apple);
	bool HasPlayerCollisionWithStone(const Player& player, const struct Stone& stone);

	void DrawPlayer(Player& player, sf::RenderWindow& window);
}
