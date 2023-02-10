const int LIGHT_SENSOR_PIN = A0; // Arduino pin connected to light sensor's  pin
const int LED_PIN          = 3;  // Arduino pin connected to LED's pin
const int ANALOG_THRESHOLD = 500;

const int RELAY_PIN = 2;  // the Arduino pin, which connects to the IN pin of relay

int analogValue;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT); // set arduino pin to output mode
}

void loop() {
  analogValue = analogRead(LIGHT_SENSOR_PIN);

  if(analogValue < ANALOG_THRESHOLD)
    digitalWrite(RELAY_PIN, HIGH); // turn on LED
  else
    digitalWrite(RELAY_PIN, LOW);  // turn off LED  
  delay(500);
}

