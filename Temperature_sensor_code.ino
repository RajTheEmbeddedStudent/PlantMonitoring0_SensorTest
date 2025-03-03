#include "DHT.h" 
#define DHTPIN 26 
// Digital pin connected to the DHT sensor 
#define DHTTYPE DHT11 
// DHT 11 
DHT dht(DHTPIN, DHTTYPE); 
void setup() { 
  Serial.begin(9600); 
  Serial.println(F("DHT11 Sensor Reading with ESP32")); 
  dht.begin(); 
  } 
  void loop() { 
    delay(2000); 
    // Wait 2 seconds between readings 
    // Reading temperature 
    float tempC = dht.readTemperature();
    // Check if any reads failed and exit early (to try again) 
    if (isnan(tempC)) { 
      Serial.println(F("Failed to read from DHT sensor!")); 
      return; 
      } 
      // Print the temperature to the Serial Monitor 
      Serial.print(F("Temperature: ")); 
      Serial.print(tempC); 
      Serial.println(F(" °C"));
  }