#include <SPI.h>

const int slaveSelectPin = 10;

void setup() {
  Serial.begin(9600);
  
  // Configure SS as output
  pinMode(slaveSelectPin, OUTPUT);
  digitalWrite(slaveSelectPin, HIGH);

  // Initialize SPI as master
  SPI.begin();
}

void loop() {
  char dataToSend = 'A';  // Data to send to the slave
  char receivedData;

  // Select the slave
  digitalWrite(slaveSelectPin, LOW);

  // Transfer data
  receivedData = SPI.transfer(dataToSend);

  // Deselect the slave
  digitalWrite(slaveSelectPin, HIGH);

  // Print received data
  Serial.print("Received from Slave: ");
  Serial.println(receivedData);

  delay(1000); // 1-second delay
}
