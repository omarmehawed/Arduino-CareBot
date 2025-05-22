2/* 
  Arduino sketch to read heart rate (BPM) and SpO2 from the MAX30100 sensor.
  Uses the MAX30100_PulseOximeter library by Oxullo (install via Library Manager).
*/

#include <Wire.h>
#include "MAX30100_PulseOximeter.h"

PulseOximeter pox;                         // Create a PulseOximeter object
uint32_t lastReport = 0;
const uint32_t REPORT_PERIOD_MS = 1000;    // Report data every 1000 ms

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing MAX30100...");

  // Initialize the sensor
  if (!pox.begin()) {
    // If initialization fails, print error and halt
    Serial.println("MAX30100 not found! Check wiring.");
    while (1);
  }
  Serial.println("MAX30100 initialized.");

  // (Optional) Adjust LED current for brightness/signal:
  // pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);  // Example: set IR LED to 7.6 mA
}

void loop() {
  // Must be called frequently to update sensor readings
  pox.update();

  // Every REPORT_PERIOD_MS milliseconds, read and print values
  if (millis() - lastReport > REPORT_PERIOD_MS) {
    lastReport = millis();
    float heartRate = pox.getHeartRate();  // beats per minute
    float spO2      = pox.getSpO2();       // blood oxygen percentage
    Serial.print("Heart Rate: ");
    Serial.print(heartRate);
    Serial.print(" BPM, SpO2: ");
    Serial.print(spO2);
    Serial.println(" %");
  }
}
