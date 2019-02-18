
#include <Wire.h>
#include <BH1750.h>

#include <Adafruit_Sensor.h>
#include "DHT.h"

#define DHTPIN 13    
#define DHTTYPE DHT22   
DHT dht(DHTPIN, DHTTYPE);
BH1750 lightMeter(0x23);

float lux;

void setup() {
  Serial.begin(115200);
   lightMeter.begin();
  Wire.begin();

  dht.begin();
}

void loop() {

 delay(500);
  
 lux = lightMeter.readLightLevel();
 // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
   
 // Check if any reads failed and exit early (to try again).
  if (isnan(lux) || isnan(h) || isnan(t)) {
    Serial.println("0 , 0 , 0");
    return;
 
  }
  Serial.print(lux);
  Serial.print(" , ");
  Serial.print(h);
  Serial.print(" , ");
  Serial.println(t);
  
  delay(500);
  
  


 
 
}
