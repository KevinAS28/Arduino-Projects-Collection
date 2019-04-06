#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>
#include <math.h>
int val;
int tempPin = 1;


int pinCS = 10; // Attach CS to this pin, DIN to MOSI and CLK to SCK 
int numberOfHorizontalDisplays = 1;
int numberOfVerticalDisplays = 4;


//SCK = 13
//MISO = 12
//MOSI = 11
//SS = 10
Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

int wait = 250; // In milliseconds

int spacer = 1;
int width = 5 + spacer; // The font width is 5 pixels

void setup() {
  Serial.begin(9600);
  matrix.setIntensity(5); // Use a value between 0 and 15 for brightness
 matrix.setRotation(3);    // The same hold for the last display
}
const int rate = 5;
int i = 0, seconds=3;
float rate_temp[rate];
void loop() {
 if (i==rate)
 {
   rate_temp;
   i= 0;
   float total = 0;
   for (int a =0 ; a < rate; a++)
   {
     total += rate_temp[a];
   }
   total/=rate;
//   float decimal = total-floor(total); //misal 0.95
//   
//   float x = decimal*10; //9.5
//   int y = x; //9
//   float one_decimal = (float)y/10; //0.9
//   Serial.println(decimal);
//   Serial.println(x);
//   Serial.println(y);
//   Serial.println(one_decimal);
//   Serial.println(" ");
//   //total -= decimal;
//   total += one_decimal;
   
   matrix.fillScreen(LOW);
   String celcius = String(total);
   celcius[celcius.length()-1]='C';
   Serial.println(celcius);
   for (int i =0;i< celcius.length();i++)
    {    
    int y = (matrix.height() - 8) / 2; // center the text vertically
    matrix.drawChar((6*i)+1, y, celcius[i], HIGH, LOW, 1);
    }
   matrix.write(); // Send bitmap to display
   return;
 }
  // put your main code here, to run repeatedly:
 
 val = analogRead(tempPin);
 float mv = ( val/1024.0)*5000;
 float cel = mv/10;
 rate_temp[i] = cel;
 delay(3*1000/rate);
 i++;
}
