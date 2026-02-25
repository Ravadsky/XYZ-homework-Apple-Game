#include "UI.h"
#include "Game.h"
#include <string>

namespace ApplesGame
{//Инициализировать интерфейс
	void InitUI(UIState& uiState, const sf::Font& font)
	{  //инициализировать текст очков (шрифт, размер шрифта и цвет)
		uiState.scoreText.setFont(font);
		uiState.scoreText.setCharacterSize(24);
		uiState.scoreText.setFillColor(sf::Color::Yellow);
		//инициализировать подсказку для ввода (шрифт, размер шрифта, цвет)
		uiState.inputHintText.setFont(font);
		uiState.inputHintText.setCharacterSize(24);
		uiState.inputHintText.setFillColor(sf::Color::White);
		//установить туда текст в кавычках. В задании 3 исправил стрелочки на ВАСД, тут тоже
		uiState.inputHintText.setString("Use WASD to move, Space to restart, ESC to exit");
		//И установить ориджин в углу подсказки
		uiState.inputHintText.setOrigin(GetTextOrigin(uiState.inputHintText, { 1.f, 0.f }));
		//Виден ли текст окончания игры
		uiState.isGameOverTextVisible = false;

		//инициализировать текст конца игры (шрифт, размер шрифта, цвет, стиль, надпись и ориджин)
		uiState.gameOverText.setFont(font);
		uiState.gameOverText.setCharacterSize(48);
		uiState.gameOverText.setStyle(sf::Text::Bold);
		uiState.gameOverText.setFillColor(sf::Color::Red);
		uiState.gameOverText.setString("GAME OVER");
		uiState.gameOverText.setOrigin(GetTextOrigin(uiState.gameOverText, { 0.5f, 0.5f }));
	}
	//Обновить интерфейс
	void UpdateUI(UIState& uiState, const struct GameState& gameState, float timeDelta)
	{
		//обновить количество очков (съеденных яблок)
		uiState.scoreText.setString("Apples eaten: " + std::to_string(gameState.numEatenApples));
		//Проверка, нужно ли выводить текст конца игры
		uiState.isGameOverTextVisible = gameState.isGameOver;
		//Покрасить игровое время в зависимости от того, закончилась ли игра или нет
		sf::Color gameOverTextColor = (int)gameState.timeSinceGameOver % 2? sf::Color::Red : sf::Color::Yellow;
		//установить заполняющий цвет
		uiState.gameOverText.setFillColor(gameOverTextColor);
	}
	//отрисовать интерфейс
	void DrawUI(UIState& uiState, sf::RenderWindow& window)
	{
		//нарисовать счетчик очков в левом верхнем углу
		uiState.scoreText.setPosition(10.f, 10.f);
		window.draw(uiState.scoreText);
		//нарисовать подсказку ввода в правом верхнем углу
		uiState.inputHintText.setPosition(window.getSize().x, 10.f);
		window.draw(uiState.inputHintText);
		//если игра закончена
		if (uiState.isGameOverTextVisible)
		{   //по центру нарисовать текст конца игры
			uiState.gameOverText.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
			window.draw(uiState.gameOverText);
		}
	}

}

