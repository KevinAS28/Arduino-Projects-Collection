
#include <Servo.h>
Servo yay0;
Servo yay1;

int port = 3;
void setup() {
  // put your setup code here, to run once:
  yay0.attach(3);
  pinMode(port, OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  int angka = analogRead(port);
  angka = map(angka, 0, 1023, 0, 180);
  yay0.write(angka);
  delay(100);
}
