/*
 * ComI2C.hpp
 *
 *  Created on: 16 janv. 2022
 *      Author: colom
 */

#ifndef INC_COM_COMI2C_HPP_
#define INC_COM_COMI2C_HPP_

#include "ComManager.hpp"
class ComI2C : public  ComTx
{
	virtual int Update(user::update_type_event evt, void* ptr) {};
	virtual void SendMsg();
};



#endif /* INC_COM_COMI2C_HPP_ */
