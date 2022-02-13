/*
 * Publisher.hpp
 *
 *  Created on: 16 janv. 2022
 *      Author: colom
 */

#ifndef INC_PUBLISHER_HPP_
#define INC_PUBLISHER_HPP_

class Publisher
{
public:
	Publisher ()
	{
		m_publisher = new Publisher;
	}

	Publisher * getPublicherInstance()
	{
		return m_publisher;
	}

private :
	Publisher * m_publisher;

};



#endif /* INC_PUBLISHER_HPP_ */
