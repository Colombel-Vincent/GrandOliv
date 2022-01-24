/*
 * MidiFixture.cpp
 *
 *  Created on: Jan 20, 2022
 *      Author: colom
 */
#include "../../Inc/MidiFixture/MidiFixture.hpp"
#include "../types_grandoliv3.cpp"


int MidiFixture::SetChannel(uint8_t p_value)
{
	if(p_value > 0 && p_value < 16)
	{
		_channel = p_value;
		return 0;
	}
	return 1;
}

int MidiFixture::SetNote(uint8_t p_value)
{
	if(p_value > 0 && p_value < 127)
	{
		_channel = p_value;
		return 0;
	}
	return 1;
}

int MidiFixture::Update(void * ptr) // Function that update Midi fixture 
{
	MidiNoteEvent * _evt = IsMidiNoteEvent(ptr);
	if (_evt != nullptr) //if ptr is really a note event
	{
		_event = *_evt;
		return 0;
	}

	MidiConfiguration* _mdiconfig = IsMidiConfiguration(ptr);
	if (_evt != nullptr) //if ptr is really a midi Configuration
	{
		SetChannel (_mdiconfig->channel);
		SetNote( _mdiconfig->note);
		return 0;
	}
	return 1;
}


void MidiFixture::Notify() 
{
	
}


