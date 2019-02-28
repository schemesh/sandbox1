#include <OneWire.h>
#include <DallasTemperature.h>
#include <temperature.h>
 
#define MAX_SENSORS 5
static byte sensors = 0;
static OneWire* bus[MAX_SENSORS];
static DallasTemperature sensor[MAX_SENSORS];

byte temperatureSetupSensor(byte pin){
  if(sensors == MAX_SENSORS-1) 
    return -1;
  bus[sensors] = new OneWire(pin);
  sensor[sensors] = DallasTemperature(bus[sensors]);
  sensor[sensors].begin();
  sensors++;
  return sensors - 1; // Return Id of the sensor <>
}
 
void temperatureStartMeasure(byte sensorId) {
  sensor[sensorId].requestTemperatures();
}

float temperatureRead(byte sensorId) {
  return sensor[sensorId].getTempCByIndex(0);
}
