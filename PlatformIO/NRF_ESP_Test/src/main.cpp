#include <Arduino.h>
#include <SPI.h>
#include <RF24.h>

#define CE_PIN 4
#define CSN_PIN 5

RF24 radio(CE_PIN, CSN_PIN);

void setup() {
  Serial.begin(115200);
  delay(2000);

  Serial.println("\n--- ESP32 NRF24 Bring-Up Test ---");

  if (!radio.begin()) {
    Serial.println("x NRF24 NOT detected");
    while (1) {
      delay(1000);
    }
  }

  Serial.println("NRF24 detected");

  radio.setChannel(76);
  radio.setDataRate(RF24_1MBPS);
  radio.setPALevel(RF24_PA_LOW);
  radio.setAutoAck(true);
  radio.enableDynamicPayloads();

  radio.printDetails();
}

void loop() {
  delay(2000);
}
