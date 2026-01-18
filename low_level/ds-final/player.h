#pragma once
#include <iostream>
#include <array>
#include "item.h"

/**************************
Player Decleration
***************************/
class Player
{
    protected:
        std::string _name;
        int _health = 100;
        int _attackPower = 20;
        std::array<Item*, 4> _inventory;
    
    public:

        //constructor
        Player();
        Player(std::string name, int health, int attackPower, std::array<Item*, 4>);

        //setters
        void setName(std::string name);
        void setHealth(int health);
        void setAttackPower(int attackPower);
        void setInventory(std::array<Item*, 4> inventory);

        //getters
        std::string getName();
        int getHealth();
        int getAttackPower();
        std::array<Item*, 4> getInventory();

        //functions for player
        int attack();
        void takeDamage(int amount);
        void addToInventory(Item* item);
        void useItem(std::string itemName);
};

/**********************
Player Implementation
**********************/

//constructor
Player::Player() : _name(""), _health(100)
{
    for (size_t i = 0; i < _inventory.size(); ++i)
    {
        _inventory[i] = nullptr;
    }
}
Player::Player(std::string name, int health, int attackPower, std::array<Item*, 4> inventory)
{
    _name = name;
    _health = health;
    _attackPower = attackPower;
    _inventory = inventory;

    for (size_t i = 0; i < _inventory.size(); ++i)
    {
        _inventory[i] = nullptr;
    }
}

//setters
void Player::setName(std::string name)
{
    _name = name;
}
void Player::setHealth(int health)
{
    _health = health;
}
void Player::setAttackPower(int attackPower)
{
    _attackPower = attackPower;
}
void Player::setInventory(std::array<Item*, 4>  inventory)
{
    _inventory = inventory;
}

//getters
std::string Player::getName()
{
    return _name;
}
int Player::getHealth()
{
    return _health;
}
int Player::getAttackPower()
{
    return _attackPower;
}
std::array<Item*, 4> Player::getInventory()
{
    return _inventory;
}

//functions 
int Player::attack()
{
  return _attackPower;  
}
void Player::takeDamage(int damage)
{
    if (damage > 0)
    {
        _health -= damage;
        if (_health < 0) _health = 0;
    }
}
void Player::addToInventory(Item* item)
{
    //finds the first null and add the item to that node
    for (size_t i = 0; i < _inventory.size(); ++i)
    {
        if (_inventory[i] == nullptr)
        {
            _inventory[i] = item;
            std::cout << "\n** " << item->getName() << " collected **\n";
            return;
        }
    }
    std::cout << "\n** Inventory is full! **\n";
}
void Player::useItem(std::string itemName)
{
    for (size_t i = 0; i < _inventory.size(); ++i)
    {
        if (_inventory[i] != nullptr && _inventory[i]->getName() == itemName)
        {
            //applies effect based on item type
            if (_inventory[i]->getEffect() == "Heal")
            {
                _health += _inventory[i]->getValue();


                //caps health at 100
                if(_health > 100) _health = 100;
                std::cout << "\n** Used " << _inventory[i]->getName() << "! Health restored to "
                          << _health << " . **\n";
            }
            else if (_inventory[i]->getEffect() == "Attack Buff")
            {
                _attackPower += _inventory[i]->getValue();
                std::cout << "\n** Used " << _inventory[i]->getName() << ". **\n";
            }

            //removes item from inentory
            _inventory[i] = nullptr;
            return;
        }
    }
    std::cout << "\n** You don't have that item. **\n";
}
