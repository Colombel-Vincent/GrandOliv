/*
 * types_grandoliv3.hpp
 *
 *  Created on: 23 janv. 2022
 *      Author: colom
 */

#include <cstdint>
#ifndef INC_TYPES_GRANDOLIV3_HPP_
#define INC_TYPES_GRANDOLIV3_HPP_

typedef enum class MidiNoteEvent // enum for the différent state of note
{
	NoteOn,
	NoteOff,
	NotePress

	
}MidiNoteEvent;


typedef enum LedState // enum to represetn state of led
{
	LedOff,
	LedOn
}LedState;

typedef struct  MidiConfiguration // struct to configure a midiFixture
{
	uint8_t note;
	uint8_t channel;

}MidiConfiguration;


#endif /* INC_TYPES_GRANDOLIV3_HPP_ */
