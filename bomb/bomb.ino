#include <Arduino.h>
#include <TM1637Display.h>
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
// Module connection pins (Digital Pins)
#define CLK 11
#define DIO 12

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   2000

const uint8_t SEG_DONE[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_C | SEG_E | SEG_G,                           // n
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
  };

TM1637Display display(CLK, DIO);
uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
void setup()
{
     Serial.begin(9600);
  display.setBrightness(0x0f);    
  display.setSegments(data);
}

int i = 0;
void loop()
{
  if (i==4)
  {
     Serial.begin(9600);
  display.setBrightness(0x0f);        
  uint8_t reset[] = { 0x0, 0x0, 0x0, 0x0 };    
  for (int i = 0; i< 4; i++)
  {
    data[i] = reset[i];
  }
    i=0;
    display.setSegments(data);
    //delay(5000);
  }
    char key = keypad.getKey();
  
  if (key){
    //Serial.println(key);
    data[i]=display.encodeDigit(key-48);
    display.setSegments(data);
    i++;
  }
}
