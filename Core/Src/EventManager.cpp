/*
 * EventManager.cpp
 *
 *  Created on: Jan 20, 2022
 *      Author: colom
 */


#include "../Inc/EventManager.hpp"
#include <algorithm>
EventManager * EventManager::_eventManager =NULL;

 EventManager * EventManager::GetInstance()
{
	if(_eventManager==nullptr){
		_eventManager = new EventManager;
	    }
	return _eventManager;
}

 /*notify manager*/
 int EventManager::Notify(user::update_type_event evt, void* ptr)
 {
	 switch (evt)
	 {
	 case user::update_type_event::MidiMsgTx:
		 _ComMidi->Update(evt, ptr);
	 case  user::update_type_event::NewNote:
		 return UpdateAllFixtureList(); // Update all the list to sort in croissant order
	 case  user::update_type_event::NewChannel:
		 return UpdateAllFixtureList();
	 case  user::update_type_event::MidiMsgRx:
		 MidiFixtureSubscriberList.at(1)->Update(evt, ptr);
	 default:
		 break;
	 }
	 return 0;
 }


 int EventManager::UpdateAllFixtureList()
 {
	 int err = 0;
	 if (CheckDuplicatesInMidiSubscribersList(&RedLedSubscriberList))
		 return 1;
	 if (CheckDuplicatesInMidiSubscribersList(&GreenLedSubscriberList))
		 return 1;
	 if (CheckDuplicatesInMidiSubscribersList(&MidiFixtureSubscriberList))
		 return 1;
	 SortMidiFixtureSubsrciberList(&RedLedSubscriberList);
	 SortMidiFixtureSubsrciberList(&GreenLedSubscriberList);
	 SortMidiFixtureSubsrciberList(&MidiFixtureSubscriberList);
	 UpdateIndexOfMidiFixture();
	 return 0;
 }


 void EventManager::UpdateIndexOfMidiFixture()
 {
	 for (int i = 0; i < 16; i++)
		 for (int g = 0; g < 127; g++)
			 MidiFixtureIndex[i][g] = 0;

	for (auto * it : MidiFixtureSubscriberList)
	{
		MidiFixtureIndex[it->GetChannel()][it->GetNote()] = FindMidiFixtureInSubcriber(&MidiFixtureSubscriberList, it);
	}

 }

 int EventManager::CheckDuplicatesInMidiSubscribersList(std::vector<MidiFixture*>* p_subsriberList)
 {
	 for (auto it : *p_subsriberList)
	 {
		 for (auto it2 : *p_subsriberList)
			 if (it != nullptr && it2 != nullptr)
			 {
				 if (it->GetId() == it2->GetId() && it != it2) // if multiple same key
				 {
					 return 1;
				 }
			 }
	 }
	 return 0;
 }


 int EventManager::Attach(void* ptr, user::attach_type_event evt)
 {

	 switch (evt)
	 {
	 case user::attach_type_event::ButtonGreenLed:
		 AddMidiFixtureInSubscriber(&GreenLedSubscriberList, (MidiFixture*)ptr);
		 AddMidiFixtureInSubscriber(&MidiFixtureSubscriberList, (MidiFixture*)ptr);

	 case user::attach_type_event::ButtonRedLed:
		 AddMidiFixtureInSubscriber(&RedLedSubscriberList, (MidiFixture*)ptr);
		 AddMidiFixtureInSubscriber(&MidiFixtureSubscriberList, (MidiFixture*)ptr);

	 case user::attach_type_event::Button:
		 AddMidiFixtureInSubscriber(&MidiFixtureSubscriberList, (MidiFixture*)ptr);

	 case user::attach_type_event::ComI2C:
		 if(_ComI2C==NULL)
			 return 1;
		 _ComI2C = (ComTx*)ptr;
	 case user::attach_type_event::ComUART:
		 if(_ComUart==NULL)
			 return 1;
		 _ComUart = (ComTx*)ptr;
	 case user::attach_type_event::ComMidi:
		 if(_ComMidi==NULL)
			 return 1;
		 _ComMidi = (ComTx*)ptr;
	 }

	 return 0;
 }


 /**/
 int EventManager::SortMidiFixtureSubsrciberList(std::vector<MidiFixture*>* p_subsriberList)
 {
	 std::sort(p_subsriberList->begin(), p_subsriberList->end());
	 return 0;
 }

 /**/
 void EventManager::AddMidiFixtureInSubscriber(std::vector<MidiFixture*>* p_subsriberList, MidiFixture* p_mdiFx,bool indexingMidiFixture)
 {
	 p_subsriberList->push_back(p_mdiFx);
	 SortMidiFixtureSubsrciberList(p_subsriberList);

	 if (indexingMidiFixture)
		 MidiFixtureIndex[p_mdiFx->GetChannel()][p_mdiFx->GetNote()] = FindMidiFixtureInSubcriber(p_subsriberList, p_mdiFx);
 }

 void EventManager::DeleteMidiFixtureInSubscriber(std::vector<MidiFixture*>* p_subsriberList, MidiFixture* p_mdiFx, bool eraseIndexingMidiFixture)
 {

	 int offset = FindMidiFixtureInSubcriber(p_subsriberList, p_mdiFx);
	 p_subsriberList->erase(p_subsriberList->begin() + offset);

	 if (eraseIndexingMidiFixture)
		 MidiFixtureIndex[p_mdiFx->GetChannel()][p_mdiFx->GetNote()] = DEFAULT_VALUE_INDEX;
 }

 int EventManager::FindMidiFixtureInSubcriber(std::vector<MidiFixture*>* p_subsriberList, MidiFixture* p_mdiFx)
 {
	 int index = 0;
	 for (auto it : *p_subsriberList)
	 {
		 if (it == p_mdiFx)
			 return index;
		 index++;
	 }
	 return -1;
 }


 int EventManager::Detach(void* ptr, user::attach_type_event evt)
 {
	 switch (evt)
	 {
	 case user::attach_type_event::ButtonGreenLed:
		 DeleteMidiFixtureInSubscriber(&GreenLedSubscriberList, (MidiFixture*)ptr);
	 case user::attach_type_event::ButtonRedLed:
		 DeleteMidiFixtureInSubscriber(&RedLedSubscriberList, (MidiFixture*)ptr);
	 case user::attach_type_event::Button:
		 DeleteMidiFixtureInSubscriber(&MidiFixtureSubscriberList, (MidiFixture*)ptr);
	 case user::attach_type_event::ComMidi:
		 _ComMidi =NULL;
	 case user::attach_type_event::ComI2C:
		 _ComI2C =NULL;
	 case user::attach_type_event::ComUART:
		 _ComUart =NULL;
	 }
	 return 0;
 }
