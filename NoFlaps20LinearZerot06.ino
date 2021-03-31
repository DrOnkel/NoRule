



#define  PRINTCOUNTER 100

#define THRESHOLD  20
#define KPROP  1
#define NORMAL 0
#define OUTPUTMODE 3

byte j;
int CounterPrint ;
int SpeedL, SpeedR;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  Serial.println("No Flaps 20LinearZerot06");
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  pinMode(A7, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A7);
  // print out the value you read:


  if ((sensorValue < 512 - THRESHOLD)  )
  {
    SpeedR = NORMAL + (512 - sensorValue - THRESHOLD) * KPROP  ;
    SpeedL = NORMAL - (512 - sensorValue - THRESHOLD) * KPROP;

  



    if (CounterPrint == 0)
        Serial.print("\t   case 50  \t");




  }

  else if ((sensorValue > 512 + THRESHOLD)  )
  {
    // if (  ( sensorValue - THRESHOLD - 512)*KPROP < 255)

    SpeedR = NORMAL + (512 - sensorValue + THRESHOLD) * KPROP  ;
    SpeedL = NORMAL - (512 - sensorValue + THRESHOLD) * KPROP;



    if (CounterPrint == 0)
      Serial.print("\t   case 69  \t");





  }


  else
  {
    SpeedR = NORMAL   ;
    SpeedL = NORMAL  ;



    if (CounterPrint == 0)
      Serial.print("\t   case 91  \t");

  }

{ // BEGIN of SET MOTOR

  if(SpeedR>255)
  SpeedR=255;

 if(SpeedR<-255)
  SpeedR=-255;



   if(SpeedL>255)
  SpeedL=255;

 if(SpeedL<-255)
  SpeedL=-255;

  if (SpeedR >= 0)
  {
  digitalWrite(4, LOW);
  analogWrite(3, SpeedR);
  }
  else
   {
  digitalWrite(4, HIGH);
  analogWrite(3, 255 + SpeedR);
  }


 if (SpeedL >= 0)
  {
  digitalWrite(6, LOW);
  analogWrite(5, SpeedL );
  }
else
{
  digitalWrite(6, HIGH);
  analogWrite(5, 255 + SpeedL );
  }


  


}  // END of set motor






  if (CounterPrint++ > PRINTCOUNTER)
    CounterPrint = 0;

  if (CounterPrint == 0)
  {
    Serial.println("");
    Serial.print(sensorValue);
    Serial.print(" \t ");
    Serial.print(SpeedR);
    Serial.print(" \t ");
    Serial.print(SpeedL);



  }












  // Serial.println("    ");
}
