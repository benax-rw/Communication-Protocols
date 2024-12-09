#include <SPI.h>

volatile char receivedData;
volatile bool dataReceived = false;

void setup() {
  Serial.begin(9600);

  // Set MISO as output
  pinMode(MISO, OUTPUT);

  // Enable SPI as slave
  SPCR |= _BV(SPE);
  
  // Enable SPI interrupt
  SPCR |= _BV(SPIE);

  // Enable global interrupts
  sei();
}

void loop() {
  if (dataReceived) {
    Serial.print("Received from Master: ");
    Serial.println(receivedData);

    // Send response back to master
    SPDR = receivedData + 1;  // Modify received data as a response

    dataReceived = false;
  }
}

// SPI interrupt service routine
ISR(SPI_STC_vect) {
  receivedData = SPDR; // Read received data
  dataReceived = true;
}
