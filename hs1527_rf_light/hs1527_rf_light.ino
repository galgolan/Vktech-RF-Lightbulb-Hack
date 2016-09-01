#include "hs1527.h"

#define TXPIN 10 // Pin to transmit encoded data
HS1527 encoder(TXPIN);

#define LED_PIN 13

#define BTN_A 3
#define BTN_B 2
#define BTN_C 1
#define BTN_D 0

#define HS_1527_PULSETIME 284 // Time in microseconds for one pulse

char *address = "\xED\x9D\xA8";
int repeat = 5;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(TXPIN, OUTPUT);
}

void loop() {
  for (int i = 0; i < repeat; i++) {
    digitalWrite(LED_PIN, HIGH);
    // Send multiple times to ensure the bulbs receive the message. 
    // They only toggle once.
      encoder.sendMsg(address, BTN_A);
    digitalWrite(LED_PIN, LOW);
    delay(250);
  }
  
  delay(1000);
}

