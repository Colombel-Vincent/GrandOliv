/*
 * Buton.cpp
 *
 *  Created on: Jan 22, 2022
 *      Author: colom
 */

#include "../../Inc/MidiFixture/Button.hpp"


int ButtonGreenLed::Update(user::update_type_event evt, void* ptr)
{
	if (evt == user::update_type_event::LedGreenStatus)
	{
		_greenLed = *(user::LedState*)(uint8_t*) ptr;
		return 1;
	}
	else
		return ButtonRedLed::Update(evt, ptr);
	
}

int ButtonRedLed::Update(user::update_type_event evt, void* ptr)
{
	if (evt == user::update_type_event::LedGreenStatus)
	{
		_redLed = *(user::LedState*)(uint8_t*)ptr;
		return 1;
	}
	else
		return Button::Update(evt, ptr);

}

 ButtonRedLed::ButtonRedLed() : Button()
{
	 EventManager::GetInstance()->Attach(this, user::attach_type_event::ButtonRedLed);
}


bool ButtonRedLed::SetRedLedColumn(uint8_t value)
{
	 _redLedColumn = value;
	 return 1;
}
bool ButtonRedLed::SetRedLedRow(uint8_t value)
{
	 _redLedRow = value;
	 return 1;
}




//////Green LED
 ButtonGreenLed::ButtonGreenLed() : ButtonRedLed()
 {
	 EventManager::GetInstance()->Attach(this, user::attach_type_event::ButtonGreenLed);
 }

 bool ButtonGreenLed::SetGreenLedColumn(uint8_t value)
 {
	 _greenLedColumn = value;
	 return 1;
 }
 bool ButtonGreenLed::SetGreenLedRow(uint8_t value)
 {
	 _greenLedRow = value;
	 return 1;
 }

 ButtonNoLed::ButtonNoLed() : Button()
 {
	 
 }

 Button::Button()
 {
	 EventManager::GetInstance()->Attach(this, user::attach_type_event::Button);
 }




