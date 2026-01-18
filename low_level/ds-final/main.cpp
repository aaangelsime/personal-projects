#include "dungeon.h"
#include "player.h"
#include "enemy.h"
#include "room.h"
#include "item.h"
#include <iostream>
#include <array>
#include <string>
#include <limits>
#include <fstream>

using namespace std;


//ENEMY CLASS   
//instantiation for the three enemies
Enemy _firegiant ("Fire Giant", 90, 25);
Enemy _malekith ("Maliketh", 120, 35);
Enemy _malenia ("Malenia", 140, 25);

//ITEM CLASS
//instantiations for the two items
Item _healthBuff ("Healing buff", "Heal", 60);
Item _strengthBuff ("Strength buff", "Attack Buff", 30);

//game logic functions
bool game_intro();
void game_loop(Player& player, Dungeon<int>& game_dungeon);
void game_combat(Player& player, Enemy* enemy);

//game ascii functions
void print_text(const std::string& filename);

int main(int argc, char *argv[])
{
    //PLAYER CLASS
    //instantiation for player class
    Player player; 
    string player_name;

    //DUNGEON class
    Dungeon<int> game_dungeon;

    //Room1
    game_dungeon.push_back(1);
    game_dungeon.getTail()->setDescription("description of room");
    game_dungeon.getTail()->setEnemy(&_firegiant);
    game_dungeon.getTail()->setItem(&_strengthBuff);
    //Room2
    game_dungeon.push_back(2);
    game_dungeon.getTail()->setDescription("description of room");
    game_dungeon.getTail()->setEnemy(&_malekith);
    game_dungeon.getTail()->setItem(&_healthBuff);
    //Room3
    game_dungeon.push_back(3);
    game_dungeon.getTail()->setDescription("description of room");
    game_dungeon.getTail()->setEnemy(&_malenia);
    game_dungeon.getTail()->setItem(&_healthBuff);

    
    //user intro stats
    cout << "Enter players name: ";
    cin >> player_name;
    player.setName(player_name);
    cout << "Players name: " << player.getName() << " | Health: " 
         << player.getHealth() << endl;

    //call intro function
    game_intro();
    //call loop function, doesn't need game_combat function because it's in the game_loop
    game_loop(player, game_dungeon);

    return 0;
}

//Implementation for the games intro
bool game_intro()
{
    int user_choice;

    while (true)
    {
        cout << "\n===============================\n";
        cout << "           Dungeon             \n";
        cout << "===============================\n";

        cout << "1. Enter the dungeon\n";
        cout << "2. Exit\n";
        cout << "Choose an option: ";
        cin >> user_choice;

        if (user_choice == 2)
        {
            cout << "You weren't ready anyways...\n";
            return false;   
        }
        else if (user_choice == 1)
        {
            cout << "good luck bruh...\n";
            return true;
        }
        else
        {
            cout << "Invalid option...\n";
        }
    }
}

//Implementation for the game's loop
void game_loop(Player& player, Dungeon<int>& game_dungeon)
{
    bool play_game = game_intro();

    if(!play_game)
    {
        return;
    }

    //starts at the head (first room) of dungeon
    Room<int>* currentRoom = game_dungeon.getHead();
    int loop_choice;
    std::string item_name;

    //MAIN LOOP
    while(currentRoom != nullptr && player.getHealth() > 0)
    {
        cout << "\n----Current Location: Room " << currentRoom->getData() << "----\n";
        cout << player.getName() << "'s Health: " << player.getHealth() << " | Attack Power: " << player.getAttackPower() << endl;
        // cout << currentRoom->getDescription() << endl;

        //checks for item
        Item* roomItem = currentRoom->getItem();
        if(roomItem != nullptr)
        {
            cout << "\nYou found a " << roomItem->getName() << ".\n";
            player.addToInventory(roomItem);
            currentRoom->setItem(nullptr); //the item is then picked
        }

        //checks for enemy
        Enemy* roomEnemy = currentRoom->getEnemy();
        if(roomEnemy != nullptr)
        {
            cout << "Encountered  " << roomEnemy->getName() << ".\n";

            // calls combat function
            game_combat(player, roomEnemy);

            /////DEFEATED
            if (player.getHealth() <= 0)
            {
                cout << roomEnemy->getName() << " has you beat.. Game Over\n";
                //breaks the main loop
                break;
            }

            //////WON
            if(roomEnemy->getHealth() <= 0)
            {
                cout << "You defeated " << roomEnemy->getName() << ".\n";
                //removes defeated enemy 
                currentRoom->setEnemy(nullptr);
            }
        }

        //menu only if no enemy is present and player is still alive
        if (currentRoom->getEnemy() == nullptr && player.getHealth() > 0)
        {
            cout << "\nWhat would you like to do?\n";
            cout << "1. Use an item\n";


            //check the last room for victory condit.
            if (currentRoom->getNext() == nullptr)
            {
                cout << "2. Claim the final prize\n";
            }
            else
            {
                cout << "2. Move to the next room\n";
            }
            cout << "3. Quit\n";
            cout << "Choose an option: ";
            cin >> loop_choice;

            if(loop_choice == 2)
            {
                if(currentRoom->getNext() == nullptr)
                {
                    cout << "Congrats, you clamed the final prize.\n";
                    currentRoom = nullptr;
                }
                else
                {
                    //move to next room
                    currentRoom = currentRoom->getNext();
                }
            }
            else if (loop_choice == 3)
            {
                cout << "Quitting game....\n";
                //ends loop
                currentRoom = nullptr;
            }
            else 
            {
                cout << "Invalid option.. Choose 1, 2, or 3.\n";
            }
        }
    }
    //FIXME implement game loop
    if(player.getHealth() <= 0)
    {
        cout << "\n GAME OVER \n";
    }
    else if (currentRoom == nullptr)
    {
        if (loop_choice != 2)
        {
            cout << "\n GAME ENDED \n";
        }
    }
}

//implementation for the games combat
void game_combat(Player& player, Enemy* enemy)
{
    cout << "-----Combat Start-----\n";
    cout << player.getName() << " (" << player.getHealth() << " HP) vs. "
         << enemy->getName() << " (" << enemy->getHealth() << " HP)\n";

    //copy of enemy
    Enemy currentEnemy = *enemy;
    //item use
    std::string item_Name;
    //player choice
    int combat_choice;
    
    while (player.getHealth() > 0 && currentEnemy.getHealth() > 0)
    {
        cout << "\n----------------------------------------\n";
        cout << "Your turn! Choose an action:\n";
        cout << "1. attack " << currentEnemy.getName() << endl;
        cout << "2. Use item \n";
        cout << "Choose: ";
        cin >> combat_choice;

        //invalid inputs for combat choice
        if(cin.fail())
        {
            cout << "Invalid input\n";
            cin.clear();
            //returns the max finite value represented by the streamsize type
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            combat_choice = 0;
        }

        if (combat_choice == 1)
        {
            int damageDealth = player.attack();
            currentEnemy.takeDamage(damageDealth);
            cout << "You attacked " << currentEnemy.getName() 
                 << " for " << damageDealth << " damage\n";
        }
        else if (combat_choice == 2)
        {

            //returns the max finite value represented by the streamsize type
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter the name of the item to use: ";
        
            if(!getline(cin, item_Name))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n Could not read item name.\n";
            }
            else
            {
            player.useItem(item_Name);
            cout << "\n Player Health: " << player.getHealth() << " | Attack Power: " 
                 << player.getAttackPower() << endl;
            }
        }
        else
        {
            cout << "Invalid choice. Skipping turn.\n";
        }

        if (currentEnemy.getHealth() <= 0)
        {
            enemy->setHealth(0);
            cout << currentEnemy.getName() << " has been defeated!\n";
            //combat ends
            return;
        }

        //chekcs if player spent turn on invalid choice or use item
        if (combat_choice == 1 || combat_choice == 2)
        {
        int enemyDamage = currentEnemy.attack();
        player.takeDamage(enemyDamage);
        cout << currentEnemy.getName() << " attacks you for " << enemyDamage << " damage.\n";
        cout << "Your remaining health: " << player.getHealth() << endl;
        }

        //check if player is defeated
        if(player.getHealth() <= 0)
        {
            cout << "You have been defeated...\n";
            return;
        }
    }
}

void print_text(const std::string& filename)
{
    std::ifstream file("enter.txt");
}