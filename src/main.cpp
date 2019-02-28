#include <Arduino.h>
#include <temperature.h>
#include <Adafruit_MCP4725.h>


Adafruit_MCP4725 dac;
byte idt1,idt2;

void setup() {
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");
  idt1 = temperatureSetupSensor(4);
  idt2 = temperatureSetupSensor(5);
  dac.begin(0x60);
}

void loop() {
  temperatureStartMeasure(idt1);
  temperatureStartMeasure(idt2);
  delay(250);
  Serial.print("Sensor 1: ");
  Serial.println(temperatureRead(idt1));
  Serial.print("Sensor 2: ");
  Serial.println(temperatureRead(idt2));
  for(int i=0;i<4096;i+=300)
  {
    dac.setVoltage(i,false);
    delay(1);
  }
}