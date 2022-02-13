/*
 * Observer.hpp
 *
 *  Created on: Jan 20, 2022
 *      Author: colom
 */

#ifndef INC_OBSERVER_HPP_
#define INC_OBSERVER_HPP_

#include <vector>

#include <list>

#include "MidiFixture/MidiFixture.hpp"
#include "Com/ComManager.hpp"

class eventSubscriber
{

    virtual int Attach(void* ptr, user::attach_type_event evt) = 0;
    virtual int Detach(void* ptr, user::attach_type_event evt) = 0;
};

/*This class manage all the event that comme from midi reception and update on the current event all the involved classes*/
class EventManager : eventSubscriber
{
protected:
    const uint8_t DEFAULT_VALUE_INDEX = 255;
	
    EventManager() 
    {

        for (int i = 0; i < 16; i++)
            for (int g = 0; g < 127; g++)
                MidiFixtureIndex[i][g] = DEFAULT_VALUE_INDEX;

        _ComMidi =NULL;
        _ComUART =NULL;
        _ComI2C =NULL;

    };

    static EventManager* _eventManager;
    uint8_t test;
public:

    EventManager(EventManager &other) = delete;

    void operator=(const EventManager &) = delete;

    static EventManager *GetInstance();

    void Update(IObserver * test) {

    }

    int Notify (user::update_type_event evt, void* ptr) ;
    int Attach(void* ptr,user:: attach_type_event evt) ;
    int Detach(void* ptr, user::attach_type_event evt) ;

    void ExecuteTx();
    void midiMsgManager(MidiMsg* msg);
    
private :

    /*Add MidiFxiture in a subscriber list*/
    void AddMidiFixtureInSubscriber(std::vector<MidiFixture*>* p_subsriberList, MidiFixture* p_mdiFx, bool indexingMidiFixture = false);

    /*Delete MidiFixture in a subscriber list*/
    void DeleteMidiFixtureInSubscriber(std::vector<MidiFixture*>* p_subsriberList, MidiFixture* p_mdiFx, bool eraseIndexingMidiFixture = false);
    
    /*update all midiFixture list*/
    int UpdateAllFixtureList();

    /*Check have several same value for id*/
    int CheckDuplicatesInMidiSubscribersList(std::vector<MidiFixture*>* p_subsriberList);

    /*Sort in croissant order subsriber list*/
    int SortMidiFixtureSubsrciberList(std::vector<MidiFixture*>* p_subsriberList);

    /*Find midi Fixture in the subcribers list and return his place*/
    int FindMidiFixtureInSubcriber(std::vector<MidiFixture*>* p_subsriberList, MidiFixture* p_mdiFx);

    /*Update index for midifixture subscriber*/
    void UpdateIndexOfMidiFixture();
	/*List of all MidiFixture  that have to listen event from midi Com*/
	std::vector<MidiFixture*> MidiFixtureSubscriberList;

    /*This Index Contains all adress in the array to optimize the search in the large list*/
    uint8_t MidiFixtureIndex[16][127]; 

	/*List of all button with green led that have to listen event from midi Com*/
    std::vector<MidiFixture*>  GreenLedSubscriberList;

    /*List of all button with Red Led that have to listen event from midi Com*/
    std::vector<MidiFixture*>  RedLedSubscriberList;

    /*List of all Fader with led string that have to listen event from midi Com*/
    std::vector<MidiFixture*>  FaderLedSubscriberList;


    ComTx * _ComUart;
    ComTx * _ComMidi;
    ComTx * _ComI2C;

};



#endif /* INC_OBSERVER_HPP_ */
