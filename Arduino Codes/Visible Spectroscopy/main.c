#include "AS726X.h"


AS726X sensor;


void setup() 
{
  Wire.begin();
  Serial.begin(115200);
  sensor.begin();
}


void loop() 
{
  sensor.takeMeasurements();
   if (sensor.getGreen() == SENSORTYPE_AS7262)
  {
    //Visible readings
    Serial.print(" Reading: V[");
    Serial.print(sensor.getCalibratedViolet(), 2);
    Serial.print("] B[");
    Serial.print(sensor.getCalibratedBlue(), 2);
    Serial.print("] G[");
    Serial.print(sensor.getCalibratedGreen(), 2);
    Serial.print("] Y[");
    Serial.print(sensor.getCalibratedYellow(), 2);
    Serial.print("] O[");
    Serial.print(sensor.getCalibratedOrange(), 2);
    Serial.print("] R[");
    Serial.print(sensor.getCalibratedRed(), 2);
  }


  Serial.print("] tempF[");
  Serial.print(sensor.getTemperature(), 1);
  Serial.print("]");


  Serial.println();
}
