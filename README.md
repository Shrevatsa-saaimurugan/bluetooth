# bluetooth
This Arduino code enables control of an LED through a Bluetooth module. It waits for incoming data from the Bluetooth module and interprets the received commands to turn the LED on or off.

Here's a breakdown of the code:

### 1. Pin Definitions and Initialization:

```cpp
int ledPin = 13;
```

- **LED Pin:** Defines the pin number for the LED (pin 13 in this case).

### 2. Setup Function:

```cpp
void setup() {
  // Initialize serial communication with a baud rate of 9600
  Serial.begin(9600);

  // Set LED pin as an output
  pinMode(ledPin, OUTPUT);
}
```

- **Serial Communication:** Initializes serial communication with a baud rate of 9600 to communicate with the Bluetooth module.
- **LED Pin Configuration:** Sets the LED pin as an output using `pinMode()`.

### 3. Loop Function:

```cpp
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
  }
}
```

- **Serial Data Reception:**
  - Checks if there is data available to read from the Bluetooth module using `Serial.available()`.
  - If data is available, it reads the incoming character using `Serial.read()`.

- **Command Interpretation:**
  - Checks the received command:
    - If the command is '1', it turns on the LED (`digitalWrite(ledPin, HIGH)`).
    - If the command is '0', it turns off the LED (`digitalWrite(ledPin, LOW)`).

This code assumes that the Bluetooth module sends '1' to turn on the LED and '0' to turn it off. Adjustments might be necessary based on the specific communication protocol used by your Bluetooth module.

Make sure to connect the Bluetooth module to the correct RX and TX pins on your Arduino, and configure the baud rate accordingly. Additionally, ensure that the ground of the Bluetooth module is connected to the ground of the Arduino to establish a common ground reference.
