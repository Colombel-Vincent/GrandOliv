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


 class MidiFixture : public MidiFixtureEventClass
{
public :
	int SetChannel(uint8_t p_value) ;
	int SetNote(uint8_t p_value) ;

	inline uint8_t GetNote(){return _value;};
	inline uint8_t GetChannel(){return _channel;};

	int Update(void* ptr) ;

	virtual void Attach(IObserver* observer) {};
	virtual void Detach(IObserver* observer) {};
	virtual void Notify();

protected :
	 uint8_t _value ; // midi value [0 ... 127]
	 uint8_t _note; // midi note [0 ... 127]
	 uint8_t _channel; // midi Channel [0 ... 16]
	 MidiNoteEvent _event; //midi event
	 bool _sent; // to specify if the MidiFicture as been sent
};




#endif /* INC_MIDIFIXTURE_HPP_ */
