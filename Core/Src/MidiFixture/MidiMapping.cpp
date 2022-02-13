/*
 * MidiMapping.cpp
 *
 *  Created on: 9 févr. 2022
 *      Author: colom
 */


#include "MidiFixture/MidiMapping.hpp"

void createAllButton(std::vector<MidiFixture*> *  MdiList)
{
	for (int i =0 ; i<15 ;i++)
	{
		for (int g= 0 ; g<16 ; g++)
		{
			switch(ButtonTypeMapping[i*g])
			{
				case user::midi_fixture_types::Button_W_1Led :
				{
					ButtonRedLed *  Bt = (ButtonRedLed*)Builder::GetInstance()->build(user::Button_W_1Led);
					createNoLedButton(Bt);
					createRedLedButton(Bt);
					MdiList->push_back(Bt);
					break;
				}
				case user::midi_fixture_types::Button_W_2Led :
				{
					ButtonGreenLed *  Bt = (ButtonGreenLed*)Builder::GetInstance()->build(user::Button_W_2Led);
					createNoLedButton(Bt);
					createGreenLedButton(Bt);
					createRedLedButton(Bt);
					MdiList->push_back(Bt);
					break;
				}
				case user::midi_fixture_types::Button_W :
				{
					ButtonNoLed *  Bt = (ButtonNoLed*)Builder::GetInstance()->build(user::Button_W);
					createNoLedButton(Bt);
					MdiList->push_back(Bt);
					break;
				}
				case user::midi_fixture_types::Nothing :

					break;

				default :
					break;
			}
		}
	}
}

void createNoLedButton(MidiFixtureImpl * Bt)
{
	static int iterator =0;
	Bt->SetChannel(ButtonMidiMapping[iterator][0]);
	Bt->SetChannel(ButtonMidiMapping[iterator][1]);
	iterator ++;
}

void createRedLedButton(ButtonRedLed * Bt)
{
	static int iterator =0;
	Bt->SetRedLedColumn(ButtonRedLedMapping[iterator][0]);
	Bt->SetRedLedRow(ButtonRedLedMapping[iterator][1]);
	iterator ++;
}

void createGreenLedButton(ButtonGreenLed * Bt)
{
	static int iterator =0;
	Bt->SetGreenLedColumn(ButtonGreenLedMapping[iterator][0]);
	Bt->SetGreenLedRow(ButtonGreenLedMapping[iterator][1]);
	iterator ++;
}


