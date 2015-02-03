/* Arduino Starter Kit Tutorial
 * Color Mixing Lamp   (photoresistor)
 */
 //TODO: Add Comments & use more descriptive names
const int rOut = 10;
const int gOut = 9;
const int bOut = 11;

const int rIn = A0;
const int gIn = A1;
const int bIn = A2;

int rRaw = 0;
int gRaw = 0;
int bRaw = 0;

int red = 0;
int green = 0;
int blue = 0;

void setup() {
 Serial.begin(9600);
 
 pinMode(rOut, OUTPUT);
 pinMode(gOut, OUTPUT);
 pinMode(bOut, OUTPUT);
 
}

void loop() {
  rRaw = analogRead(rIn);
  delay(5);
  gRaw = analogRead(gIn);
  delay(5);
  bRaw = analogRead(bIn);
  delay(5);
  
  red = rRaw/4 - 50;
  green = gRaw/4 - 50;
  blue = bRaw/4 - 50;
  
  if (red < 0) { red = 0; }
  if (green < 0) { green = 0; }
  if (blue < 0) { blue = 0; }
  
  analogWrite(rOut, red);
  analogWrite(gOut, green);
  analogWrite(bOut, blue);
 
  Serial.print("Raw -\tRed: ");
  Serial.print(rRaw);
  Serial.print("\tGreen: ");
  Serial.print(gRaw);
  Serial.print("\tBlue: ");
  Serial.println(bRaw);
  
  Serial.print("Mapped -\tRed: ");
  Serial.print(red);
  Serial.print("\tGreen: ");
  Serial.print(green);
  Serial.print("\tBlue: ");
  Serial.println(blue);
}
