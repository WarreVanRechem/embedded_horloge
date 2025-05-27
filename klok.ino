#include <FastLED.h>  // Bibliotheek voor LEDs

#define LED_PIN A2        // Datapin PA2
#define NUM_LEDS 28       // Aantal LEDs
#define EN_LED_PIN A1     // Enable pin PA1
#define BRIGHTNESS 12     // Helderheid LEDs
#define LED_TYPE WS2812B  // Type LED
#define COLOR_ORDER GRB
#define BUTTON_PIN1 A3  // Knop 1 op PA3
#define BUTTON_PIN2 A4  // Knop 2 op PA4
#define BUTTON_PIN3 A5  // Knop 3 op PA5
#define BUTTON_PIN4 A6  // Knop 4 op PA6

CRGB leds[NUM_LEDS];

// Vorige toestand van knoppen
int lastButton1State = HIGH;
int lastButton2State = HIGH;
int lastButton3State = HIGH;
int lastButton4State = HIGH;

// Huidig patroon
int currentPattern = 0;

// Tijdvariabelen
unsigned long lastUpdateTime = 0;
const unsigned long UPDATE_INTERVAL = 1000;  // Update elke seconde
const int TIME_ACCELERATION = 1;             // Normale snelheid
int hours = 11;
int minutes = 0;
int seconds = 0;

void setup() {
  // Initialiseren LED-strip
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);

  // LED-strip aanzetten
  pinMode(EN_LED_PIN, OUTPUT);
  digitalWrite(EN_LED_PIN, HIGH);

  // Knoppen instellen
  pinMode(BUTTON_PIN1, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);
  pinMode(BUTTON_PIN3, INPUT_PULLUP);
  pinMode(BUTTON_PIN4, INPUT_PULLUP);

  // Start met alle LEDs uit
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();

  delay(2000);  // Opstartdelay
}

void displayTime() {
  // Update tijd
  if (millis() - lastUpdateTime >= UPDATE_INTERVAL) {
    seconds += TIME_ACCELERATION;
    while (seconds >= 60) {
      seconds -= 60;
      minutes++;
      if (minutes >= 60) {
        minutes = 0;
        hours++;
        if (hours >= 24) {
          hours = 0;
        }
      }
    }
    lastUpdateTime = millis();
  }

  // Zet alle LEDs uit
  fill_solid(leds, NUM_LEDS, CRGB::Black);

  // Uren: LED 0-11 (rood, 12-uursformaat)
  int displayHour = hours % 12;
  leds[displayHour] = CRGB::Red;

  // Minuten: LED 12-23 (groen, elke 5 minuten)
  int fiveMinutes = minutes / 5;
  if (fiveMinutes < 12) {
    leds[12 + fiveMinutes] = CRGB::Green;
  }
}

void loop() {
  // Lees knopstatus
  int button1State = digitalRead(BUTTON_PIN1);
  int button2State = digitalRead(BUTTON_PIN2);
  int button3State = digitalRead(BUTTON_PIN3);
  int button4State = digitalRead(BUTTON_PIN4);

  // Knoppen verwerken (debouncing)
  if (button1State == LOW && lastButton1State == HIGH) {
    currentPattern = 3;
  }
  if (button2State == LOW && lastButton2State == HIGH) {
    currentPattern = 2;
  }
  if (button3State == LOW && lastButton3State == HIGH) {
    currentPattern = 1;
  }
  if (button4State == LOW && lastButton4State == HIGH) {
    currentPattern = 0;  // Tijdmodus
  }

  // Sla knopstatus op
  lastButton1State = button1State;
  lastButton2State = button2State;
  lastButton3State = button3State;
  lastButton4State = button4State;

  // Selecteer patroon
  switch (currentPattern) {
    case 0:  // Tijdmodus
      displayTime();
      leds[24] = CRGB::Green;

      break;
    case 1:                                     // Patroon 1: Driehoek van groen met rode randen
      fill_solid(leds, NUM_LEDS, CRGB::Black);  // Reset LEDs
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
      leds[24] = CRGB::Black;
      leds[25] = CRGB::Black;
      leds[26] = CRGB::Black;
      leds[27] = CRGB::Green;
      break;
    case 2:  // Patroon 2: Blauwe zigzag met witte accenten
      fill_solid(leds, NUM_LEDS, CRGB::Black);
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
      leds[24] = CRGB::Black;
      leds[25] = CRGB::Green;
      leds[26] = CRGB::Black;
      leds[27] = CRGB::Black;
      break;
    case 3:  // Patroon 3: Gele golf met groene stippen
      fill_solid(leds, NUM_LEDS, CRGB::Black);
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
      leds[24] = CRGB::Black;
      leds[25] = CRGB::Black;
      leds[26] = CRGB::Green;
      leds[27] = CRGB::Black;
      break;
    default:  // Alles uit
      fill_solid(leds, NUM_LEDS, CRGB::Black);
      break;
  }

  // Update LEDs
  FastLED.show();

  // Debounce delay
  delay(100);
}
