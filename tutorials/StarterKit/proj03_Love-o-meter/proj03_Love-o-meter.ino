/* Arduino Starter Kit Tutorial
 * Love-o-meter   (temperature sensor)
 */
 const int sensorPin = A0;
 const float baselineTemp = 24.0;
 
 void setup() {
   //open serial port at 9600 bits per second
   Serial.begin(9600);
   
   // for pins 2 to 4
   for (int pinNum = 2; pinNum < 5; pinNum++){
     // set to output mode
     pinMode(pinNum, OUTPUT);
     /* write LOW to pin (or turn off, as they are 
      *   hooked up to LEDs)
      */
     digitalWrite(pinNum, LOW);
   }
 }
 
 void loop() {
   // Read the analog value from sensor pin
   int sensorVal = analogRead(sensorPin);
   
   // Output raw sensor value to console window
   Serial.print("Sensor Value: ");
   Serial.print(sensorVal);
   
   // get sensor value as a voltage
   //   (Assumption: 0 < sensorVal < 1024)
   float voltage = (sensorVal/1024.0) * 5;
   
   // Output Voltage
   Serial.print(", Volts: ");
   Serial.print(voltage);
   
   // Convert voltage to temperature in degrees C
   float temperature = (voltage - 0.5) * 100;
   
   // Output temperature
   Serial.print(", degrees C: ");
   Serial.println(temperature);
   
   if (temperature < baselineTemp) {
     digitalWrite(2, LOW);
     digitalWrite(3, LOW);
     digitalWrite(4, LOW);
   } else if (temperature >= baselineTemp && 
    temperature < baselineTemp + 1) {
     digitalWrite(2, HIGH);
     digitalWrite(3, LOW);
     digitalWrite(4, LOW);
   } else if (temperature >= baselineTemp +1 && 
    temperature < baselineTemp + 2) {
     digitalWrite(2, HIGH);
     digitalWrite(3, HIGH);
     digitalWrite(4, LOW);
   } else if (temperature >= baselineTemp +4) {
     digitalWrite(2, HIGH);
     digitalWrite(3, HIGH);
     digitalWrite(4, HIGH);
   }
   
   delay(1);
 }   
   
