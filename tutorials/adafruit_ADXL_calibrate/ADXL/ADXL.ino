
// opposite wiring to tutorial
const int xInput = A2;
const int yInput = A1;
const int zInput = A0;

const int buttonPin = 2;
const int xLedPin = 11;
const int yLedPin = 10;
const int zLedPin = 9;

// Raw Ranges:
// initialise to mid-range and allow calibration to find the axis' min & max
int xRawMin = 512;
int xRawMax = 512;

int yRawMin = 512;
int yRawMax = 512;

int zRawMin = 512;
int zRawMax = 512;

// Take multiple samples to reduce noise
// number specificed below
int sampleSize = 32; 

int i = 0;
int xLEDVals[10] = {0,0,0,0,0,0,0,0,0,0};
int yLEDVals[10] = {0,0,0,0,0,0,0,0,0,0};
int zLEDVals[10] = {0,0,0,0,0,0,0,0,0,0};
int xRawVals[10] = {0,0,0,0,0,0,0,0,0,0};
int yRawVals[10] = {0,0,0,0,0,0,0,0,0,0};
int zRawVals[10] = {0,0,0,0,0,0,0,0,0,0};
int xSclVals[10] = {0,0,0,0,0,0,0,0,0,0};
int ySclVals[10] = {0,0,0,0,0,0,0,0,0,0};
int zSclVals[10] = {0,0,0,0,0,0,0,0,0,0};

void setup() {
  
  analogReference(EXTERNAL);
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(xLedPin, OUTPUT);
  pinMode(yLedPin, OUTPUT);
  pinMode(zLedPin, OUTPUT);
}

void loop() {
  int xRaw = ReadAxis(xInput);
  int yRaw = ReadAxis(yInput);
  int zRaw = ReadAxis(zInput);

  // Using Low llike the tutorial just didn't make sense in my head 
  // so wiring to the switch is as below:
  //  + --\/\/\------o-------GND
  //                  \------IN2
  if (digitalRead(buttonPin) == HIGH)
  {
    AutoCalibrate(xRaw, yRaw, zRaw);
  }
  else
  {
    // Convert raw values to 'milli-Gs"
    long xScaled = map(xRaw, xRawMin, xRawMax, -1000, 1000);
    long yScaled = map(yRaw, yRawMin, yRawMax, -1000, 1000);
    long zScaled = map(zRaw, zRawMin, zRawMax, -1000, 1000);

    
    // Convert rahighPass(w values straight to a pwm value for LEDs
    int xLED = highPass(abs(map(xRaw, zRawMin, zRawMax, -88, 88)));
    int yLED = highPass(abs(map(yRaw, zRawMin, zRawMax, -88, 88)));
    int zLED = highPass(abs(map(zRaw, zRawMin, zRawMax, -88, 88)), 80);

    analogWrite((xLedPin), xLED);
    analogWrite((yLedPin), yLED);
    analogWrite((zLedPin), zLED);
    
    
    // re-scale to fractional Gs
    float xAccel = xScaled / 1000.0;
    float yAccel = yScaled / 1000.0;
    float zAccel = zScaled / 1000.0;
    
    if (i = 0) {   
      Serial.print("Raw Ranges: X: ");
      Serial.print(xRawMin);
      Serial.print("-");
      Serial.print(xRawMax);
      
      Serial.print(", Y: ");
      Serial.print(yRawMin);
      Serial.print("-");
      Serial.print(yRawMax);
      
      Serial.print(", Z: ");
      Serial.print(zRawMin);
      Serial.print("-");
      Serial.print(zRawMax);
      Serial.println();
      Serial.print(xRaw);
      Serial.print(", ");
      Serial.print(yRaw);
      Serial.print(", ");
      Serial.print(zRaw);
  
      
      Serial.print(" :: ");
      Serial.print(xAccel);
      Serial.print("G, ");
      Serial.print(yAccel);
      Serial.print("G, ");
      Serial.print(zAccel);
      Serial.println("G");
      Serial.print("LEDs (x,y,z)");
      Serial.print(xLED);
      Serial.print(", ");
      Serial.print(yLED);
      Serial.print(", ");
      Serial.println(zLED);
    }
    delay(100);
    i = (++i % 10);
  }
}

//
// Read "sampleSize" samples and report the average
//
int ReadAxis(int axisPin)
{
  long reading = 0;
  analogRead(axisPin);
  delay(1);
  for (int i = 0; i < sampleSize; i++)
  {
    reading += analogRead(axisPin);
  }
  return reading/sampleSize;
}

int highPass(int value) {
  return highPass(value, 15);
}

int highPass(int value, int lowLimit) {
  return value > lowLimit ? value : 0;
}

//
// Find the extreme raw readings from each axis
//
void AutoCalibrate(int xRaw, int yRaw, int zRaw)
{
  Serial.println("Calibrate");
  if (xRaw < xRawMin)
  {
    xRawMin = xRaw;
  }
  if (xRaw > xRawMax)
  {
    xRawMax = xRaw;
  }
  
  if (yRaw < yRawMin)
  {
    yRawMin = yRaw;
  }
  if (yRaw > yRawMax)
  {
    yRawMax = yRaw;
  }
 
  if (zRaw < zRawMin)
  {
    zRawMin = zRaw;
  }
  if (zRaw > zRawMax)
  {
    zRawMax = zRaw;
  }
}


