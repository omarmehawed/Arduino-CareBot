#include <Wire.h> 
7 #include "MAX30100_PulseOximeter.h" 
8 
9 PulseOximeter pox; 
10 uint32_t lastReport = 0; 
11 const uint32_t REPORT_PERIOD_MS = 1000; 
// Create a PulseOximeter object 
// Report data every 1000 ms 
12 
13 void setup() { 
14 Serial.begin(9600); 
15 
Serial.println("Initializing MAX30100..."); 
16 
17 
18 
// Initialize the sensor 
if (!pox.begin()) { 
19 
20 
// If initialization fails, print error and halt 
Serial.println("MAX30100 not found! Check wiring."); 
21 
while (1); 
22 
} 
23 
Serial.println("MAX30100 initialized."); 
} 
 void loop() { 
// Must be called frequently to update sensor readings 
 pox.update(); 

float sp02 = pox.getSp02(); 
Serial.print("Heart Rate: "); 
 
Serial.print(heartRate); 
 
// (Optional) Adjust LED current for brightness/signal: 
// pox.setIRLed Current (MAX30100_LED_CURR_7_6MA); // Example: set IR LED to 7.6 mA 
// Every REPORT_PERIOD_MS milliseconds, read and print values 
if (millis() lastReport > REPORT_PERIOD_MS) { 
lastReport = millis(); 
float heartRate = pox.getHeartRate(); 
// beats per minute 
Serial.print(" BPM, SpO2: "); 
// blood oxygen percentage 

Serial.print(sp02); 

Serial.println(" %"); 

}