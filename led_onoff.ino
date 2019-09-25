const int pinbutton = 5;
const int led = 4;
const int del = 500; 
 
boolean newpinstate = LOW;
boolean newpinstate2= LOW;
boolean oldpinstate = LOW;
 
boolean ledOn = 0;
boolean ledstatus = LOW;
boolean pinPressed = 0;
 
 
void setup() 
{
  Serial.begin(9600);
  //Serial.println(" ");

  pinMode(pinbutton, INPUT);
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);

}
 
void loop()
{

  //Determining if the pin is pressed 
  newpinstate = digitalRead(pinbutton);      delay(1);
  newpinstate2 = digitalRead(pinbutton);      

  if (newpinstate == newpinstate2)
  {
      if (newpinstate != oldpinstate) 
      {
          if (newpinstate == HIGH)
          {
            pinPressed = 1; 
          } 
          else{pinPressed = 0;}
          oldpinstate = newpinstate;
      }   
  }


  //If pin is pressed, want to turn led on or off 
  if(pinPressed == 1)
  {   
     if (ledOn == 0)  
     {   
         ledOn = 1;  
     } 
     else                            
     { 
        ledOn = 0; 
        digitalWrite(led,LOW);
     }
     pinPressed = 0;
  }
 
  
  if (ledOn == 1)
  {
    digitalWrite(led,HIGH);
    delay(del);
    digitalWrite(led,LOW);
    delay(del);
  }
}
