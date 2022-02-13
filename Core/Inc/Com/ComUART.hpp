/*
 * ComUart.hpp
 *
 *  Created on: 16 janv. 2022
 *      Author: colom
 */

#ifndef INC_COM_COMUART_HPP_
#define INC_COM_COMUART_HPP_

#include "ComManager.hpp"
class ComUART : public ComTx
{
public:
	virtual int Update(user::update_type_event evt, void* ptr) { return 1; };
	virtual void SendMsg() {};
};



#endif /* INC_COM_COMUART_HPP_ */
