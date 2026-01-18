#include <Arduino.h>
#include <Wire.h>
#include <Servo.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <HCSR04.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display (SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// instance of ultra sonic sensor
const byte trigger_pin = 8;
const byte echo_pin = 9;
UltraSonicDistanceSensor distanceSensor(trigger_pin, echo_pin);

// Servo object
Servo myservo;
int pos = 0; // var to store the servo position

// baud rate
int br = 9600;

// LED pins
int red_led = 5;
int yellow_led = 4;
int green_led = 3;

// Joystick pins
int joy_stick_x = A0;
int joy_stick_y = A1;
int button = 2;

int servo_pin = 12;

void setup() {

Wire.begin();

if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (1); // OLED not detected
}

display.clearDisplay();
display.setTextSize(1);
display.setTextColor(SSD1306_WHITE);
display.setCursor(0, 0);

display.display();

// Joystick setup
pinMode(joy_stick_x, INPUT);
pinMode(joy_stick_y, INPUT);
pinMode(button, INPUT_PULLUP);

// led setup
pinMode(red_led, OUTPUT);
pinMode(yellow_led, OUTPUT);
pinMode(green_led, OUTPUT);

// Servo setup
myservo.attach(servo_pin);
myservo.write(0);

Serial.begin(br);
}

void loop() {

  // joy stick values
  int joy_value_x = analogRead(joy_stick_x);
  int joy_value_y = analogRead(joy_stick_y);

  float distance = distanceSensor.measureDistanceCm();
  

  // Joystick → Servo mapping 
  if (joy_value_x < 200) {
    pos = 20;
  } 
  else if (joy_value_x < 400) {
    pos = 60;
  } 
  else if (joy_value_x < 600) {
    pos = 100;
  } 
  else if (joy_value_x < 800) {
    pos = 135;
  } 
  else {
    pos = 165;
  }

  myservo.write(pos);

  // Serial Debug 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("X: ");
  Serial.print(joy_value_x);
  Serial.print(" | Y: ");
  Serial.print(joy_value_y);
  Serial.print(" | Servo: ");
  Serial.println(pos);

  // OLED 
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(10, 0);
  display.print("Distance: ");
  display.print(distance);

  display.setCursor(10, 20);
  display.print("X: ");
  display.print(joy_value_x);

  display.setCursor(10, 35);
  display.print("Y: ");
  display.print(joy_value_y);

  display.setCursor(10, 50);
  display.print("Angle: ");
  display.print(pos);

  display.display();

  delay(50);
}
