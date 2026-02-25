#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Apple.h"
#include "Stone.h"
#include "UI.h"
#include "GameSettings.h"
#include "GameOptions.h"
#include <Vector>

namespace ApplesGame
{
	//Новая структура - игровое состояние, в нём глобальные параметры
	struct GameState
	{
		Player player;
		std::vector<Apple*> apples;
		Stone stones[NUM_STONES];
		int numEatenApples = 0;
		UIState uiState;
		GameOptionsState OptionsState;
		bool isGameOver = false;
		float timeSinceGameOver = 0.f;

		// Так же ссылки на игровые ассеты. У всех яблок получается 1 текстурный объект - этакое инстанцирование?
		sf::Font font;
		sf::Texture playerTexture;
		sf::Texture appleTexture;
		sf::Texture stoneTexture;
		sf::SoundBuffer AppleSoundBuffer;
		sf::Sound AppleSound;
		sf::SoundBuffer DeathSoundBuffer;
		sf::Sound DeathSound;
		sf::Music GameOST;
	};
	//Прототипы основных функций кор геймплея
	void InitGame(GameState& gameState);
	void RestartGame(GameState& gameState);
	void HandleInput(GameState& gameState);
	void HandleConsoleInput(GameState& gameState);
	void UpdateGame(GameState& gameState, float timeDelta);
	void DrawGame(GameState& gameState, sf::RenderWindow& window);
}
