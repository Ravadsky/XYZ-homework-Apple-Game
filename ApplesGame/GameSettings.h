#pragma once
#include <string>

namespace ApplesGame
{
	// Resources path
	const std::string RESOURCES_PATH = "Resources/";

	// Все константы вынесены в отдельный файл для удобства
	const float PLAYER_SIZE = 30.f;
	const float APPLE_SIZE = 13.3f;
	const float STONE_SIZE = 30.0f;
	const float INITIAL_SPEED = 120.f;
	const float ACCELERATION = 12.f;
	const int NUM_APPLES = 20;
	const int NUM_STONES = 10;
	const unsigned int SCREEN_WIDTH = 800;
	const unsigned int SCREEN_HEGHT = 600;
}
