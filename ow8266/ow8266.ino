#include <Arduino.h>
#include <IRsend.h>
#include <IRrecv.h>
#include <IRremoteESP8266.h>
#include <IRutils.h>

const int PIN_BUTTON  = 4;
const int PIN_LED     = 15;
const int PIN_IR_RECV = 5;
const int PIN_IR_SEND = 14;

IRrecv irrecv(PIN_IR_RECV);
IRsend irsend(PIN_IR_SEND);
decode_results irresults;

void blink(){
  digitalWrite(PIN_LED, HIGH);
  delay(200);
  digitalWrite(PIN_LED, LOW);
  delay(200);    
}

void setup() {
  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_LED, OUTPUT);
  blink();

  irrecv.enableIRIn();
  irsend.begin();

  Serial.begin(115200);
  Serial1.begin(115200);
  while (!Serial) {
    delay(50);
  }
  Serial.println("114514");
}

void switchIPTV() {
  blink();
  delay(500);
  irsend.sendNEC(0x44BB3BC4); // IPTV power
  blink();
  delay(1000);
  irsend.sendNEC(0x44BB738C); // IPTV ok
  blink();
  blink();
  delay(2000);
}

void loop() {
  if (digitalRead(PIN_BUTTON) == 0) {
    Serial.println("button pressed");
    switchIPTV();
    return;
  }

  if (irrecv.decode(&irresults)) {
    serialPrintUint64(irresults.value, HEX);
    Serial.println("");

    if ((irresults.decode_type == UNKNOWN) && (irresults.value == 0x2307B446)) { // TV power
      Serial.println("power pressed");
      switchIPTV();
    }

    irrecv.resume();
  }
}
