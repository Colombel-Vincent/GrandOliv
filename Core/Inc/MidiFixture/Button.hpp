/*
 * Button.hpp
 *
 *  Created on: 16 janv. 2022
 *      Author: colom
 */

#ifndef INC_MIDIFIXTURE_BUTTON_HPP_
#define INC_MIDIFIXTURE_BUTTON_HPP_

#include "MidiFixtureImpl.hpp"

#include <iostream>
#include "../../Inc/EventManager.hpp"

class Button : public MidiFixtureImpl
{
public : 

	Button();
protected:
	uint8_t counterAdress;
	uint8_t muxAdress;

	inline virtual int Update(user::update_type_event evt, void* ptr) {return MidiFixtureImpl::Update(evt, ptr);}
public:
};

class ButtonRedLed :  public Button
{
public : 
	ButtonRedLed();
	void Notify() {};
	/*Update Red Led State*/
	virtual int  Update(user::update_type_event evt, void* ptr);
	
	inline uint8_t GetRedLedColumn(){return _redLedColumn;};
	inline uint8_t GetRedLedRow(){return _redLedRow;};
	inline uint8_t GetRedledState(){return _redLed;};


	bool SetRedLedColumn(uint8_t value);
	bool SetRedLedRow(uint8_t value);

protected:
	user::LedState _redLed;
	uint8_t _redLedColumn;
	uint8_t _redLedRow;

};


class ButtonGreenLed : public ButtonRedLed
{

public :
	ButtonGreenLed();
	void Notify() {};
	virtual int  Update(user::update_type_event evt, void* ptr) ;

	inline uint8_t GetGreenLedColumn(){return _greenLedColumn;};
	inline uint8_t GetGreenLedRow(){return _greenLedRow;};
	inline uint8_t GetGreenledState(){return _greenLed;};

	bool SetGreenLedColumn(uint8_t value);
	bool SetGreenLedRow(uint8_t value);

protected :
	user::LedState _greenLed ;
	uint8_t _greenLedColumn;
	uint8_t _greenLedRow ;


};

class ButtonNoLed :  public Button
{
public : 
	ButtonNoLed();
	void Notify() {};
	inline virtual int Update(user::update_type_event evt, void* ptr) { return Button::Update(evt, ptr); };
	

protected : 
	uint8_t id;
};





#endif /* INC_MIDIFIXTURE_BUTTON_HPP_ */
