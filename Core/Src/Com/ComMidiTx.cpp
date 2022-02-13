/*
 * ComTxMidi.cpp
 *
 *  Created on: 13 févr. 2022
 *      Author: colom
 */


#include <Com/ComMidiTx.hpp>


 ComMidiTx::ComMidiTx()
{
	_bufferTx = (uint8_t*)malloc(sizeof(uint8_t)*100);
	_msgCount = 0;
}

int ComMidiTx::Update(user::update_type_event evt, void* ptr)
{
	switch(evt)
	{
		case user::update_type_event::MidiMsgTx :
			AddMsgInBufferTx(*(MidiMsg*) ptr);
			return 0;
		default :
			return 1;
	}

}


uint32_t   ComMidiTx::SerializeMidiMsg(MidiMsg  ptr)
{
	uint32_t  SerializeMsg;
	SerializeMsg = ptr.channel << 24;
	SerializeMsg = ptr.note<< 16;
	SerializeMsg = ptr.midi_event<< 8;
	SerializeMsg = ptr.value;
	return SerializeMsg;
}

void ComMidiTx::AddMsgInBufferTx(MidiMsg  ptr)
{
	//semaphore
	_bufferTx[_msgCount*4] = SerializeMidiMsg(ptr);
	_msgCount ++;
	//semaphore
}
int ComMidiTx::SendAllMidiData()
{
	SendMsg();
	return 0;
}
void ComMidiTx::SendMsg()
{
	//semaphore
	uint8_t * tempBuffer = (uint8_t *)malloc(sizeof(uint8_t)*_msgCount*4);
	memcpy(tempBuffer,_bufferTx,sizeof(uint8_t)*_msgCount*4);
	sendMidiMessage(tempBuffer,sizeof(tempBuffer));
	_msgCount = 0;
	//semaphore
}

