/*
 * builder.cpp
 *
 *  Created on: 9 févr. 2022
 *      Author: colom
 */

#include "../Inc/Builder.hpp"
Builder * Builder::m_builder =NULL;

 Builder::Builder ()
 {
	 m_midiFixtureBuilder.Register(user::Midi_fixture_types::Button_W_2Led, new DerivedCreator<ButtonGreenLed, MidiFixtureImpl>);
	 m_midiFixtureBuilder.Register(user::Midi_fixture_types::Button_W_1Led, new DerivedCreator<ButtonRedLed, MidiFixtureImpl>);
	 m_midiFixtureBuilder.Register(user::Midi_fixture_types::Button_W, new DerivedCreator<ButtonNoLed, MidiFixtureImpl>);
	 m_midiFixtureBuilder.Register(user::Midi_fixture_types::Button_W, new DerivedCreator<ButtonNoLed, MidiFixtureImpl>);

	 m_comBuilder.Register(user::Com_types::com_midiTx, new DerivedCreator<ComMidiTx, ComTx>);
	 m_comBuilder.Register(user::Com_types::com_UART, new DerivedCreator<ComUART, ComTx>);
	 m_comBuilder.Register(user::Com_types::com_I2C, new DerivedCreator<ComI2C, ComTx>);

	 m_comRxBuilder.Register(user::Com_types::com_midiRx, new DerivedCreator<ComMidiRx, ComRx>);

 }

  Builder* Builder::GetInstance()
 {
	if(m_builder==nullptr){
		m_builder = new Builder();
		}
	return m_builder;
 }

 void * Builder::build(user::Midi_fixture_types key)
 {
	 return m_midiFixtureBuilder.Create( key);
 }

 void * Builder::build(user::Com_types key)
 {
	 if(key== user::Com_types::com_midiRx)
		 return m_comRxBuilder.Create( key);
	 return m_comBuilder.Create( key);
 }
