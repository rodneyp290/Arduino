#include <CapacitiveSensor.h>


const int loT = 8;
const int hiT = 100;

int sensorVal;
int sensorLow = hiT;
int sensorHigh = loT;


CapacitiveSensor capSensor = CapacitiveSensor(4, 2);

int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  while (millis() < 5000) {
    sensorVal = analogRead(A0);
    if (sensorVal > sensorHigh && sensorVal < hiT) {
      sensorHigh = sensorVal;
    }
    if (sensorVal < sensorLow && sensorVal > loT) {
      sensorLow = sensorVal;
    }
  }
  digitalWrite(ledPin, LOW);
  
  Serial.begin(9600);
}

void loop() {
  
  sensorVal = capSensor.capacitiveSensor(30);
  Serial.println(sensorVal);

  if (sensorVal > loT && sensorVal < hiT) {
  
    int pitch = map(sensorVal, sensorLow, sensorHigh, 50, 4000);
  
    noTone(8);
    tone(8, pitch, 20);
    digitalWrite(8, HIGH);

  } else {
    noTone(8);
    digitalWrite(8, LOW);
  }
  
  delay(10);
  
}
