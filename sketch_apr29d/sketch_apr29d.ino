#include <Servo.h>
Servo yay;
Servo yayy;
Servo yayyy;
int led1 = 4;
int port = A0;
int portt = A1;
int porttt = A2;
void setup() {
  // put your setup code here, to run once:
  yay.attach(3); 
  yayy.attach(5);
  yayyy.attach(6);
  pinMode(port, INPUT);
  pinMode(portt, INPUT);
  pinMode(porttt, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  yay.write(0);
  delay(200);
  yay.write(90);
  delay(200);
  */
 int angka = analogRead(port);
 int angkaa = analogRead(portt);
 int angkaaa = analogRead(porttt);
 angka = map(angka, 0, 1023, 0, 180);
 angkaa = map(angkaa, 0, 1023, 0, 180);
 angkaaa = map(angkaa, 0, 1023, 0, 180);
 yay.write(angka);
 yayy.write(angkaa);
 yayyy.write(angkaaa);
 if (angka>90)
 {
  digitalWrite(led1, HIGH);
 }
 else
 {
  digitalWrite(led1, LOW);
 }
  
}
