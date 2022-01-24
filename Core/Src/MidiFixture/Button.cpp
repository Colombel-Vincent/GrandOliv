/*
 * Buton.cpp
 *
 *  Created on: Jan 22, 2022
 *      Author: colom
 */

#include "../../Inc/MidiFixture/Button.hpp"
#include "../types_grandoliv3.cpp"


int ButtonGreenLed::Update(void* ptr)
{
	LedState* _ldState = IsLedState(ptr);
		if (_ldState != nullptr)
		{
			_greenLed = *_ldState;
			return 0;
		}
	return 0;
}

int ButtonRedLed::Update(void* ptr)
{
	LedState* _ldState = IsLedState(ptr);
	if (_ldState != nullptr)
	{
		_redLed = *_ldState;
		return 1;
	}
	return 1;
}


