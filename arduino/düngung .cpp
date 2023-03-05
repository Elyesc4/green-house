// Define variables for time interval and pump pin
unsigned long interval = 2419200000; // 4 weeks in milliseconds
int pumpPin = 8;

void setup() {
  // Initialize pump pin as output
  pinMode(pumpPin, OUTPUT);
}

void loop() {
  // Get current time
  unsigned long currentTime = millis();

  // Check if 4 weeks have passed
  if (currentTime % interval == 0) {
    // Activate pump for 5 seconds
    digitalWrite(pumpPin, HIGH);
    delay(5000);
    digitalWrite(pumpPin, LOW);
  }
}