#include <FastLED.h>  //Bibliotheek om leds aan te sturen

#define LED_PIN A2        // datapin PA2
#define NUM_LEDS 28       //aantal leds
#define EN_LED_PIN A1     // enable pin PA1
#define BRIGHTNESS 12     // hoe hard de leds kunnen branden. Ik verkies een laag getal anders verblinden de leds.
#define LED_TYPE WS2812B  // type led dat je gebruikt
#define COLOR_ORDER GRB
#define BUTTON_PIN1 A3  // knop1 in op PA3
#define BUTTON_PIN2 A4  // knop2 in op PA4
#define BUTTON_PIN3 A5  // knop3 in op PA5
#define BUTTON_PIN4 A6  // knop4 in op PA6

CRGB leds[NUM_LEDS];

//vorige toestand onthouden van de knoppen.
int lastButton1State = HIGH;
int lastButton2State = HIGH;
int lastButton3State = HIGH;
int lastButton4State = HIGH;

// Zal onthouden welk patroon van leds zal gebruikt worden
int currentPattern = 0;

void setup() {
  //instialiseren led-strips
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  // stroom led strip aanzetten
  pinMode(EN_LED_PIN, OUTPUT);
  digitalWrite(EN_LED_PIN, HIGH);
  //knoppen instellen
  pinMode(BUTTON_PIN1, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);
  pinMode(BUTTON_PIN3, INPUT_PULLUP);
  pinMode(BUTTON_PIN4, INPUT_PULLUP);
  //we zetten een delay om de opstart de tijd te geven.
  delay(2000);
  // Starten met alle leds uit
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
}

void loop() {
  // Lees de huidige status van elke knop
  int button1State = digitalRead(BUTTON_PIN1);
  int button2State = digitalRead(BUTTON_PIN2);
  int button3State = digitalRead(BUTTON_PIN3);
  int button4State = digitalRead(BUTTON_PIN4);



  switch (currentPattern) {
    case 1:  // Patroon 1: Driehoek van groen met rode randen (Knop 1)
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
      leds[24] = CRGB::Green;
      leds[25] = CRGB::Black;
      leds[26] = CRGB::Black;
      leds[27] = CRGB::Black;
      break;
    case 2:  // Patroon 2: Blauwe zigzag met witte accenten (Knop 2)
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
    case 3:  // Patroon 3: Gele golf met groene stippen (Knop 3)
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
    case 4:  // Patroon 4: Paarse diagonaal met oranje uiteinden (Knop 4)
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
      leds[24] = CRGB::Black;
      leds[25] = CRGB::Black;
      leds[26] = CRGB::Black;
      leds[27] = CRGB::Green;
      break;
    default:  // alles uit bij default
      fill_solid(leds, NUM_LEDS, CRGB::Black);
      break;
  }

  // debouncing zodat de knop enkel zal reager wanneer hij echt is ingedrukt
  if (button3State == LOW && lastButton3State == HIGH) {
    currentPattern = 1;
  }
  if (button2State == LOW && lastButton2State == HIGH) {
    currentPattern = 2;
  }
  if (button1State == LOW && lastButton1State == HIGH) {
    currentPattern = 3;
  }
  if (button4State == LOW && lastButton4State == HIGH) {
    currentPattern = 4;
  }

  // Sla huidige knopstatussen op voor volgende loop
  lastButton1State = button1State;
  lastButton2State = button2State;
  lastButton3State = button3State;
  lastButton4State = button4State;
  // Update de LEDs met nieuwe kleuren
  FastLED.show();
  //korte delay voor debounce en stabilistatie van de leds
  delay(100);  // Debounce delay
}
