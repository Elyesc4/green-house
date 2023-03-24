#!/usr/bin/env python
import serial
import json
import datetime
import os
from time import sleep

URL = 'http://localhost:3000/python'
FILE_PATH = '/home/www-dev/www/green-house/raspbarrypi/src/storage/sensor.json'


def updateFile(sensorData):
    # Öffnen der JSON-Datei und Laden des Inhalts in ein Dictionary
    with open(FILE_PATH, 'r') as file:
        data = json.load(file)

    # Aktualisierung des Werts des heutigen Datums im Dictionary
    # today = datetime.date.today().strftime('%Y-%m-%d %H:%M')
    today = datetime.datetime.now().isoformat()
    # today = datetime.datetime.now() #.strftime('%Y-%m-%d %H:%M:%S')
    updated_value = json.loads(sensorData)
    data[today] = updated_value

    # Schreiben des aktualisierten Dictionaries zurück in die JSON-Datei
    with open(FILE_PATH, 'w') as file:
        json.dump(data, file)


if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyS0', 9600, timeout=1)
    ser.reset_input_buffer()
    
    while True:
        sleep(1)
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').rstrip()
            updateFile(line)