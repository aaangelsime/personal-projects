#pragma once 
#include <iostream>

/**************************
Enemy Decleration
***************************/
class Enemy
{
    private:
        std::string _name;
        int _health;
        int _damage;

    public:

        //constructors
        Enemy();
        Enemy(std::string name, int health, int damage);

        //setters
        void setName(std::string name);
        void setHealth(int health);
        void setDamage(int damage);

        //getters
        std::string getName();
        int getHealth();
        int getDamage();

        //take damage function
        void takeDamage(int amount);
        int attack();
};

/**********************
Enemy Implementation
**********************/
Enemy::Enemy() : _name(""), _health(), _damage()
{}
Enemy::Enemy(std::string name, int health, int damage)
{
    _name = name;
    _health = health;
    _damage = damage;
}

//setters
void Enemy::setName(std::string name)
{
    _name = name;
}
void Enemy::setHealth(int health)
{
    _health = health;
}
void Enemy::setDamage(int damage)
{
    _damage = damage;
}

//getters
std::string Enemy::getName()
{
    return _name;
}
int Enemy::getHealth()
{
    return _health;
}
int Enemy::getDamage()
{
    return _damage;
}

//take damage function
void Enemy::takeDamage(int amount)
{
    _health -=amount;
    if (_health < 0)
    {
        _health = 0;
    }
}
int Enemy::attack()
{
    return _damage;
}