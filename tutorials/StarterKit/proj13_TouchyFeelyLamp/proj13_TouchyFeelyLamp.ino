#include <CapacitiveSensor.h>

CapacitiveSensor capSensor = CapacitiveSensor(4, 2);

int threshold = 1000;
const int ledPin = 12;
bool on = false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = capSensor.capacitiveSensor(30);
  Serial.println(sensorValue);

  if ( sensorValue > threshold ) {
    on = !on;
    if (on) { 
      digitalWrite(ledPin, HIGH);
    } else { 
      digitalWrite(ledPin, LOW);
    }
    delay(100);
  } 
  //if (sensorValue < threshold - 500) { 
  //  digitalWrite(ledPin, LOW);
  //}
  delay(10);
}

