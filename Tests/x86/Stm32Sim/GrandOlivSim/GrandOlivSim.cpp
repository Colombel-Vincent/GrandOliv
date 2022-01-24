

#include <iostream>
#include "../../../../Core/Inc/AbstractFactory.hpp"
#include "../../../../Core/Inc/MidiFixture/Button.hpp"
#include "../../../../Core/Inc/MidiFixture/MidiFixture.hpp"
#include "../../../../Core/Inc/EventManager.hpp"



EventManager* EventManager::_eventManager = nullptr;

int main()
{
    
    Factory<MidiFixture, std::string> temp;
    temp.Register("B", new DerivedCreator<Button, MidiFixture>);
    temp.Register("B2L", new DerivedCreator<ButtonGreenLed, MidiFixture>);
    temp.Register("B1L", new DerivedCreator<ButtonRedLed, MidiFixture>);
    temp.Register("BNL", new DerivedCreator<ButtonNoLed, MidiFixture>);

    MidiFixture * pBase  = temp.Create("B");
    MidiFixture * pBase1 = temp.Create("B2L");
    MidiFixture * pBase2 = temp.Create("B1L");
    MidiFixture * pBase3 = temp.Create("BNL");
    EventManager* evt = EventManager::GetInstance();
    evt->update((IObserver *)pBase);
    MidiNoteEvent* test = new MidiNoteEvent;

        
    return 0;
}

