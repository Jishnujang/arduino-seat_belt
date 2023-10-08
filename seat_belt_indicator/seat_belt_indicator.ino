


#define kpa2atm 0.00986923267


// pin defs
int pressurePin = 0;

// variables
int val;
float pkPa; // pressure in kPa
float pAtm; // pressure in Atm

unsigned long time;


void setup()
{
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  pinMode(8, INPUT);
 
}

void loop()
{
  
  /* get the pressure */
  val = analogRead(pressurePin);
  pkPa = ((float)val/(float)1023+0.095)/0.009;
  pAtm = kpa2atm*pkPa;
  
 
  /* send pressure to serial port */

 
    if(digitalRead(8) == 0)
    {
      
          if(pkPa > 110)
          {
              digitalWrite(2,LOW);
              Serial.println("Seat belt detected");
          }
          else
          {
              Serial.println("seat belt without Human");
              digitalWrite(2,HIGH);
              delay(750);
              digitalWrite(2,LOW);
          }
    
    }
    
  
  else
  {
          Serial.println("seat belt not used");
          digitalWrite(2,HIGH);
          delay(750);
          digitalWrite(2,LOW);
  }
  delay(1000);
}