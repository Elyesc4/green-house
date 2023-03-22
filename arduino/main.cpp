#include <Wire.h>
#include "Adafruit_Si7021.h"

// @osl Temperatur & Luftfeuchtigkeit regulierung
#define FAN_PIN 9             // Definiere den Pin des Lüfters
#define TEMP_THRESHOLD 30     // Definiere den Schwellenwert der Temperatur in Grad Celsius
#define HUMIDITY_THRESHOLD 60 // Definiere den Schwellenwert der relativen Luftfeuchtigkeit in Prozent

Adafruit_Si7021 sensor = Adafruit_Si7021();

#define LIGHT_SENSOR_PIN A0 // Arduino pin connected to light sensor's  pin
#define LED_PIN 3          // Arduino pin connected to LED's pin
#define LUX_THRESHOLD 80
#define LED_RELAY_PIN 2

void setup()
{
    Serial.begin(9600);
    pinMode(FAN_PIN, OUTPUT);

    pinMode(LED_RELAY_PIN, OUTPUT); // set arduino pin to output mode
    if (!sensor.begin())
    {
        Serial.println("Sensor konnte nicht gefunden werden, bitte überprüfen Sie die Verbindung!");
         while (true); // todo @ebr wofür?
    }
}

void loop()
{
    float temperature = sensor.readTemperature();
    float humidity = sensor.readHumidity();
    float lux_analog_value = analogRead(LIGHT_SENSOR_PIN);

//    Serial.println("Hello from Arduino!");
    setFan(temperature, humidity);
    setLEDs(lux_analog_value);
    delay(500);
}

void setFan(float temperature, float humidity)
{
    // Wenn die Temperatur den Schwellenwert überschreitet oder die relative Luftfeuchtigkeit unter dem Schwellenwert liegt, schalte den Lüfter ein
    if (temperature <= TEMP_THRESHOLD || humidity < HUMIDITY_THRESHOLD)
    {
        digitalWrite(FAN_PIN, LOW);
    }
    else
    {
        digitalWrite(FAN_PIN, HIGH);
    }
}

void setLEDs(float analogValue)
{
    if (analogValue < LUX_THRESHOLD)
        digitalWrite(LED_RELAY_PIN, HIGH); // turn on LED
    else
        digitalWrite(LED_RELAY_PIN, LOW); // turn off LED
}