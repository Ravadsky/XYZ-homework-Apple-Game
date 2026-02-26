#include "Game.h"
#include "Math.h"
#include "BitOperations.h"
#include <assert.h>
#include <cstdlib>


//сделали пространство имен по названию игры
namespace ApplesGame
{ //функция инициализиации игровой сессии
	void InitGame(GameState& gameState)
	{
		// Инициализация игровых ассетов по их расположению в файлах
		assert(gameState.playerTexture.loadFromFile(RESOURCES_PATH + "Pacman.png"));
		assert(gameState.appleTexture.loadFromFile(RESOURCES_PATH + "Apple.png"));
		assert(gameState.font.loadFromFile(RESOURCES_PATH + "Fonts/Roboto-Regular.ttf"));
		assert(gameState.stoneTexture.loadFromFile(RESOURCES_PATH + "Stone.png"));
		assert(gameState.AppleSoundBuffer.loadFromFile(RESOURCES_PATH + "Apple.wav"));
		assert(gameState.DeathSoundBuffer.loadFromFile(RESOURCES_PATH + "Death.wav"));
		assert(gameState.GameOST.openFromFile(RESOURCES_PATH + "Music.wav"));

		gameState.AppleSound.setBuffer(gameState.AppleSoundBuffer);
		gameState.AppleSound.setVolume(0.4f);

		gameState.DeathSound.setBuffer(gameState.DeathSoundBuffer);
		gameState.DeathSound.setVolume(0.8f);

		gameState.GameOST.play();
		gameState.GameOST.setVolume(0.4f);
		gameState.GameOST.setLoop(true);

	}

	void RestartGame(GameState& gameState)
	{
		//вызвать инициализацию игрока
		InitPlayer(gameState.player, gameState.playerTexture);
		
		for (int i = 0; i < NUM_STONES; i++)
		{
			InitStone(gameState.stones[i], gameState.stoneTexture);
		}
		gameState.OptionsState.ApplesNumber = CheckBit(gameState.OptionsState.GameOptions, 0) ? (rand() % 80 + 20) : NUM_APPLES;

		gameState.apples.clear();
		// Цикл - инициализировать каждое яблоко
		for (int i = 0; i < gameState.OptionsState.ApplesNumber; i++)
		{
			gameState.apples.push_back(new Apple);
			InitApple(gameState.apples[i], gameState.appleTexture);
		}

		// Установить параметры объекта game.state
		gameState.numEatenApples = 0;
		gameState.isGameOver = false;
		gameState.timeSinceGameOver = 0.f;
	}

	//ввод событий 
	void HandleInput(GameState& gameState)
	{   //Если игра уже закончена
		if (gameState.isGameOver)
		{    //То надо нажать пробел
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{   //чтобы перезапустить игру
				RestartGame(gameState);
			}

			return;
		}
		//Блок проверки на стрелочки - в параметр направления устанавливается соответствующее направление
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			gameState.player.direction = PlayerDirection::Up;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			gameState.player.direction = PlayerDirection::Right;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			gameState.player.direction = PlayerDirection::Down;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			gameState.player.direction = PlayerDirection::Left;
		}
	}

	void HandleConsoleInput(GameState& gameState)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			SetBit(gameState.OptionsState.GameOptions, 0, true);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			SetBit(gameState.OptionsState.GameOptions, 0, false);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			SetBit(gameState.OptionsState.GameOptions, 1, true);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			SetBit(gameState.OptionsState.GameOptions, 1, false);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
		{
			SetBit(gameState.OptionsState.GameOptions, 2, true);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
		{
			SetBit(gameState.OptionsState.GameOptions, 2, false);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			gameState.OptionsState.ContinueOptions = true;
		}
	}
	//метод tick, обновляющий состояние игры каждый кадр
	void UpdateGame(GameState& gameState, float timeDelta)
	{ //если игра ещё не закончена
		if (!gameState.isGameOver)
		{
			// обновить игрока
			UpdatePlayer(gameState.player, timeDelta);
			//цикл - пройтись по каждому яблоку
			for (int i = 0; i < gameState.OptionsState.ApplesNumber; i++)
			{
				// Проверить было ли соприкосновение яблока и игрока
				if (HasPlayerCollisionWithApple(gameState.player, gameState.apples[i]))
				{
					// Если было - инициализировать яблоко в другой рандомной координате
					
					//if (gameState.OptionsState.isEndlessMode) InitApple(gameState.apples[i], gameState.appleTexture);
					if (CheckBit(gameState.OptionsState.GameOptions, 1)) InitApple(gameState.apples[i], gameState.appleTexture);
					else DeleteApple(gameState.apples[i]);

					gameState.AppleSound.play();
					// Прибавить к счетчику съеденных яблок
					gameState.numEatenApples++;
					// Увеличить скорость игрока на константу
					
					//if (gameState.OptionsState.isAccelerated) gameState.player.speed += ACCELERATION;
					if (CheckBit(gameState.OptionsState.GameOptions, 2)) gameState.player.speed += ACCELERATION;
					
				}
			}
			for (int i = 0; i < NUM_STONES; i++)
			{
				if (HasPlayerCollisionWithStone(gameState.player, gameState.stones[i]))
				{
				gameState.DeathSound.play();
				gameState.isGameOver = true;
				gameState.timeSinceGameOver = 0.f;
				}
			}

			// Проверка не врезался ли игрок в границы экрана
			if (HasPlayerCollisionWithScreenBorder(gameState.player))
			{
				//если да - закончить игру
				gameState.isGameOver = true;
				gameState.timeSinceGameOver = 0.f;
			}
		}
		else
		{
			//если же нет - то прибавлять к игровому времени разницу времен между прошедшим кадром и настоящим (дельту времени)
			gameState.timeSinceGameOver += timeDelta;
		}
		//обновить интерфейс
		UpdateUI(gameState.uiState, gameState, timeDelta);
	}
	//функция отрисовки игры
	void DrawGame(GameState& gameState, sf::RenderWindow& window)
	{
		// Сначала рисуем игрока
		DrawPlayer(gameState.player, window);
		// Затем в цикле рисуем каждое яблоко
		for (int i = 0; i < gameState.OptionsState.ApplesNumber; i++)
		{
			//здесь рисуется яблоко
			DrawApple(gameState.apples[i], window);
		}
		for (int i = 0; i < NUM_STONES; i++)
		{
			DrawStone(gameState.stones[i], window);
		}
		//Под конец обновляется интерфейс.
		DrawUI(gameState.uiState, window);
	}
}