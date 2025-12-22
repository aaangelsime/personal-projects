#pragma once
#include "room.h"
#include <iostream>

using namespace std;

/********************************
Decleration for LinkedList Class
********************************/

template <typename T>
class Dungeon
{
    private:
        Room<T> *_head;
        Room<T> *_tail;
        size_t DungeonSize;
        std::string _description;

    public:
        Dungeon();
        ~Dungeon();

        bool empty();
        size_t size();

        void push_front(T);
        T pop_front();
        T front();
        void push_back(T);
        T pop_back();
        T back();

        bool operator==(const Dungeon<T>&);
        // Have to declare a template for friend functions using a different template variable
        template <typename T2>
        friend ostream &operator<<(ostream &, const Dungeon<T2> &);

        //getters
        Room<T>* getHead();
        Room<T>* getTail();
        Room<T>* getDescription();
        
};

/********************************
implentation for LinkedList Class
********************************/

// set to nullptr and initialize DungeonSize
template <typename T>
Dungeon<T>::Dungeon()
{
    _head = nullptr;
    _tail = nullptr;
    DungeonSize = 0;
}

// iteratively delete the Dungeon starting at _head
template <typename T>
Dungeon<T>::~Dungeon()
{
    Room<T>* current = _head;
        while (current != nullptr)
        {
            Room<T>* next = current->getNext(); // Saves the next Pointer
            delete current; // Deletes the current Room
            current = next; // Moves through the next code
        }
}

// return true if the Dungeon is empty, false otherwise.
// Do not just check DungeonSize, should actually check _head and _tail
template <typename T>
bool Dungeon<T>::empty()
{
    // Checks if the Dungeon is empty by checking both _head and _tail
    return (_head == nullptr && _tail == nullptr);
}

// return number of elements in Dungeon
template <typename T>
size_t Dungeon<T>::size()
{
    // Returns num of elements in the Dungeon
    return DungeonSize;
}

// add an element to the beginning of the Dungeon, updating _head
template <typename T>
void Dungeon<T>::push_front(T data)
{
    // Adds a new   Room to the beginnning of the Dungeons and updates the _head
    Room<T>* newRoom = new Room<T>();
    newRoom->setData(data);

    if (empty())
    {
        _head = newRoom;
        _tail = newRoom;
    }
    else
    {
        newRoom->setNext(_head);
        _head->setPrev(newRoom);
        _head = newRoom;
    }
    DungeonSize++;
}

// return the first element in the Dungeon.
// if the Dungeon is empty, print that out and return 0
template <typename T>
T Dungeon<T>::front()
{
    // Returns the info of the first element
    if (empty())
    {
        return T(); // Returns the default constructor value
    }
    return _head->getData();
}

// remove the first element from the Dungeon and return its data
// if the Dungeon is empty, print that out and return 0;
template <typename T>
T Dungeon<T>::pop_front()
{
    // Removes the first element, updates _head, and returns that info
    if (empty())
    {
        return T(); // Returns default constructer
    }
   
    // Changed var name
    T someData = _head->getData();
    // Saves    Room to delete later
    Room<T>* temp = _head;

    // Dungeon that had only one element
    if (_head == _tail)
    {
        _head = nullptr;
        _tail = nullptr;
    }
    else
    {
     
        _head = _head->getNext();
        _head->setPrev(nullptr);
    }

    delete temp;
    DungeonSize--;
    return someData;
}

// add an element to the end of hte Dungeon, updating _tail
template <typename T>
void Dungeon<T>::push_back(T data)
{
    // Adds a new   Room to the end of the Dungeon and updates the _tail 
    Room<T>* newRoom = new Room<T>();
    newRoom -> setData(data);

    if (empty())
    {
        _head = newRoom;
        _tail = newRoom;
    }
    else
    {
        newRoom->setPrev(_tail);
        _tail->setNext(newRoom);
        _tail = newRoom;
    }
    DungeonSize++;
}

// return the last element in the Dungeon.
// if the Dungeon is empty, print that out and return 0
template <typename T>
T Dungeon<T>::back()
{
    // Returns the info of the last element
    if (empty())
    {
        return T(); // returns default constructor value 
    }
    return _tail->getData();
}

// remove the last element from the Dungeon and return its data
// if the Dungeon is empty, print that out and return 0;
template <typename T>
T Dungeon<T>::pop_back()
{
    // Removes the first element, updates _head, and returns that info
    if (empty())
    {
        // Returns default constructer
        return T();
    }
    
    // Changed var name
    T someData = _tail->getData(); 
    Room<T>* temp = _tail;

    // Dungeon that had only one element
    if (_head == _tail)
    {
        _head = nullptr;
        _tail = nullptr;
    }
    else
    {
        // Moving tail back to prev Room
        _tail = _tail->getPrev(); 
        // Setting the new tail "next" to nullptr
        _tail->setNext(nullptr);
    }

    delete temp;
    DungeonSize--;
    return someData;
}

// overloading <<, should return a space separated stream of all of the elements
template <typename T>
ostream &operator<<(ostream &os, const Dungeon<T> &Dungeon)
{
    // Displays all elements of the Dungeon and has spaces inbetween
    Room<T>* current = Dungeon._head;
    
    while (current != nullptr)
    {
        os << current->getData() << " ";
        current = current->getNext();
    }

    return os;
}

// should iterate through each Dungeon to check that they are exactly the same
template <typename T>
bool Dungeon<T>::operator==(const Dungeon<T>& rhs)
{
    // Checks if two Dungeons are the same size and elements
    if (DungeonSize != rhs.DungeonSize)
    {
        return false;
    }

    Room<T>* currentLHS = _head;
    Room<T>* currentRHS = rhs._head;

    while (currentLHS != nullptr)
    {
        if (currentLHS->getData() != currentRHS->getData())
        {
            return false;
        }
        currentLHS = currentLHS->getNext();
        currentRHS = currentRHS->getNext();
    }
    return true;
}

//getters
template<typename T>
Room<T>* Dungeon<T>::getHead()
{
    return _head;
}
template<typename T>
Room<T>* Dungeon<T>::getTail()
{
    return _tail;
}
template<typename T>
Room<T>* Dungeon<T>::getDescription()
{
    return _description;
}