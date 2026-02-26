#pragma once
#include <SFML/Graphics.hpp>

namespace ApplesGame
{
bool CheckBit(uint8_t& flags, int bitDepth);
//Устанавливает определенный флаг в переменной флагов. bitDepth - разрядность бита, где устанавливается флаг
void SetBit(uint8_t& flags, int bitDepth, bool flagValue);
}