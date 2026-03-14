#include "Utils.h"

namespace ApplesGame
{


void AddStringToText(sf::Text& textRef, std::string newString)
{
	textRef.setString(textRef.getString() + newString + "\n");
}

}
