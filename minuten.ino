#include <FastLED.h>  // Bibliotheek voor LEDs

#define LED_PIN A2        // Datapin PA2
#define NUM_LEDS 28       // Aantal LEDs
#define EN_LED_PIN A1     // Enable pin PA1
#define BRIGHTNESS 12     // Helderheid LEDs
#define LED_TYPE WS2812B  // Type LED
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

// Tijdvariabelen voor LED-schakeling
unsigned long lastUpdateTime = 0;
const unsigned long UPDATE_INTERVAL = 1000;  // Update elke seconde

// Variabele voor binnenste ring patroon
int currentInnerLed = 12;  // Huidige LED in binnenste ring (start bij LED 12)

void setup() {
  // Initialiseren LED-strip
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);

  // LED-strip aanzetten
  pinMode(EN_LED_PIN, OUTPUT);
  digitalWrite(EN_LED_PIN, HIGH);

  // Start met alle LEDs uit
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();

  delay(2000);  // Opstartdelay
}

void loop() {
  // Update LED elke seconde
  if (millis() - lastUpdateTime >= UPDATE_INTERVAL) {
    // Zet alle LEDs uit
    fill_solid(leds, NUM_LEDS, CRGB::Black);

    // Zet de huidige LED in de binnenste ring aan (LEDs 12-23) op wit
    leds[currentInnerLed] = CRGB::White;

    // Ga naar de volgende LED in de binnenste ring
    currentInnerLed = 12 + ((currentInnerLed - 12 + 1) % 12);  // Beperk tot LEDs 12-23

    // Update tijdstempel
    lastUpdateTime = millis();
  }

  // Update LEDs
  FastLED.show();
}
