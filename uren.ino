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

// Variabele voor buitenste ring patroon
int currentOuterLed = 0;  // Huidige LED in buitenste ring

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

    // Zet de huidige LED in de buitenste ring aan (LEDs 0-11) op wit
    leds[currentOuterLed] = CRGB::White;

    // Ga naar de volgende LED in de buitenste ring
    currentOuterLed = (currentOuterLed + 1) % 12;  // Beperk tot LEDs 0-11

    // Update tijdstempel
    lastUpdateTime = millis();
  }

  // Update LEDs
  FastLED.show();
}
