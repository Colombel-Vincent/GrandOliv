/*
 * EventManager.cpp
 *
 *  Created on: Jan 20, 2022
 *      Author: colom
 */


#include "../Inc/EventManager.hpp"



 EventManager * EventManager::GetInstance()
{
	if(_eventManager==nullptr){
		_eventManager = new EventManager(5);
	    }
	return _eventManager;
}

