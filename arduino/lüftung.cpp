#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme; // I2C

const int fanPin = 12; // Pin, an dem der Lüfter angeschlossen ist
const float humidityThreshold = 50; // Schwellwert für die Luftfeuchtigkeit, ab dem der Lüfter eingeschaltet werden soll

void setup() {
  Serial.begin(9600);
  pinMode(fanPin, OUTPUT); // Setze den Lüfter-Pin als Ausgang
  if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}

void loop() {
  float temperature = bme.readTemperature();
  float humidity = bme.readHumidity();

  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" *C");

  Serial.print("Humidity = ");
  Serial.print(humidity);
  Serial.println(" %");

  if (humidity > humidityThreshold) {
    digitalWrite(fanPin, HIGH); // Lüfter einschalten
    Serial.println("Fan ON");
  } else {
    digitalWrite(fanPin, LOW); // Lüfter ausschalten
    Serial.println("Fan OFF");
  }

  delay(2000);
}
