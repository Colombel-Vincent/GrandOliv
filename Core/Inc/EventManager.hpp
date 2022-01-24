/*
 * Observer.hpp
 *
 *  Created on: Jan 20, 2022
 *      Author: colom
 */

#ifndef INC_OBSERVER_HPP_
#define INC_OBSERVER_HPP_

#include <list>

#include "observers_types.hpp"
#include "MidiFixture/Button.hpp"

/*This class manage all the event that comme from midi reception and update on the current event all the involved classes*/
class EventManager : eventSubscriber
{
protected:
	
    EventManager(uint8_t _value) : test(_value) {};
    static EventManager* _eventManager;
    uint8_t test;
public:

    EventManager(EventManager &other) = delete;

    void operator=(const EventManager &) = delete;

    static EventManager *GetInstance();

    void update(IObserver * test) {
        int nu = 8;
        test->Update(&nu);
    }
    template<class T>
    void notify() {};
    template<>
    void notify <MidiFixture>() {};


    //int registerEncodeur (Encodeur * en);
    //int registerFader (Fader * fd);
    //int registerButton(MidiFixture * md);
    //int registerRedLedButton(ButtonRedLed * bt);
    //int registerGreenLedButton (ButtonGreenLed * bt);
    //int registerfaderLed (Fader * fd);
    //int registerCom (ComManager * com);
    
private :

    /*List of all encodeur that have to listen event from midi Com*/
	//std::list<Encodeur> EncodeurSubscriberList;
	/*List of all fader that have to listen event from midi Com*/
	//std::list<Fader> FaderSubscriberList;
	/*List of all MidiFixture  that have to listen event from midi Com*/
	std::list<MidiFixture> ButtonSubscriberList;
	/*List of all button with green led that have to listen event from midi Com*/
    std::list<ButtonGreenLed>  GreenLedSubscriberList;
    /*List of all button with Red Led that have to listen event from midi Com*/
    std::list<ButtonRedLed>  RedLedSubscriberList;
    /*List of all Fader with led string that have to listen event from midi Com*/
   // std::list<faderLed>  FaderLedSubscriberList;
    /*List of all Com "Arduino and I2C" that have to listen event from midi Com*/
  //  std::list <ComManager> ComBufferList;

};



#endif /* INC_OBSERVER_HPP_ */
