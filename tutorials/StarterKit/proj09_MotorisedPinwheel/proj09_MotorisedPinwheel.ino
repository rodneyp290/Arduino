const int button = 2;
const int motor = 9;
int buttonPressed = 0;

void setup() {
  pinMode(button, INPUT);
  pinMode(motor, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  buttonPressed = digitalRead(button);
  
  if (buttonPressed == HIGH) {
    digitalWrite(motor, HIGH);
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(motor, LOW);
    digitalWrite(13, LOW);
  }
}
