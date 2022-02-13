

#include <iostream>
#include "../../../../Core/Inc/AbstractFactory.hpp"
#include "../../../../Core/Inc/MidiFixture/Button.hpp"
#include "../../../../Core/Inc/MidiFixture/MidiFixtureImpl.hpp"
#include "../../../../Core/Inc/EventManager.hpp"



EventManager* EventManager::_eventManager = nullptr;

int main()
{
    
    Factory<MidiFixtureImpl, std::string> temp;
    temp.Register("B2L", new DerivedCreator<ButtonGreenLed, MidiFixtureImpl>);
    temp.Register("B1L", new DerivedCreator<ButtonRedLed, MidiFixtureImpl>);
    temp.Register("BNL", new DerivedCreator<ButtonNoLed, MidiFixtureImpl>);

    
    MidiFixtureImpl * pBase1 = temp.Create("B1L");
    pBase1->SetChannel(5);
    MidiFixtureImpl * pBase2 = temp.Create("B1L");
    pBase2->SetChannel(4);
    MidiFixtureImpl* pBase5 = temp.Create("B1L");
    pBase5->SetChannel(6);
    MidiFixtureImpl* pBase4 = temp.Create("B1L");
    pBase4->SetChannel(3);
    MidiFixtureImpl* pBase8 = temp.Create("B1L");
    pBase8->SetChannel(10);
    MidiFixtureImpl * pBase3 = temp.Create("BNL");
    EventManager* evt = EventManager::GetInstance();
    MidiMsg* mdiMsg = new MidiMsg;
    mdiMsg->midi_event = 5;
    mdiMsg->note = 5;
    mdiMsg->value = 5;
    mdiMsg->channel = 5;
    evt->notify(user::update_type_event::MidiMsgRx,(void *) mdiMsg);
    evt->update((IObserver *)pBase1);
    user::MidiNoteEvent* test = new user::MidiNoteEvent;

        
    return 0;
}

