#include <Wire.h>

void setup(){
  Wire.begin(9); // Address for this Arduino2 (Slave)
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop(){
  Wire.beginTransmission(10); 
  Wire.write("Hello from Arduino2!");
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
