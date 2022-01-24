/*
 * Button.hpp
 *
 *  Created on: 16 janv. 2022
 *      Author: colom
 */

#ifndef INC_MIDIFIXTURE_BUTTON_HPP_
#define INC_MIDIFIXTURE_BUTTON_HPP_

#include "MidiFixture.hpp"
#include <iostream>




class Button : public MidiFixture
{

protected:
	uint8_t counterAdress;
	uint8_t muxAdress;

public:
};

class ButtonRedLed :  public Button
{
public : 
	/*Update Red Led State*/
	int Update(void * ptr) override;
	
protected:
	LedState _redLed;
	uint8_t _redLedColumn;
	uint8_t _redLedRow;

};


class ButtonGreenLed : public ButtonRedLed
{

public :
	int Update(void* ptr) override;
protected :
	LedState _greenLed ;
	uint8_t _greenLedColumn;
	uint8_t _greenLedRow ;


};

class ButtonNoLed :  public Button
{
public : 
	void ClassNotAbstract() {
		counterAdress = 5;
	};

protected : 
	uint8_t id;
};





#endif /* INC_MIDIFIXTURE_BUTTON_HPP_ */
