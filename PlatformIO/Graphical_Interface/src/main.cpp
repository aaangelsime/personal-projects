#include <Arduino.h>
#include <Wire.h>
#include "LiquidCrystal_I2C.h"

// pinout for buttons
#define button_up 3
#define button_down 5
#define button_select 6


// I2C address 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Menu structure
const char* menu_items[] =
{
  "Start",
  "Settings",
  "About",
  "Reset"
};

const int menu_length = sizeof(menu_items) / sizeof(menu_items[0]);
int current_item = 0;
int menu_offset = 0;

/***************************
Function Declarations
***************************/

// Draw menu screen function
void draw_menu();

// Navigation function
void handle_input();

// Select Item function
void select_item();

/**********************
Program Setup
**********************/

void setup()
{
  
  Wire.begin(); // uno r4 I2C sda/scl
  lcd.init(); // initialize lcd object
  lcd.backlight(); //turn backlight on

  pinMode(button_up, INPUT_PULLUP);
  pinMode(button_down, INPUT_PULLUP);
  pinMode(button_select, INPUT_PULLUP);

  lcd.clear();
  lcd.setCursor(0, 0);
  delay(1500);

}

/**********************
Program Loop
**********************/

void loop()
{
  handle_input();
  draw_menu();

  if(digitalRead(button_select) == LOW)
  {
    select_item();
    while(digitalRead(button_select) == LOW);
    delay(150);
  }
}

/***************************
Function Definition
***************************/

// Draw menu screen function
void draw_menu()
{
  lcd.clear();

  for (int i = 0; i < 2; i++)
  {
    int item_index = menu_offset + i;

    if (item_index >= menu_length) break;

    lcd.setCursor(0, i);

    if (item_index == current_item) lcd.print(">");
    else lcd.print(" ");

    lcd.print(menu_items[item_index]);
  }
}

// Navigation function
void handle_input()
{
  if(digitalRead(button_up) == LOW)
  {
    current_item--;

    if(current_item < 0) current_item = menu_length - 1;
  }

  if(digitalRead(button_down) == LOW)
  {
    current_item++;
    if (current_item >= menu_length) current_item = 0;
  }

  // Scroll Window conditional
  if(current_item < menu_offset) menu_offset = current_item;

  else if (current_item >= menu_offset + 2) menu_offset = current_item - 1;

  delay(200);
}

// Select Item Function
void select_item()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Selected: ");
  lcd.setCursor(0, 1);
  lcd.print(menu_items[current_item]);
  delay(1000);
}