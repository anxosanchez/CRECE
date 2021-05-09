#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include <Servo.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, PIN, NEO_GRB + NEO_KHZ800);

Servo myservo;

int pos = 90;

int buttonPin = 10;

int counter = 0;

int sensorPin = A3;
int sensorValue = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  strip.begin();
  strip.setBrightness(3);
  strip.show(); // Initialize all pixels to 'off'
  pinMode(buttonPin, INPUT_PULLUP);
  colorWipe(strip.Color(255, 0, 0), 50); // Red
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    counter = counter + 1;
  }
  else {
    counter = 0;
  }
  delay(50);
  if (counter > 30) {
    colorWipe(strip.Color(0, 255, 0), 50); // Green
    rainbowCycle(10);
    myservo.attach(13);
    colorWipe(strip.Color(0, 255, 0), 50); // Green
    Serial.println("START OF TEST");
    myservo.write(170);
    delay(50);
    for (pos = 170; pos >= 40; pos -= 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      sensorValue = analogRead(sensorPin);
      Serial.println(sensorValue);
      delay(100);                       // waits 15ms for the servo to reach the position
    }
    delay(3000);
    for (pos = 40; pos <= 170; pos += 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(30);                       // waits 15ms for the servo to reach the position
    }

    Serial.println();
    delay(2000);
    colorWipe(strip.Color(255, 0, 0), 50); // Red
    counter = 0;
    myservo.detach();
  }
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

// rainbowCycle(10);
// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;
  for (j = 0; j < 256 * 4; j++) { // 1 cycles of all colors on wheel
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(4);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
