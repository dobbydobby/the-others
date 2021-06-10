#include <Adafruit_NeoPixel.h>
#define PIN 7
#define LEDNUM 2
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDNUM, PIN, NEO_GRB + NEO_KHZ800);
void setup() {
}
void loop() {
  strip.begin();
  strip.show();
  strip.setPixelColor(0, 255, 0, 255);
  delay(3000);
  strip.setPixelColor(0, 255, 255, 0);
  strip.setPixelColor(1, 0, 255, 0);
  delay(3000);
}
