const int rOut = 10;
const int gOut = 9;
const int bOut = 11;

const int potPin = A0;
int hue_degree = 0;
void setup() {
  Serial.begin(9600);

  pinMode(rOut, OUTPUT);
  pinMode(gOut, OUTPUT);
  pinMode(bOut, OUTPUT);

}

float modulo(float dividend, float divisor) {
  float quotient = floor(dividend/divisor);
  return (dividend - (divisor * quotient));
}

void loop() { 
  hue_degree++;
  hue_degree = hue_degree % 360;
  delay(100);
  float hue = hue_degree / 60.0;
  float chroma = 1; //normally V * S
  float midColour = chroma * ( 1 - abs((modulo(hue, 2) -1 )));  // shown as X on wikipedia
  
  // RGB in range of [0, 1)
  float red_ = 0;
  float green_ = 0;
  float blue_ = 0;
  
  // RGB byte codes
  byte red = 0;
  byte green = 0;
  byte blue = 0;
  
  if (0 <= hue && hue < 1) {
    red_ = chroma;
    green_ = midColour;
    blue_ = 0;
  } else if (1 <= hue && hue < 2) {
    red_ = midColour;
    green_ = chroma;
    blue_ = 0;
  } else if (2 <= hue && hue < 3) {
    red_ = 0;
    green_ = chroma;
    blue_ = midColour;
  } else if (3 <= hue && hue < 4) {
    red_ = 0;
    green_ = midColour;
    blue_ = chroma;
  } else if (4 <= hue && hue < 5) {
    red_ = midColour;
    green_ = 0;
    blue_ = chroma;
  } else if (5 <= hue && hue < 6) {
    red_ = chroma;
    green_ = 0;
    blue_ = midColour;
  } else {
    red_ = 0;
    green_ = 0;
    blue_ = 0;
  }
  
  red = floor(red_ * 255);
  green = floor(green_ * 255);
  blue = floor(blue_ * 255);
  
  
  analogWrite(rOut, red);
  analogWrite(gOut, green);
  analogWrite(bOut, blue);
  
  Serial.print("HUE -\tHue: ");
  Serial.print(hue_degree);
  Serial.print("\t(");
  Serial.print(hue);
  Serial.println(")");
  
  Serial.print("RGB -\tRed: ");
  Serial.print(red);
  Serial.print("\tGreen: ");
  Serial.print(green);
  Serial.print("\tBlue: ");
  Serial.println(blue);
  
  if (hue_degree % 60 == 0) { delay(1000); }
}

