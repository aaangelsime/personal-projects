#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display (SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// function for centered text
void draw_centered_text(const char* text, int y)
{
int16_t x1, y1;
uint16_t w, h;

display.getTextBounds(text, 0, y, &x1, &y1, &w, &h);
int x = (SCREEN_WIDTH - w) / 2;

display.setCursor(x, y);
display.print(text);
}

int joyStick_x = A0; // x-axis signal
int joyStick_y = A1; // y-axis signal
int button = 3;

int green_light = 7; // green led
int blue_light = 6; // blue led
int yellow_light = 4;
int red_light = 5;

void setup() {

  Wire.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (1); // OLED not detected
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);

  display.println("SunFounder OLED");
  display.println("Uno R4 WiFi");
  display.println("SSD1306 OK");

  display.display();

  // Pinmode -> Joystick
  pinMode(joyStick_x, INPUT);
  pinMode(joyStick_y, INPUT);
  pinMode(button, INPUT_PULLUP);

  // Pinmode -> LEDS
  pinMode(green_light, OUTPUT);
  pinMode(blue_light, OUTPUT);
  pinMode(yellow_light, OUTPUT);
  pinMode(red_light, OUTPUT);

 Serial.begin(9600); // baud rate
}

/*
The loop reads at the current values of the input pins and outputs them at serial output
*/
void loop() {
  int valuex, valuey;

  valuex = analogRead(joyStick_x);
  valuey = analogRead(joyStick_y);

  Serial.print("x-axis: ");
  Serial.print(valuex);
  Serial.print(" | Y-axis: ");
  Serial.println(valuey);

  // X value
  if (valuex < 500)
  {
    digitalWrite(blue_light, HIGH);
  }
  else if (valuex > 510)
  {
    digitalWrite(red_light, HIGH);
  }
  else 
  {
    digitalWrite(blue_light, LOW);
    digitalWrite(red_light, LOW);
  }

  // Y value
    if (valuey < 510)
  {
    digitalWrite(green_light, HIGH);
  }
  else if (valuey > 518)
  {
    digitalWrite(yellow_light, HIGH);
  }
  else 
  {
    digitalWrite(green_light, LOW);
    digitalWrite(yellow_light, LOW);
  }

  // ----oled-----

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Title for oled
  draw_centered_text("X and Y-axis Coordinates", 0);

  // display values underneath title
  display.setCursor(10, 20);
  display.print("X: ");
  display.print(valuex);

  display.setCursor(10, 35);
  display.print("Y: ");
  display.print(valuey);

  display.display();

  delay(250);

}
