/*
 * ComManager.hpp
 *
 *  Created on: 16 janv. 2022
 *      Author: colom
 */

#ifndef INC_COM_COMMANAGER_HPP_
#define INC_COM_COMMANAGER_HPP_


#include "../observers_types.hpp"



class ComRx
{
public :
	 virtual int Notify(user::update_type_event evt, void* ptr) = 0;
};


class ComTx : IObserver
{
public :
	virtual int Update(user::update_type_event evt, void* ptr) =0;
	virtual void SendMsg();
};



#endif /* INC_COM_COMMANAGER_HPP_ */
