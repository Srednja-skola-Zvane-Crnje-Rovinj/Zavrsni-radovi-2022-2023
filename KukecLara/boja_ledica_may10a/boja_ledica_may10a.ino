#include "arduino_secrets.h"
#include "thingProperties.h"
#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    60
#define BRIGHTNESS  100
#define LED_TYPE    WS2812B
#define FADE_SPEED  5
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

void setup() {
  // Start serial communication with a baud rate of 9600
  Serial.begin(9600);
  // Delay for 1.5 seconds
  delay(1500);

  // Initialize the properties used by the Arduino Cloud service
  initProperties();

  // Begin the connection to the Arduino Cloud service using the preferred connection type
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  // Set the debug message level to 2 and print debug information to the serial monitor
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  // Delay for 3 seconds
  delay( 3000 );

  // Add the LED strip to the FastLED library, specify the LED type, pin, and color order, and set the color correction to TypicalLEDStrip
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

  // Set the LED strip brightness to the specified value
  FastLED.setBrightness(  BRIGHTNESS );
}

void loop() {
  ArduinoCloud.update();  // continuously updates the connection with the Arduino IoT Cloud
}

void onBojaLedChange()  {
  // If the power is on, update the color of the LED strip
  if (powerOnOff == true) {
    uint8_t r, g, b;
    // Get the RGB color value from the bojaLed property
    bojaLed.getValue().getRGB(r, g, b);

    // Set the color of each LED in the strip to the specified RGB value
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB(r, g, b);
    }

    // Show the updated LED strip color
    FastLED.show();
  }
  // If the power is off, do nothing
  else
  {

  }
}

void onPowerOnOffChange()  {     // Define the function for the Power On/Off state change event
  uint8_t r, g, b;               // Declare variables for red, green, and blue color values
  bojaLed.getValue().getRGB(r, g, b);   // Get the RGB color values from the "bojaLed" property

  if (  powerOnOff == true) {    // If the Power On/Off state is "true"
    for (int i = 0; i < NUM_LEDS; i++) {  // Loop through each LED in the strip
      leds[i] = CRGB(r, g, b);    // Set the color of the LED to the RGB values
    }
    FastLED.show();   // Update the LED strip with the new colors
  }
  else {    // If the Power On/Off state is "false"
    for (int i = 0; i < NUM_LEDS; i++) {  // Loop through each LED in the strip
      leds[i] = CRGB(0, 0, 0);   // Set the color of the LED to black (off)
    }
    FastLED.show();  // Update the LED strip with the new colors
  }
}


void onSvjetlinaLedChange()  {   // Define the function for the LED brightness change event
  FastLED.setBrightness(svjetlinaLed);   // Set the brightness of the LED strip to the value of the "svjetlinaLed" property
  FastLED.show();   // Update the LED strip with the new brightness level
}


void onFade1Change()  {   // Define the function for the Fade1 state change event
  if (fade1 == true) {   // If the Fade1 state is "true"
    uint8_t thisHue = beatsin8(10, 0, 255);  // Generate a hue value that changes over time
    fill_rainbow(leds, NUM_LEDS, thisHue, 10);   // Fill the LED strip with a rainbow pattern using the generated hue value
    FastLED.show();   // Update the LED strip with the new colors
  }
}
