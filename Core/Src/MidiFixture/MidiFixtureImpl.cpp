/*
 * MidiFixture.cpp
 *
 *  Created on: Jan 20, 2022
 *      Author: colom
 */
#include "../../Inc/MidiFixture/MidiFixtureImpl.hpp"




int MidiFixtureImpl::SetChannel(uint8_t p_value)
{
	int previousChannel = _channel;
	if( p_value < 16)
	{
		_channel = p_value;
		_id = _channel * _note;
		if (EventManager::GetInstance()->Notify(user::update_type_event::NewChannel, NULL)) // check that this modification is possible
		{
			_note = previousChannel;
			_id = _channel * _note;
			return 1;
		}
		return 0;
	}
	return 1;
}

int MidiFixtureImpl::SetNote(uint8_t p_value)
{
	int previousNote = _note;
	if( p_value < 127)
	{
		_note = p_value;
		_id = _channel * _note;
		if (EventManager::GetInstance()->Notify(user::update_type_event::NewChannel, NULL)) // check that this modification is possible
		{
			_note = previousNote;
			_id = _channel * _note;
			return 1;
		}
		return 0;
	}
	return 1;
}

int MidiFixtureImpl::Update(user::update_type_event evt, void* ptr) // Function that update Midi fixture 
{
	switch (evt)
	{
	case user::update_type_event::NewChannel :
		SetChannel(*(uint8_t*)ptr);
		return 1;

	case user::update_type_event::NewNote:
		SetNote(*(uint8_t*)ptr);
		return 1;
	default:
		return 0;
	}
	
	
	user::MidiNoteEvent* _evt=NULL; //= IsMidiNoteEvent(ptr);
	if (_evt != nullptr) //if ptr is really a note event
	{
		_event = *_evt;
		return 0;
	}

	MidiConfiguration* _mdiconfig = NULL;// = IsMidiConfiguration(ptr);
	if (_evt != nullptr) //if ptr is really a midi Configuration
	{
		SetChannel (_mdiconfig->channel);
		SetNote( _mdiconfig->note);
		return 0;
	}
	return 1;
}

 uint8_t MidiFixtureImpl::SetValue(uint8_t value) 
 {
	 
	 if (value < 127 && value!=_value)
	 {
		 if (value > 0)
			 _event = user::MidiNoteEvent::NoteOn;
		 else
			 _event = user::MidiNoteEvent::NoteOff;
		 _value = value;
		 SendMsgMidi();
		return 1;
	 }
	 return 0;
 }



 void MidiFixtureImpl::SendMsgMidi()
 {
	MidiMsg* mdi_msg = new MidiMsg;
	mdi_msg->channel = _channel;
	mdi_msg->note =  _note;
	mdi_msg->midi_event = (uint8_t)_event;
	mdi_msg->value = _value;
	EventManager::GetInstance()->Notify(user::update_type_event::MidiMsgTx, mdi_msg);
 }



