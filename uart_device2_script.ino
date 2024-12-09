#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  // User input to send a custom message
  if (Serial.available()) {
    String userMessage = Serial.readStringUntil('\n');
    mySerial.println(userMessage); 
  }

  // Check for incoming message from Arduino1
  if (mySerial.available()){
    String receivedData = mySerial.readStringUntil('\n');
    Serial.print("Rx Msg: ");
    Serial.println(receivedData);
  }
}
