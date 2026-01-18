#pragma once 
#include "item.h"
#include "enemy.h"

class Enemy;
class Player;

/**************************
Room Decleration
***************************/
template <typename T>
class Room
{
    private:
        T _data;
        Room<T>* _prev;
        Room<T>* _next;

        //room description
        std::string _description;
        Enemy* _enemy;
        Item* _item;

    public:
        
        //constructors
        Room();
        //destructor
        ~Room();

        //setters
        void setData(T);
        void setPrev(Room<T>*);
        void setNext(Room<T>*);

        void setDescription(std::string description);
        void setEnemy(Enemy* enemy);
        void setItem(Item* item);

        //getters
        T getData();
        Room<T>* getPrev();
        Room<T>* getNext();

        std::string getDescription();
        Enemy* getEnemy();
        Item* getItem();

};

/**********************
Room Implementation
**********************/

//constructor
template <typename T>
Room<T>::Room()
{
    _prev = nullptr;
    _next = nullptr;
    _enemy = nullptr;
    _item = nullptr;
}
//destructor
template<typename T>
Room<T>::~Room()
{
    if(_enemy != nullptr)
    {
        delete _enemy;
        _enemy = nullptr;
    }

    if (_item != nullptr)
    {
        delete _item;
        _item = nullptr;
    }
}
//setters
template<typename T>
void Room<T>::setData(T data)
{
    _data = data;
}
template<typename T>
void Room<T>::setPrev(Room<T>* prev)
{
    _prev = prev;
}
template<typename T>
void Room<T>::setNext(Room<T>* next)
{
    _next = next;
}
template<typename T>
void Room<T>::setDescription(std::string description)
{
    _description = description;
}
template<typename T>
void Room<T>::setEnemy(Enemy* enemy)
{
    _enemy = enemy;
}
template<typename T>
void Room<T>::setItem(Item* item)
{
    _item = item;
}

//getters
template<typename T>
T Room<T>::getData()
{
    return _data;
}
template<typename T>
Room<T>* Room<T>::getPrev()
{
    return _prev;
}
template<typename T>
Room<T>* Room<T>::getNext()
{
    return _next;
}
template<typename T>
std::string Room<T>::getDescription()
{
    return _description;
}
template<typename T>
Enemy* Room<T>::getEnemy()
{
    return _enemy;
}
template<typename T>
Item* Room<T>::getItem()
{
    return _item;
}


