#include "BitOperations.h"

namespace ApplesGame
{
	bool CheckBit(uint8_t& flags, int bitDepth)
	{
		return flags & (1 << bitDepth);
	}

	void SetBit(uint8_t& flags, int bitDepth, bool flagValue)
	{
		//в зависимости от значения флага (0,1) происходит вставка значения в нужный бит (bitDepth). 
		flagValue ? flags |= (1 << bitDepth) : flags &= ~(1 << bitDepth);
	}
}

