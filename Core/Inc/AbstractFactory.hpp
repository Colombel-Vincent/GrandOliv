/*
 * MidiFactory.hpp
 *
 *  Created on: 16 janv. 2022
 *      Author: colom
 */

#ifndef ABSTRACTFACTORY_HPP_
#define ABSTRACTFACTORY_HPP_


#include <map>


/*Abstract Creator with Base Class T*/
template <class T>
class Creator
{
public:
    virtual ~Creator(){}
    virtual T* Create() = 0;//pure virtual
};


template <class DerivedType, class BaseType> // Creator to create the derived class from a base class
class DerivedCreator : public Creator<BaseType>
{
public:
    BaseType* Create()
    {
        return new DerivedType;
    }
};

template <class T, class Key>
class Factory
{
public:
    void Register(Key Id, Creator<T>* Cn)
    {
        ConstructorMap[Id] = Cn;
    }

    T* Create(Key Id)
    {
        return ConstructorMap[Id]->Create();
    }

    ~Factory()
    {
    	typename std::map<Key, Creator<T>*>::iterator it = ConstructorMap.begin();
        
        while (it != ConstructorMap.end())
        {
            delete (*it).second;
            ++it;
        }
    }
private:
    std::map<Key, Creator<T>*> ConstructorMap;
};


#endif /* ABSTRACTFACTORY_HPP_ */
