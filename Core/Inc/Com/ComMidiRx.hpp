/*
 * ComMidi.hpp
 *
 *  Created on: Jan 20, 2022
 *      Author: colom
 */

#ifndef INC_COM_COMMIDI_HPP_
#define INC_COM_COMMIDI_HPP_

#include "ComManager.hpp"


class ComMidiRx : public ComRx
{
	 virtual int Notify(user::update_type_event evt, void* ptr) {};
};


#endif /* INC_COM_COMMIDI_HPP_ */
