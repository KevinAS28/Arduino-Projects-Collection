int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int pot=A0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pot, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

}
int activated;
void active(int led)
{
    digitalWrite(activated, LOW);
    activated = led;
    digitalWrite(led, HIGH);
  
}
void loop() {
  //Serial.println(analogRead(pot));
  int angka = analogRead(pot);
  const int jmlh_led = 4;
  int led_list[jmlh_led] = {led1, led2, led3, led4};
  int rules[jmlh_led] = {((angka > 0) & (angka < 250)),
                         ((angka >= 250) & (angka < 500)),
                         ((angka >= 500) & (angka < 750)),
                         ((angka >= 750) & (angka < 1024))};
  for (int i = 0; i < jmlh_led; i++)
  {
    if (rules[i])
    {
      active(led_list[i]); 
    }
  }
  /*
  if ((angka > 0) & (angka < 250))
  {
    active(led1);
  }
    if ((angka >=250) & (angka < 500))
  {
    active(led2);
  }
      if ((angka >=500) & (angka < 750))
  {
    active(led3);
  }
      if ((angka >= 750) & (angka <= 1023))
  {
    active(led4);
  }
  */
  //delay(100);
}
