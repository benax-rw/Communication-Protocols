#include <Wire.h>

void setup() {
  Wire.begin(10);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop(){
  Wire.beginTransmission(9); // The address of Arduino2 (Slave) should be known.
  Wire.write("Hello from Arduino1!");
  Wire.endTransmission();

  delay(1000);
}

void receiveEvent() {
  Serial.print("Received Message: ");
  while (Wire.available()) {
    char receivedChar = Wire.read();
    Serial.print(receivedChar);
  }
  Serial.println();
}

