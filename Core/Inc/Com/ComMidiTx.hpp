/*
 * ComTxMidi.hpp
 *
 *  Created on: Jan 23, 2022
 *      Author: colom
 */

#ifndef INC_COM_COMMIDITX_HPP_
#define INC_COM_COMMIDITX_HPP_

#include "usbd_midi.h"
#include "usbd_midi_if.h"
#include "ComManager.hpp"

class ComMidiTx : public ComTx
{
public :
	 int  Update(user::update_type_event evt, void* ptr);
	  ComMidiTx();
	int SendAllMidiData();
	void AddMsgInBufferTx(MidiMsg ptr);
	uint32_t  SerializeMidiMsg(MidiMsg ptr);
	virtual void SendMsg();

private :
	uint8_t*  _bufferTx;
	uint8_t _msgCount;

};




#endif /* INC_COM_COMMIDITX_HPP_ */
