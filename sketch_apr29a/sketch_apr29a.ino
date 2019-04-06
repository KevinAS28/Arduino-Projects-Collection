int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600);

}
  char a;
  int activated = led1;
void loop() {
  // put your main code here, to run repeatedly:
  a =  Serial.read();
  if (Serial.available()>0)
  {
    Serial.println(a);
    delay(100);
  }

  if (a=='1')
  {
    digitalWrite(activated, LOW);
    digitalWrite(led1, HIGH);
    activated = led1;
    Serial.println("lampu 1");
    delay(1000);
    
  }  if (a=='2')
  {
    digitalWrite(activated, LOW);
    digitalWrite(led2, HIGH);
    activated = led2;
    Serial.println("lampu 2");
    delay(1000);
    
  }
    if (a=='3')
  {
    digitalWrite(activated, LOW);
    digitalWrite(led3, HIGH);
    activated = led3;
    Serial.println("lampu 3");
    delay(1000);
  }
    if (a=='4')
  {
    digitalWrite(activated, LOW);
    digitalWrite(led4, HIGH);
    Serial.println("lampu 4");
    activated = led4;
    
  }

}
