#include <Arduino.h>

char cmd[32];
uint8_t idx = 0;

void setup()
{
  Serial.begin(115200);
  Serial.println("ESP32 Ready");
}

void loop()
{
  while (Serial.available())
  {
    char c = Serial.read();

    if (c == '\n' || c == '\r')
    {
      cmd[idx] = '\0';

      if (strcmp(cmd, "PING") == 0)
        Serial.println("PONG");
      else
      {
        Serial.print("Unknown: ");
        Serial.println(cmd);
      }

      idx = 0;
    }
    else if (idx < sizeof(cmd) - 1)
    {
      cmd[idx++] = c;
    }
    else
    {
      idx = 0; // overflow protection
    }
  }
}