#include <FastLED.h>  // Bibliotheek voor LEDs

#define LED_PIN A2        // Datapin PA2 (voor ATtiny1614, pin PA2)
#define NUM_LEDS 28       // Aantal LEDs
#define EN_LED_PIN A1     // Enable pin PA1 (voor ATtiny1614, pin PA1)
#define BRIGHTNESS 12     // Helderheid LEDs
#define LED_TYPE WS2812B  // Type LED (WS2812B)
#define COLOR_ORDER GRB   // Kleurvolgorde (Green, Red, Blue)

CRGB leds[NUM_LEDS];  // Array om LED-kleuren op te slaan

// Tijdvariabelen voor LED-schakeling
unsigned long lastUpdateTime = 0;
const unsigned long UPDATE_INTERVAL = 1000;  // Update elke seconde (1000 ms)

// Variabele voor buitenste ring patroon
int currentOuterLed = 0;  // Huidige LED in buitenste ring (LEDs 0-11)
bool ledState = false;    // Staat van de LEDs (aan/uit)

void setup() {
  // Initialiseren LED-strip
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);  // Stel helderheid in

  // Stel EN_LED_PIN in als uitgang
  pinMode(EN_LED_PIN, OUTPUT);

  // Start met LEDs uit: zet MOSFET hoog (LEDs uit)
  digitalWrite(EN_LED_PIN, HIGH);  // Hoog = MOSFET uit, LEDs uit

  // Start met alle LEDs uit
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();

  delay(2000);  // Opstartdelay van 2 seconden
}

void loop() {
  // Controleer of het tijd is om de LEDs te updaten (elke seconde)
  if (millis() - lastUpdateTime >= UPDATE_INTERVAL) {
    // Wissel de LED-staat
    ledState = !ledState;

    if (ledState) {
      // Zet MOSFET laag om LEDs aan te zetten
      digitalWrite(EN_LED_PIN, LOW);  // Laag = MOSFET aan, LEDs aan
      fill_solid(leds, NUM_LEDS, CRGB::Black);  // Zet alle LEDs uit
      leds[currentOuterLed] = CRGB::White;      // Zet huidige LED aan
    } else {
      // Zet MOSFET hoog om LEDs uit te zetten
      digitalWrite(EN_LED_PIN, HIGH);  // Hoog = MOSFET uit, LEDs uit
      fill_solid(leds, NUM_LEDS, CRGB::Black);  // Zet alle LEDs uit
    }

    // Ga naar de volgende LED in de buitenste ring (cyclus van 0 naar 11)
    currentOuterLed = (currentOuterLed + 1) % 12;  // Beperk tot LEDs 0-11

    // Update tijdstempel voor de volgende iteratie
    lastUpdateTime = millis();

    // Update de LED-strip om de nieuwe kleuren te tonen
    FastLED.show();
  }
}
