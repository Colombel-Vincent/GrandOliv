/*
 * obervers_types.hpp
 *
 *  Created on: Jan 23, 2022
 *      Author: colom
 */

#ifndef INC_OBERVERS_TYPES_HPP_
#define INC_OBERVERS_TYPES_HPP_


#include "types_grandoliv3.hpp"

class IObserver
{
public:
 virtual ~IObserver(){};


virtual int Update(user::update_type_event evt,void * ptr) = 0 ;
};




#endif /* INC_OBERVERS_TYPES_HPP_ */
