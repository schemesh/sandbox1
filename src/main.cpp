#include <Arduino.h>
#include <temperature.h>

byte idt1,idt2;

void setup() {
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");
  idt1 = temperatureSetupSensor(4);
  idt2 = temperatureSetupSensor(5);
}

void loop() {
  temperatureStartMeasure(idt1);
  temperatureStartMeasure(idt2);
  delay(1000);
  Serial.print("Sensor 1: ");
  Serial.println(temperatureRead(idt1));
  Serial.print("Sensor 2: ");
  Serial.println(temperatureRead(idt2));
}