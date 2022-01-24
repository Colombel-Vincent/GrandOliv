/*
 * types_grandoliv3.cpp
 *
 *  Created on: 23 janv. 2022
 *      Author: colom
 */

#include "../Inc/types_grandoliv3.hpp"

template <typename T>
MidiNoteEvent * IsMidiNoteEvent(T* ptr)
{
	return nullptr;
};

template <>
MidiNoteEvent* IsMidiNoteEvent(MidiNoteEvent* ptr)
{
	return ptr;
};


template <typename T>
MidiConfiguration* IsMidiConfiguration(T* ptr)
{
	return nullptr;
};

template <>
MidiConfiguration* IsMidiConfiguration(MidiConfiguration* ptr)
{
	return ptr;
};


template <typename T>
LedState* IsLedState(T* ptr)
{
	return nullptr;
};

template <>
LedState* IsLedState(LedState* ptr)
{
	return ptr;
};
