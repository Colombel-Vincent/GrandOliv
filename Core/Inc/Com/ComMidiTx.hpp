/*
 * ComTxMidi.hpp
 *
 *  Created on: Jan 23, 2022
 *      Author: colom
 */

#ifndef INC_COM_COMMIDITX_HPP_
#define INC_COM_COMMIDITX_HPP_

#ifndef SIMULATION
#include "../../../USB_DEVICE/Target/usbd_conf.h"
#include "../../../USB_DEVICE/App/usbd_midi_if.h"
#endif

#include "ComManager.hpp"

class ComMidiTx : public ComTx
{
public :
	ComMidiTx();
	 int  Update(user::update_type_event evt, void* ptr);
	int SendAllMidiData();
	void AddMsgInBufferTx(MidiMsg ptr);
	uint32_t  SerializeMidiMsg(MidiMsg ptr);
	 void SendMsg();

private :
	uint8_t*  _bufferTx;
	uint8_t _msgCount;

};




#endif /* INC_COM_COMMIDITX_HPP_ */
