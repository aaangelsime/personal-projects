#pragma once
#include <string>

/**************************
Item Decleration
***************************/
class Item
{
    private:
        // health buff and strength buff
        std::string _name; 
        std::string _effect;
        int _value;

    public:
        //constructor
        Item();
        Item(std::string name, std::string effect, int value);

        //setters
        void setName(std::string name);
        void setEffect(std::string effect);
        void setValue(int value);

        //getters
        std::string getName();
        std::string getEffect();
        int getValue();

        //functions
        void use();

};

/**********************
Item Implementation
**********************/

//constructor
Item::Item() : _name(""), _effect(""), _value(0)
{}
Item::Item(std::string name, std::string effect, int value)
{
    _name = name;
    _effect = effect;
    _value = value;
}

//setters
void Item::setName(std::string name)
{
    _name = name;
}
void Item::setEffect(std::string effect)
{
    _effect = effect;
}
void Item::setValue(int value)
{
    _value = value;
}

//getters
std::string Item::getName()
{
    return _name;
}
std::string Item::getEffect()
{
    return _effect;
}
int Item::getValue()
{
    return _value;
}

//use function
void Item::use()
{
    
}