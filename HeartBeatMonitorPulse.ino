// THE HEART MONITOR
// Code put together by Inga Woods-Waight
// TikTok - @ingawoods.waight
// Instagram - @ingawoods.waight


// Define the pins for the pulse sensor and LEDs
int pulsePin = A0;
int greenLedPin = 8;
int yellowLedPin = 9;
int redLedPin = 10;

// Variables to store the heart rate and LED brightness values
int heartRate = 0;
int greenBrightness = 0;
int yellowBrightness = 0;
int redBrightness = 0;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Set the LED pins as output
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
}

void loop() {
  // Read the pulse sensor value and calculate the heart rate
  int pulseValue = analogRead(pulsePin);
  heartRate = map(pulseValue, 0, 1023, 0, 220);

  // Print the heart rate to the serial monitor
  Serial.print("Heart rate: ");
  Serial.println(heartRate);

  // Update the LED brightness based on the heart rate range
  if (heartRate <= 80) {
    greenBrightness = 255;
    yellowBrightness = 0;
    redBrightness = 0;
  }
  else if (heartRate > 80 && heartRate <= 100) {
    greenBrightness = map(heartRate, 81, 100, 255, 255);
    yellowBrightness = map(heartRate, 81, 100, 0, 255);
    redBrightness = 0;
  }
  else {
    greenBrightness = 0;
    yellowBrightness = map(heartRate, 101, 110, 255, 0);
    redBrightness = map(heartRate, 101, 110, 255, 255);
  }

  // Update the LED brightness values
  analogWrite(greenLedPin, greenBrightness);
  analogWrite(yellowLedPin, yellowBrightness);
  analogWrite(redLedPin, redBrightness);

  // Delay for a short period of time before looping again
  delay(10);
}
