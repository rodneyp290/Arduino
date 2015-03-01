int baseSnsVal;
int baseLow = 1023;
int baseHigh = 0;
int preciseSnsVal;
int preciseLow = 1023;
int preciseHigh = 0;

int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  while (millis() < 5000) {
    baseSnsVal = analogRead(A0);
    if (baseSnsVal > baseHigh) {
      baseHigh = baseSnsVal;
    }
    if (baseSnsVal < baseLow) {
      baseLow = baseSnsVal;
    }
    preciseSnsVal = analogRead(A0);
    if (preciseSnsVal > preciseHigh) {
      preciseHigh = preciseSnsVal;
    }
    if (preciseSnsVal < preciseLow) {
      preciseLow = preciseSnsVal;
    }
  }
  digitalWrite(ledPin, LOW);
}

void loop() {
  
  baseSnsVal = analogRead(A0);
  preciseSnsVal = analogRead(A1);
  
  int base = map(baseSnsVal, baseLow, baseHigh, 0, 10);
  int feqLow = base * 400 + 50;
  int feqHigh = (base + 1) * 400 + 50;
  int pitch = map(preciseSnsVal, preciseLow, preciseHigh,
                 feqLow, feqHigh);
  
  tone(8, pitch, 20);
  
  delay(10);
  
}
