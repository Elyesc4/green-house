#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_Si7021.h>

// Definiere den Pin des Lüfters
#define FAN_PIN 9

// Definiere den Schwellenwert der Temperatur in Grad Celsius
#define TEMP_THRESHOLD 30

// Definiere den Schwellenwert der relativen Luftfeuchtigkeit in Prozent
#define HUMIDITY_THRESHOLD 60

Adafruit_Si7021 sensor = Adafruit_Si7021();

void setup() {
  Serial.begin(9600);
  pinMode(FAN_PIN, OUTPUT);
  if (!sensor.begin()) {
    Serial.println("Sensor konnte nicht gefunden werden, bitte überprüfen Sie die Verbindung!");
    while (true);
  }
}

void loop() {
  float temperature = sensor.readTemperature();
  // Serial.print("Temperatur: ");
  // Serial.print(temperature);
  // Serial.println(" *C");

  float humidity = sensor.readHumidity();
  // Serial.print("Luftfeuchtigkeit: ");
  // Serial.print(humidity);
  // Serial.println(" %");

  // Wenn die Temperatur den Schwellenwert überschreitet und die relative Luftfeuchtigkeit unter dem Schwellenwert liegt, schalte den Lüfter ein
  if (temperature <= TEMP_THRESHOLD || humidity < HUMIDITY_THRESHOLD) {
    digitalWrite(FAN_PIN, LOW);
  } else {
    digitalWrite(FAN_PIN, HIGH);
  }

  delay(1000);
}