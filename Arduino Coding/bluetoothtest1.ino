#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);
  
  bluetooth.begin(9600);
  Serial.println("Bluetooth Two-Way Ready");
}

void loop() {
  // Read from Serial Monitor, send via Bluetooth
  if (Serial.available()) {
    String message = Serial.readStringUntil('\n');
    bluetooth.println(message);
    Serial.println("Sent: " + message);
  }

  // Read from Bluetooth, print to Serial
  if (bluetooth.available()) {
    String received = bluetooth.readStringUntil('\n');
    Serial.println("Received: " + received);
  }
}
