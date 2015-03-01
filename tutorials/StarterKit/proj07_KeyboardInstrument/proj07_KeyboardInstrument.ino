
int note[] = {262, 294, 330, 349};

void setup (){ 
  Serial.begin(9600);
}

void loop() {

 int keyVal = analogRead(A0);
 Serial.println(keyVal);
 
 if (keyVal == 1023) {
   tone(8, note[0]);
 } else if (keyVal >= 990 && keyVal <= 1010) {
   tone(8, note[1]);
 } else if (keyVal >= 505 && keyVal <= 515) {
   tone(8, note[2]);
 } else if (keyVal >= 5 && keyVal <= 10) {
   tone(8, note[3]);
 } else {
   noTone(8);
 }
}
