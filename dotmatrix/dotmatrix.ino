#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

int pinCS = 10; // Attach CS to this pin, DIN to MOSI and CLK to SCK 
int numberOfHorizontalDisplays = 1;
int numberOfVerticalDisplays = 4;


//SCK = 13
//MISO = 12
//MOSI = 11
//SS = 10
Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

String tape = "Kevin PKK";
int wait = 250; // In milliseconds

int spacer = 1;
int width = 5 + spacer; // The font width is 5 pixels

void setup() {

  matrix.setIntensity(0.5); // Use a value between 0 and 15 for brightness

// Adjust to your own needs
//  matrix.setPosition(0, 0, 0); // The first display is at <0, 0>
//  matrix.setPosition(1, 1, 0); // The second display is at <1, 0>
//  matrix.setPosition(2, 2, 0); // The third display is at <2, 0>
//  matrix.setPosition(3, 3, 0); // And the last display is at <3, 0>
//  ...
//  matrix.setRotation(0, 2);    // The first display is position upside down
 matrix.setRotation(3);    // The same hold for the last display
//return;
 matrix.fillScreen(LOW);
 String kevin = "Kevin";
 for (int i =0;i< kevin.length();i++)
 {
    
    int y = (matrix.height() - 8) / 2; // center the text vertically
 matrix.drawChar((6*i)+1, y, kevin[i], HIGH, LOW, 1);
 }
 matrix.write(); // Send bitmap to display
}

void loop() {

return;
  for ( int i = 0 ;
  i < width * tape.length() + matrix.width() - 1 - spacer; //i < (abjad length) * (sentence count) + (width screen) - (1) - (space between abjad)
  i++ ) {

    matrix.fillScreen(LOW);

    int letter = i / width;
    int x = (matrix.width() - 1) - i % width;
    int y = (matrix.height() - 8) / 2; // center the text vertically

    while ( x + width - spacer >= 0 && letter >= 0 ) {
      if ( letter < tape.length() ) {
        matrix.drawChar(x, y, tape[letter], HIGH, LOW, 1);
      }

      letter--;
      x -= width;
    }

    matrix.write(); // Send bitmap to display

    delay(wait);
  }

}
