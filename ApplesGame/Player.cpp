#include "Player.h"
#include <assert.h>
#include "GameSettings.h"
#include "Apple.h"
#include "Stone.h"

//Пространство имён по имени игрового проекта
namespace ApplesGame
{ //Инициализировать игрока
	void InitPlayer(Player& player, const sf::Texture& texture)
	{
		//Расположить игрока в центре экрана
		player.position.x = (float)SCREEN_WIDTH / 2.f;
		player.position.y = (float)SCREEN_HEGHT / 2.f;
		//Присвоить ему начальную скорость из константы
		player.speed = INITIAL_SPEED;
		//Начальное направление - вверх
		player.direction = PlayerDirection::Up;

		//Инициализировать спрайт игрока
		player.sprite.setTexture(texture);
		//Установить ориджин в центре текстуры
		player.sprite.setOrigin(GetSpriteOrigin(player.sprite, { 0.5f, 0.5f }));
		//установить скейл по константе PLAYER_SIZE
		player.sprite.setScale(GetSpriteScale(player.sprite, { PLAYER_SIZE, PLAYER_SIZE }));
	}
	//Обновить состояние игрока
	void UpdatePlayer(Player& player, float timeDelta)
	{
		// Свич по направлению движения, полученной из обраотчика ввода
		switch (player.direction)
		{   //Если вверх
		case PlayerDirection::Up:
		{//То уменьшаем у на дельту времени * скорость
			player.position.y -= player.speed * timeDelta;
			break;
		}
		//Если вправо
		case PlayerDirection::Right:
		{//То увеличиваем х на дельту времени * скорость
			player.position.x += player.speed * timeDelta;
			break;
		}
		//Если вниз
		case PlayerDirection::Down:
		{ //то увеличиваем у на дельту времени * скорость
			player.position.y += player.speed * timeDelta;
			break;
		}
		//Если влево
		case PlayerDirection::Left:
		{ //то уменьшаем х на дельту времени * скорость
			player.position.x -= player.speed * timeDelta;
			break;
		}
		}
	}
	//функция проверки коллизии с границами экрана
	bool HasPlayerCollisionWithScreenBorder(const Player& player)
	{   /*Сложное булевое вычисление, если х не меньше 0, если у не меньше нуля, если х не больше ширины экрана и если у не больше высоты экрана.
		Но там ещё берется в расчет что от центра игрока в сторону ещё половина спрайта место занимает*/
		return (player.position.x - PLAYER_SIZE / 2.f < 0) ||
			(player.position.x + PLAYER_SIZE / 2.f > SCREEN_WIDTH) ||
			(player.position.y - PLAYER_SIZE / 2.f < 0) ||
			(player.position.y + PLAYER_SIZE / 2.f > SCREEN_HEGHT);
	}
	//Проверить коллизию с яблоком
	bool HasPlayerCollisionWithApple(const Player& player, const Apple* apple)
	{//В локальные переменные dx xy ввести дельту расстояния, посчитать дистанцию как гипотенузу по катетам. Если дистанция меньше чем половинки их спрайтов - то коллизия была
		float dx = player.position.x - apple->position.x;
		float dy = player.position.y - apple->position.y;
		float distance = sqrt(dx * dx + dy * dy);
		return distance < (PLAYER_SIZE + APPLE_SIZE) / 2.f;
	}

	bool HasPlayerCollisionWithStone(const Player& player, const Stone& stone)
	{
		float dx = player.position.x - stone.position.x;
		float dy = player.position.y - stone.position.y;
		float distance = sqrt(dx * dx + dy * dy);
		return distance < (PLAYER_SIZE + STONE_SIZE) / 2.f;
	}


	//Отрисовать игрока
	void DrawPlayer(Player& player, sf::RenderWindow& window)
	{   //Установить позицию для спрайта по позиции игрока
		player.sprite.setPosition(OurVectorToSf(player.position));
		//Установить константу для скейла спрайта, чтобы не высчитывать много раз
		const sf::Vector2f spriteScale = (GetSpriteScale(player.sprite, { PLAYER_SIZE, PLAYER_SIZE }));

		//в зависимости от направления
		switch (player.direction)
		{//Если вверх
			case PlayerDirection::Up:
			{  //установить нормальный скейл
				player.sprite.setScale(spriteScale.x, spriteScale.y);
				//повернуть на 90 градусов против часовой стрелки 
				player.sprite.setRotation(-90.f);
				break;
			}// если вправо
			case PlayerDirection::Right:
			{//установить нормальный скейл
				player.sprite.setScale(spriteScale.x, spriteScale.y);
				//не поворачивать, т.к изначально спрайт нарисован вправо
				player.sprite.setRotation(0.f);
				break;
			}//если вниз
			case PlayerDirection::Down:
			{ //установить нормальный скейл
				player.sprite.setScale(spriteScale.x, spriteScale.y);
				//Повернуть спрайт на 90 градусов по часовой стрелке
				player.sprite.setRotation(90.f);
				break;
			} //если влево
			case PlayerDirection::Left:
			{  //Вывернуть спрайт по х, отзеркалив его
				player.sprite.setScale(-spriteScale.x, spriteScale.y);
				//не поворачивать спрайт
				player.sprite.setRotation(0.f);
				break;
			}
		}
		//Нарисовать игрока на экране
		window.draw(player.sprite);
	}
}
