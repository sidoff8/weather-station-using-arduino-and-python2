

#include <Wire.h>
#include <BH1750.h>

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN            13 
#define DHTTYPE           DHT22 
BH1750 lightMeter;
DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

void setup(){
 Serial.begin(115200);
  Wire.begin();
  
  lightMeter.begin();
     
 dht.begin();
  

}


void loop() {

  uint16_t lux = lightMeter.readLightLevel();
 
  Serial.print(lux);
  Serial.print(" , ");

  
   sensors_event_t event;  
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.print("0");
    Serial.print(" , ");
  }
  else {
    float temp;
    temp = event.temperature;
    Serial.print(temp);
    Serial.print(" , ");
  }
   
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.print("0");
  }
  else {
   float humd;
   humd = event.relative_humidity;
    Serial.print(humd);
    Serial.println();   
  }

 
  
  
  delay(250);
  
    delay(delayMS);

}
