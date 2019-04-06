#include "SevSeg.h"
int output[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

int input[] = {A5, A4};


//kevin agusto xrpl2 smkn1 cibinong
//bahasa: c
//waktu pembuatan: 1 hari

int statuss[10];

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < (sizeof(output)/sizeof(output[0])); i++)
  {
    pinMode(output[i], OUTPUT);
    statuss[i] = 0;
  }
  pinMode(A5, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  
}
void tukar(int ke)
{
  int &a = statuss[ke];
  switch(a)
  {
    case 0:
    {
      a = 1;
      break;
    }
    case 1:
    {
      a = 0;
      break;
    }
  }

  
  digitalWrite(output[ke], a);
}


void setLampu(int lampu, int what)
{
  statuss[lampu] = what;
  digitalWrite(output[lampu], what);
}

int sekarang = 0;
void loop() {

  
  // fun part is here :v kevin agusto
  
  int cahaya = analogRead(A5);
  Serial.println(cahaya);
  int kondisi0[] = {
    ((cahaya >= 100) & (cahaya < 150)),
    ((cahaya >= 150) & (cahaya < 250)),
    ((cahaya >= 250) & (cahaya < 350)),
    ((cahaya >= 350) & (cahaya < 450)),
    ((cahaya >= 450) & (cahaya < 550)),
    ((cahaya >= 550) & (cahaya < 650)),
    ((cahaya >= 650) & (cahaya < 750)),
    ((cahaya >= 750) & (cahaya < 850)),
    ((cahaya >= 850) & (cahaya < 900)),
    cahaya >= 900
    
  };
  for (int i = 0; i < (sizeof(kondisi0)/sizeof(kondisi0[0])); i++)
  {
    int benar = kondisi0[i];
    if (benar)
    {
      if (sekarang==i)
      {
        break;
      }
      sekarang = i;
      //shutdown all first
      for (int a = 0; a < (sizeof(output)/sizeof(output[0])); a++)
      {
        setLampu(a, LOW);
      }
              digitalWrite(13, HIGH);
        
        digitalWrite(13, LOW);
        
      for (int b = 0; b <= i; b++)
      {
        setLampu(b, HIGH);
      }
      
    }
  }
}
