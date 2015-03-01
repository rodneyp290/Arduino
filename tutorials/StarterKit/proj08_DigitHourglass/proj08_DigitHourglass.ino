int const tiltPin = 8;

unsigned long prevTime = 0;

int tiltState = 0;
int prevTiltState = 0;

int led = 2;

long interval = 10000;

void setup() {
  for(int ledPin = 2; ledPin < 8; ledPin++) {
    pinMode(ledPin, OUTPUT);
  }

  pinMode(tiltPin, INPUT);
  
  Serial.begin(9600);
}

void loop () {
  unsigned long currentTime = millis();

  if (currentTime - prevTime > interval) {
    prevTime = currentTime;
    digitalWrite(led, HIGH);
    led++;
    if (led == 7) {
      flash()
    }
  }
  tiltState = digitalRead(tiltPin);
  Serial.println(tiltState);

  if (tiltState != prevTiltState) {
    for (int ledPin = 2; ledPin < 8; ledPin++) {
      digitalWrite(ledPin, LOW);
    }

    led = 2;
    prevTime = currentTime;
  }
  prevTiltState = tiltState;
}


