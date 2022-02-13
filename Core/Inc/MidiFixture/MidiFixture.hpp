/*
 * MidiFixture.hpp
 *
 *  Created on: 16 janv. 2022
 *      Author: colom
 */

#ifndef INC_MIDIFIXTURE_HPP_
#define INC_MIDIFIXTURE_HPP_

#include <stdint.h>
#include "../observers_types.hpp"
#include "../../Src/types_grandoliv3.cpp"


 class MidiFixture : public MidiFixtureEventClass
{
public :
	/*setter */
	virtual int SetChannel(uint8_t p_value) { return 0; };
	virtual int SetNote(uint8_t p_value) { return 0; };

	/*Getter*/
	virtual uint8_t GetId() { return 0; };
	virtual uint8_t GetNote() { return 0; };
	virtual uint8_t GetChannel() { return 0; };

	/*This method should notify eventManager*/
	virtual uint8_t SetValue(uint8_t value) {return 0;}

	virtual void SendMsgMidi() {  };

	virtual int Update(user::update_type_event evt, void* ptr) { return 0; };
	/*operator*/
	 friend  bool operator<(MidiFixture a,MidiFixture b) ;
	 friend  bool operator>(MidiFixture a, MidiFixture b) ;
	
protected :
	 uint8_t _id =1; // MidiFixture ID
	 uint8_t _value ; // midi value [0 ... 127]
	 uint8_t _note = 1; // midi note [0 ... 127]
	 uint8_t _channel= 1 ; // midi Channel [0 ... 16]
	 user::MidiNoteEvent _event; //midi event
	 bool _sent; // to specify if the MidiFicture as been sent
};


inline  bool operator <(MidiFixture a,MidiFixture b)
 {
	 return  (a.GetNote() * a.GetNote()) < (b.GetNote() * b.GetChannel());
 };

inline  bool operator >(MidiFixture a, MidiFixture b)
{
	return  (a.GetNote() * a.GetNote()) > (b.GetNote() * b.GetChannel());
};



#endif /* INC_MIDIFIXTURE_HPP_ */
