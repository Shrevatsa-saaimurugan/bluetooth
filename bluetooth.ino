int ledPin = 13;

void setup() {
  // Initialize serial communication with a baud rate of 9600
  Serial.begin(9600);

  // Set LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Check if data is available to read from the Bluetooth module
  if (Serial.available() > 0) {
    // Read the incoming character
    char command = Serial.read();

    // Check the received command
    if (command == '1') {
      // Turn ON the LED
      digitalWrite(ledPin, HIGH);
    } else if (command == '0') {
      // Turn OFF the LED
      digitalWrite(ledPin, LOW);
    }
  }}
