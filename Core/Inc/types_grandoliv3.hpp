/*
 * types_grandoliv3.hpp
 *
 *  Created on: 23 janv. 2022
 *      Author: colom
 */

#include <cstdint>
#ifndef INC_TYPES_GRANDOLIV3_HPP_
#define INC_TYPES_GRANDOLIV3_HPP_

namespace user
{
	typedef enum class com // enum for the diff�rent state of note
	{
		MidiTx

	}com;
	typedef enum class MidiNoteEvent // enum for the diff�rent state of note
	{
		NoteOn,
		NoteOff,
		LedOn,
		LedOff,
		NotePress
	}MidiNoteEvent;

	typedef enum class attach_type_event // enum for the diff�rent state of note
	{
		MidiFixtureImpl,
		Button,
		Fader,
		Encodeur,
		ButtonGreenLed,
		ButtonRedLed,
		ComI2C,
		ComUART,
		ComMidi
	}attach_type_event;

	typedef enum LedState // enum to represetn state of led
	{
		LedOff,
		LedOn
	}LedState;

	typedef enum  update_type_event // struct of midiMsg
	{
		NewAdressSubscriber,
		NewChannel,
		NewNote,
		Mute,
		LedGreenStatus,
		LedRedStatus,
		LedFaderStatus,
		MidiMsgRx,
		MidiMsgTx

	}update_type_event;
	typedef enum  Midi_fixture_types //
	{
		Button_W_1Led,
		Button_W_2Led,
		Button_W,
		Nothing


	}midi_fixture_types;

	typedef enum  Com_types //
	{
		com_midiTx,
		com_midiRx,
		com_I2C,
		com_UART


	}Com_types;

};


typedef struct  MidiMsg // struct of midiMsg
{
	uint8_t note;
	uint8_t channel;
	uint8_t midi_event;
	uint8_t value;
}MidiMsg;

typedef struct  MidiConfiguration // struct to configure a midiFixture
{
	uint8_t note;
	uint8_t channel;

}MidiConfiguration;
MidiMsg* unserialCharWithMsgMidi(uint8_t* msg);




#endif /* INC_TYPES_GRANDOLIV3_HPP_ */
