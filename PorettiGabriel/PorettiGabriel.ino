#include "arduino_secrets.h"
#include "thingProperties.h"
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#define DHTPIN 10
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int relayPin1 = 1;
const int relayPin2 = 2;
const int relayPin3 = 3;
const int soilMoisturePin = A1;
const int lightSensorPin = A0;
const int battLevelPin = A6;

// Define the soil moisture range
const int soilMoistureMin = 1023;
const int soilMoistureMax = 0;
const int soilHumidityMin = 0;
const int soilHumidityMax = 100;

int soilMoisture;
int lightLevel;
int batt;

const float minVoltage = 3.0;          // Minimum battery voltage
const float maxVoltage = 4.2;          // Maximum battery voltage
const float fullChargeVoltage = 4.1;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Initialize the OLED display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  // Initialize the relay pins
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  pinMode(relayPin3, OUTPUT);

  // Start the DHT sensor
  dht.begin();
  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here // Read sensor data
  airTemperature = dht.readTemperature();
  airHumidity = dht.readHumidity();
  soilMoisture = analogRead(soilMoisturePin);
  lightLevel = analogRead(lightSensorPin);
  batt = analogRead(battLevelPin);
  Serial.println(batt);
  Serial.println(baterija);
  float battVoltage = batt * (3.7 / 1023.0);
  baterija = calculateBatteryPercentage(battVoltage);
  // Map soil moisture to soil humidity range
  soilHumidity = map(soilMoisture, soilMoistureMin, soilMoistureMax, soilHumidityMin, soilHumidityMax);
  light = map (lightLevel, 1023, 0, 0, 100);
  // Display air temperature and humidity on OLED screen
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Temp: ");
  display.print(airTemperature);
  display.println("C");
  display.print("Vlaga: ");
  display.print(airHumidity);
  display.println("%");
  display.setTextSize(1);
  display.print("Zemlja: ");
  display.print(soilHumidity);
  display.println("%");
  display.setTextSize(1);
  display.print("Svjetlo: ");
  display.print(light);
  display.println("%");
  display.setTextSize(1);
  display.print("Baterija: ");
  display.print(baterija);
  display.println("%");
  display.display();

  Serial.print("Temp: ");
  Serial.print(airTemperature);
  Serial.println("C");
  Serial.print("Vlaga: ");
  Serial.print(airHumidity);
  Serial.println("%");
  Serial.print("Zemlja: ");
  Serial.print(soilHumidity);
  Serial.println("%");
  Serial.print("Svjetlo: ");
  Serial.print(light);
  Serial.println("%");

// Check soil humidity and activate relay 1 if below 60%
  if (soilHumidity < 60) {
    digitalWrite(relayPin1, HIGH);
  } else {
    digitalWrite(relayPin1, LOW);
  }

  // Delay before next reading
  delay(1000);


}

int calculateBatteryPercentage(float voltage) {
  if (voltage < minVoltage) {
    return 0;
  } else if (voltage > maxVoltage) {
    return 100;
  } else {
    return (voltage - minVoltage) / (fullChargeVoltage - minVoltage) * 100;
  }
}

/*
  Since AirHumidity is READ_WRITE variable, onAirHumidityChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onAirHumidityChange()  {
  // Add your code here to act upon AirHumidity change
}

/*
  Since AirTemperature is READ_WRITE variable, onAirTemperatureChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onAirTemperatureChange()  {
  // Add your code here to act upon AirTemperature change
}

/*
  Since SoilHumidity is READ_WRITE variable, onSoilHumidityChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onSoilHumidityChange()  {
  // Add your code here to act upon SoilHumidity change
    
}

/*
  Since Light is READ_WRITE variable, onLightChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLightChange()  {
  // Add your code here to act upon Light change
}
/*
  Since Baterija is READ_WRITE variable, onBaterijaChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onBaterijaChange()  {
  // Add your code here to act upon Baterija change
}