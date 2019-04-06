const int additionalPower = A5;
void setup() {
  // put your setup code here, to run once:
  
  pinMode(additionalPower, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(additionalPower, 168);
}
