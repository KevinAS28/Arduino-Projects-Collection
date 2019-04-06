
#include <driver/adc.h>
#include <Arduino.h>

#define AUDIO_BUFFER_MAX 800

uint8_t audioBuffer[AUDIO_BUFFER_MAX];
uint8_t transmitBuffer[AUDIO_BUFFER_MAX];
uint32_t bufferPointer = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("kevin is here");
}

void loop() {
  // put your main code here, to run repeatedly:

}
