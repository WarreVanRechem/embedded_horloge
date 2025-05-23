#include <FastLED.h>

#define LED_PIN A2  // A2 -> PA7 (Arduino pin 6)
#define NUM_LEDS 24
#define EN_LED_PIN A1  // A1 -> PB2 (Arduino pin 9)
#define BRIGHTNESS 12
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define BUTTON_PIN1 A3  // A3 -> PA3 (Arduino pin 2)
#define BUTTON_PIN2 A4  // A4 -> PA2 (Arduino pin 1)
#define BUTTON_PIN3 A5  // A5 -> PA1 (Arduino pin 0)
#define BUTTON_PIN4 A6  // A6 -> PA6 (Arduino pin 5)

CRGB leds[NUM_LEDS];

// Variables to store the previous button states for debouncing
int lastButton1State = HIGH;
int lastButton2State = HIGH;
int lastButton3State = HIGH;
int lastButton4State = HIGH;

// Variable to track the current LED pattern
int currentPattern = 0;  // 0: off, 1: Knop1, 2: Knop2, 3: Knop3, 4: Knop4

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  pinMode(EN_LED_PIN, OUTPUT);
  digitalWrite(EN_LED_PIN, HIGH);      // Enable LEDs
  pinMode(BUTTON_PIN1, INPUT_PULLUP);  // Knop3
  pinMode(BUTTON_PIN2, INPUT_PULLUP);  // Knop2
  pinMode(BUTTON_PIN3, INPUT_PULLUP);  // Knop1
  pinMode(BUTTON_PIN4, INPUT_PULLUP);  // Knop4
  delay(2000);                         // Initial delay
  // Start with LEDs off
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
}

void loop() {
  // Read the current state of each button
  int button1State = digitalRead(BUTTON_PIN1);  // Knop3
  int button2State = digitalRead(BUTTON_PIN2);  // Knop2
  int button3State = digitalRead(BUTTON_PIN3);  // Knop1
  int button4State = digitalRead(BUTTON_PIN4);  // Knop4

  // Apply the current pattern
  switch (currentPattern) {
    case 1:  // Knop1: Green triangle with red edges
      leds[0] = CRGB::Green;
      leds[1] = CRGB::Green;
      leds[2] = CRGB::Green;
      leds[3] = CRGB::Red;
      leds[4] = CRGB::Green;
      leds[5] = CRGB::Red;
      leds[6] = CRGB::Red;
      leds[7] = CRGB::Green;
      leds[8] = CRGB::Red;
      leds[9] = CRGB::Red;
      leds[10] = CRGB::Green;
      leds[11] = CRGB::Red;
      leds[12] = CRGB::Red;
      leds[13] = CRGB::Green;
      leds[14] = CRGB::Red;
      leds[15] = CRGB::Red;
      leds[16] = CRGB::Green;
      leds[17] = CRGB::Red;
      leds[18] = CRGB::Red;
      leds[19] = CRGB::Green;
      leds[20] = CRGB::Red;
      leds[21] = CRGB::Red;
      leds[22] = CRGB::Green;
      leds[23] = CRGB::Red;
      break;
    case 2:  // Knop2: Blue zigzag with white accents
      leds[0] = CRGB::Blue;
      leds[1] = CRGB::Black;
      leds[2] = CRGB::White;
      leds[3] = CRGB::Black;
      leds[4] = CRGB::Blue;
      leds[5] = CRGB::Black;
      leds[6] = CRGB::White;
      leds[7] = CRGB::Black;
      leds[8] = CRGB::Blue;
      leds[9] = CRGB::Black;
      leds[10] = CRGB::White;
      leds[11] = CRGB::Black;
      leds[12] = CRGB::Blue;
      leds[13] = CRGB::Black;
      leds[14] = CRGB::White;
      leds[15] = CRGB::Black;
      leds[16] = CRGB::Blue;
      leds[17] = CRGB::Black;
      leds[18] = CRGB::White;
      leds[19] = CRGB::Black;
      leds[20] = CRGB::Blue;
      leds[21] = CRGB::Black;
      leds[22] = CRGB::White;
      leds[23] = CRGB::Black;
      break;
    case 3:  // Knop3: Yellow wave with green dots
      leds[0] = CRGB::Yellow;
      leds[1] = CRGB::Black;
      leds[2] = CRGB::Yellow;
      leds[3] = CRGB::Green;
      leds[4] = CRGB::Yellow;
      leds[5] = CRGB::Black;
      leds[6] = CRGB::Yellow;
      leds[7] = CRGB::Green;
      leds[8] = CRGB::Yellow;
      leds[9] = CRGB::Black;
      leds[10] = CRGB::Yellow;
      leds[11] = CRGB::Green;
      leds[12] = CRGB::Yellow;
      leds[13] = CRGB::Black;
      leds[14] = CRGB::Yellow;
      leds[15] = CRGB::Green;
      leds[16] = CRGB::Yellow;
      leds[17] = CRGB::Black;
      leds[18] = CRGB::Yellow;
      leds[19] = CRGB::Green;
      leds[20] = CRGB::Yellow;
      leds[21] = CRGB::Black;
      leds[22] = CRGB::Yellow;
      leds[23] = CRGB::Green;
      break;
    case 4:  // Knop4: Purple diagonal with orange ends
      leds[0] = CRGB::Orange;
      leds[1] = CRGB::Purple;
      leds[2] = CRGB::Black;
      leds[3] = CRGB::Black;
      leds[4] = CRGB::Purple;
      leds[5] = CRGB::Black;
      leds[6] = CRGB::Black;
      leds[7] = CRGB::Purple;
      leds[8] = CRGB::Black;
      leds[9] = CRGB::Black;
      leds[10] = CRGB::Purple;
      leds[11] = CRGB::Black;
      leds[12] = CRGB::Black;
      leds[13] = CRGB::Purple;
      leds[14] = CRGB::Black;
      leds[15] = CRGB::Black;
      leds[16] = CRGB::Purple;
      leds[17] = CRGB::Black;
      leds[18] = CRGB::Black;
      leds[19] = CRGB::Purple;
      leds[20] = CRGB::Black;
      leds[21] = CRGB::Black;
      leds[22] = CRGB::Purple;
      leds[23] = CRGB::Orange;
      break;
    default:  // Off
      fill_solid(leds, NUM_LEDS, CRGB::Black);
      break;
  }

  // Check for button presses (LOW state) with debouncing
  if (button3State == LOW && lastButton3State == HIGH) {  // Knop1 pressed
    currentPattern = 1;
  }
  if (button2State == LOW && lastButton2State == HIGH) {  // Knop2 pressed
    currentPattern = 2;
  }
  if (button1State == LOW && lastButton1State == HIGH) {  // Knop3 pressed
    currentPattern = 3;
  }
  if (button4State == LOW && lastButton4State == HIGH) {  // Knop4 pressed
    currentPattern = 4;
  }

  // Update the previous button states
  lastButton1State = button1State;
  lastButton2State = button2State;
  lastButton3State = button3State;
  lastButton4State = button4State;

  FastLED.show();
  delay(100);  // Debounce delay
}
