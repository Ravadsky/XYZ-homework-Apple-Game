// ©2023, XYZ School. All rights reserved.
// Authored by Aleksandr Rybalka (polterageist@gmail.com)
//Подключаем библиотеки SFML
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>

#include "Game.h"
//Пользуемся пространством имен по имени игры, чтобы при вызове функций или объектов из apple.cpp или game.cpp не дописывать ApplesGame::
using namespace ApplesGame;
//функция обработки событий
void HandleWindowEvents(sf::RenderWindow& window)
{
	sf::Event event;
	//Получить последнее событие, связанное с окном
	while (window.pollEvent(event))
	{
		// Если пытаются нажать на кнопку закрыть
		if (event.type == sf::Event::Closed)
		{//закрыть окно
			window.close();
		} //или если нажат эскейп клавиша
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
		{//закрыть окно
			window.close();
		}
	}
}

int main()
{
	// инициализация seed с помощью времени
	unsigned int seed = (unsigned int)time(nullptr);
	//Установить сид генерации значением из переменной seed
	srand(seed);

	//Инициализация важных сингл-тон объектов
	sf::RenderWindow window(sf::VideoMode(ApplesGame::SCREEN_WIDTH, ApplesGame::SCREEN_HEGHT), "AppleGame");
	ApplesGame::GameState gameState;

	//инициализируем игровые часы, а в LastTime записываем дельту времени
	sf::Clock game_clock;
	sf::Time lastTime = game_clock.getElapsedTime();

	//иницализируем игру
	InitGame(gameState);

	//Вызов меню настроек
	InitOptionUI(gameState.OptionsState, gameState.font);
	DrawOptionUI(gameState.OptionsState, window);

	while ((gameState.OptionsState.ContinueOptions == false) && window.isOpen())
	{
		HandleWindowEvents(window);
		//Если окно не открыто - вернуть 0, закончив игровой цикл.
		if (!window.isOpen())
		{
			return 0;
		}

		ApplesGame::HandleConsoleInput(gameState);
	}


	//инициализация интерфейса и шрифта.
	InitUI(gameState.uiState, gameState.font);
	//передача управления другой функции
	RestartGame(gameState);


	// начинается игровой цикл, пока окно открыто
	while (window.isOpen())
	{//обрабатываем события (закрыть окно или escape)
		HandleWindowEvents(window);
		//Если окно не открыто - вернуть 0, закончив игровой цикл.
		if (!window.isOpen())
		{
			return 0;
		}
		//принять управление игрока (стрелочки и пробел)
		HandleInput(gameState);

		// Посчитать дельту времени
		sf::Time currentTime = game_clock.getElapsedTime();
		float timeDelta = currentTime.asSeconds() - lastTime.asSeconds();
		lastTime = currentTime;
		//Обновить игровое состояние по дельта времени
		UpdateGame(gameState, timeDelta);

		//Очистить игровое окно, чтобы объекты не накладывались друг на друга с разных кадров
		window.clear();
		//Нарисовать актуальное игровое окно
		DrawGame(gameState, window);

		//Отобразить разом всё, когда все объекты дорисуются на окне
		window.display();
	}

	return 0;
}
