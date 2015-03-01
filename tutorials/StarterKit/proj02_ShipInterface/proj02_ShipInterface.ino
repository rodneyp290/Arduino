// Switch state variable ( assumption: 1 = HIGH = ON; 0 = LOW = OFF)
int switchState = 0;

void setup () {
  //set pin 3 in output mode for green LED
  pinMode(3, OUTPUT);
  //set pin 4 in output mode for first red LED
  pinMode(4, OUTPUT);
  //set pin 5 in output mode for second red LED
  pinMode(5, OUTPUT);
  //set pin 2 in input mode to read switch
  pinMode(2, INPUT);
  //for debugging
  //set pin 13 in output mode to output switch state to onboard LED
  pinMode(13, OUTPUT);
}

void loop() {
  
  // read state of switch
  switchState = digitalRead(2);

  // if switch is not pressed
  if (switchState == LOW) {
    // turn on green light (by writing HIGH to pin 3)
    digitalWrite(3, HIGH);
    // turn on first red light (by writing LOW to pin 4)
    digitalWrite(4, LOW);
    // turn on second red light (by writing LOW to pin 5)
    digitalWrite(5, LOW);
    
    // turn on board LED off to signal switch isn't pressed)
    digitalWrite(13, LOW);
  }
  else {
    //turn on onboard LED to signal switch is press
    digitalWrite(13, HIGH)
    
    // turn off green ans first red LED
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    // turn on second red LED
    digitalWrite(5, HIGH);
    
    delay(500);
    
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    
    delay(500);
  }
}
