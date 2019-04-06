int output[] = {2, 4, 7, 8};
int input[1] = {A5};
void setup()
{
  
  for (int i: output)
  {
    pinMode(i, OUTPUT);
  }
  for (int i: (::input))
  {
    pinMode(i, INPUT);
  }
  Serial.begin(9600);
  
  
}
void printdig(int x)
{
  
}
void setLampu(int x[])
{
  int lampu0 = 2, lampu1 = 4, lampu2 = 7;
  digitalWrite(lampu0, x[0]);
  digitalWrite(lampu1, x[1]);
  digitalWrite(lampu2, x[2]);  
  
}
void loop()
{
  int cahaya = analogRead(A5);
  int kondisi[] = {(cahaya > 50) & (cahaya < 300), (cahaya >= 300) & (cahaya < 700), cahaya > 700};
  int kondisi1[][3] = {{0, 0, 1}, {0, 1, 1}, {1, 1, 1}};
  Serial.println(cahaya);
  for (int i = 0; i < sizeof(kondisi)/sizeof(kondisi[0]); i++)
  {
    if (kondisi[i])
    {
      ::setLampu(kondisi1[i]);
      return;
    }
  }
  int lainnya[] = {0,0,0};
  ::setLampu(lainnya);
  
  
  
}

