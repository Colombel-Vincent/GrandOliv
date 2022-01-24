/*
 * obervers_types.hpp
 *
 *  Created on: Jan 23, 2022
 *      Author: colom
 */

#ifndef INC_OBERVERS_TYPES_HPP_
#define INC_OBERVERS_TYPES_HPP_

#include "types_grandoliv3.hpp"

class IObserver
{
public:
 virtual ~IObserver(){};


virtual int Update(void * ptr) = 0 ;
};



class MidiEvent
{
public:
	 virtual ~MidiEvent(){};

	  
};

class eventSubscriber
{
	virtual void Notify() = 0;
	virtual void Attach(IObserver* observer) = 0;
	virtual void Detach(IObserver* observer) = 0;
};

class ComTxObserver : IObserver
{

};

class MidiFixtureEventClass : public IObserver, public MidiEvent
{

};

class ComRxEvent :   public MidiEvent
{

};










#endif /* INC_OBERVERS_TYPES_HPP_ */
