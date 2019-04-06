#include <SD.h>

#define CS_PIN  D8



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    if (!SD.begin(CS_PIN)) {
      Serial.println("failed");
    }
    Serial.println("success");
  SD.open("make_it", FILE_WRITE);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("i like my self believe");
  delay(10000000);
}
