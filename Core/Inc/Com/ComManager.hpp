/*
 * ComManager.hpp
 *
 *  Created on: 16 janv. 2022
 *      Author: colom
 */

#ifndef INC_COM_COMMANAGER_HPP_
#define INC_COM_COMMANAGER_HPP_


#include "../observers_types.hpp"

class ComManagerRx
{
public :
	void Notify() = 0;
};


class ComManagerTx
{
public :
	void Update() = 0;
};



#endif /* INC_COM_COMMANAGER_HPP_ */
