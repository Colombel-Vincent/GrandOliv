/*
 * builder.hpp
 *
 *  Created on: 9 févr. 2022
 *      Author: colom
 */

#ifndef INC_BUILDER_HPP_
#define INC_BUILDER_HPP_

#include "AbstractFactory.hpp"
#include "MidiFixture/Button.hpp"
#include "Com/ComMidiTx.hpp"
#include "Com/ComMidiRx.hpp"
#include "Com/ComUART.hpp"
#include "Com/ComI2C.hpp"

class Builder
{


public :
	Builder(Builder &other) = delete;

	Builder();

	 void operator=(const Builder &) = delete;

	 static Builder *GetInstance();

	 void * build(user::Midi_fixture_types key);

	 void * build(user::Com_types key);

protected :
	static Builder* m_builder;
	Factory<MidiFixtureImpl, user::Midi_fixture_types> m_midiFixtureBuilder;
	Factory<ComTx, user::Com_types> m_comBuilder;
	Factory<ComRx, user::Com_types> m_comRxBuilder;

};



#endif /* INC_BUILDER_HPP_ */
