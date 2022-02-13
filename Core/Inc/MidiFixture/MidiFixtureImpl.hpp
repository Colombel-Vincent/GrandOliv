/*
 * MidiFixture.hpp
 *
 *  Created on: 16 janv. 2022
 *      Author: colom
 */

#ifndef INC_MIDIFIXTUREIMPL_HPP_
#define INC_MIDIFIXTUREIMPL_HPP_

#include <stdint.h>
#include "MidiFixture.hpp"
#include "../EventManager.hpp"

 class MidiFixtureImpl : public MidiFixture
{
public :
	/*setter */
	int SetChannel(uint8_t p_value) override;
	int SetNote(uint8_t p_value) override;

	/*Getter*/
	inline uint8_t GetId()override { return _id; };
	inline uint8_t GetNote()override {return _note;};
	inline uint8_t GetChannel()override {return _channel;};

	void SendMsgMidi();
	virtual uint8_t SetValue(uint8_t value);
	/*Update*/
	int Update(user::update_type_event evt, void* ptr);

	/*operator*/
	friend  bool operator<(MidiFixtureImpl a,MidiFixtureImpl b);
	friend  bool operator>(MidiFixtureImpl a, MidiFixtureImpl b);
	
protected :

};


inline  bool operator <(MidiFixtureImpl a,MidiFixtureImpl b)
 {
	 return  (a.GetNote() * a.GetNote()) < (b.GetNote() * b.GetChannel());
 };

inline  bool operator >(MidiFixtureImpl a, MidiFixtureImpl b)
{
	return  (a.GetNote() * a.GetNote()) > (b.GetNote() * b.GetChannel());
};



#endif /* INC_MIDIFIXTURE_HPP_ */
