

// ****************
// Wifi Setup

#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#include <ESP8266WebServer.h>

#define esp8266_rest_pin 13

//define server and access port
ESP8266WebServer server(80);

//define wifi network and password
const char *ssid = "Huzzah_001";
const char *password = "password";


//*********
// LED Setup

#include <Adafruit_NeoPixel.h>
#define NEOPIN 4

int LEDs = 1; // number of LEDs in a strip

int color = 0;
int wheelRate = 10;

boolean white = false; //use to toggle all white LEDs
boolean displayMode = true;

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDs, NEOPIN, NEO_GRB + NEO_KHZ800);

long currMillis = 0;
long prevMillis = 0;


void setup() {

  Serial.begin(57600);

//configure wifi connection
  wifiConfig();

//***Initialize Display
  strip.begin();
  strip.show();
  
}


void loop() {
  
  currMillis = millis(); //manage time

  server.handleClient();  //set mode and variables

  //show lightshow display
  if(millis() - prevMillis > wheelRate){
    for(uint16_t i=0; i<strip.numPixels(); i++) {
      if(displayMode) {
        if(!white) strip.setPixelColor(i, Wheel(color)); //set to color
        else strip.setPixelColor(i,255,255,255); //set to white
      }
      else strip.setPixelColor(i, 0); //turn off LEDs
    }
      if(color>255) color=0; else color++; // loop back to the begining of color wheel
      strip.show(); //push to NeoPixels
      
      prevMillis = millis(); //manage time
  }

}


// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}


