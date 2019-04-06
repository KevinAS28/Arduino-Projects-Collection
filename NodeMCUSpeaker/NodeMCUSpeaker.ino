//NodeMCU ISD1820 
//written by RoboGi

//define pin for Arduino IDE
#define PLAY_E 5 //NodeMCU pin d1
#define REC 2    //NodeMCU pin d4
#define PLAY_L 4 //NodeMCU pin d2

int recordTime ;

void setup() 
{
  //Set all the pin OUTPUT (we must send out a signal to the ISD1820)
  pinMode(REC,OUTPUT);
  pinMode(PLAY_L,OUTPUT);
  pinMode(PLAY_E,OUTPUT);
  Serial.begin(115200); 

}

void loop() 
{
    while (Serial.available() > 0) {
          char C = (char)Serial.read();
          
            if(C =='p' || C =='P'){
            playSignal ();
            break; 
            }
               
            else if(C =='r' || C =='R'){
              record(3000);              
            }
             
            else if(C =='l' || C =='L'){
              playSignal_L (1000); //for example if I have my recording is 3 seconds long with this instruction I will only produce it for a second
            }             
           
     
    }// wihile

    Serial.println("**** R or r = Record ; P or p play****");

  delay(1000);
}
 
void record(int t) //t is the recording time (us)
{
      recordTime =t;
      digitalWrite(REC, HIGH); //For the time that the pin is set to high the module will record a sound (max 10 sec)
      Serial.println("Recording started");
      delay(t);
      digitalWrite(REC, LOW);
      Serial.println("Recording Stopped ");
}

void playSignal ()
{
   digitalWrite(PLAY_E, HIGH); //If the pin is placed high it will play back all the recorded sound (50 us signal is sufficient for the reproduction of the recorded sound)
  delay(50);
  digitalWrite(PLAY_E, LOW);  
    Serial.println("Playbak Started"); 
    if(recordTime == 0)
    {
      delay(recordTime + 5000);
    } 
    else
    {
      delay(recordTime);
    }
  Serial.println("Playbak Ended");
  
}

void playSignal_L (int l) //l is how long the recorded sound has to be produced (in us)
{
     digitalWrite(PLAY_L, HIGH); //For the time that the pin is set to high the module will produce the recorded sound
     Serial.println("Playbak L Started");  
     delay(l);
     digitalWrite(PLAY_L, LOW);
     Serial.println("Playbak L Ended");    
}

