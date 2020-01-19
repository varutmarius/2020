
#include <TimerOne.h>

//TimerOne.attachInterrupt(blk());
// the setup function runs once when you press reset or power the board


static long int i,j=0,k,x,y,z,val,val1,val2,val3, wifi,levelup=5,leveldw;
byte  wifistring[801],wifistring1[11];

unsigned char Command[80];
unsigned int it = 0;
void setup() {
 Serial.begin(115200);
  pinMode(13, OUTPUT);
  pinMode(A7, INPUT);
  //pinMode(A7,INPUT_PULLUP);
//  ADMUX.REFS1=1;
  //ADMUX.REFS2=1;
   ADMUX = 0b11000000;
}

// the loop function runs over and over again forever
void loop() 
{
  z++;
// manchester();
// adcserial();   //merge ok 
   readwifi();
 if(z==20){z=6;}
}
//////////////////////////////////////////////////////
void manchester(){
 for (i=0;i<=200;i++)
    {
       if(i%2==1){val1=analogRead(A7);}
      else{val2=analogRead(A7);} 

       if (val1>=500){val1=1;}
      else{val1=0;}
      
      if (val2>=500){val2=1;}
      else{val2=0;}
      
      
           if(val1==0 && val2==0){val=0;}
      else if(val1==0 && val2==1){val=5;}
      else if(val1==1 && val2==0){val=5;}
      else if(val1==1 && val2==1){val=0;}
      else{}
      delayMicroseconds(250);
      wifistring[i]=val;

     }
/////triere valori ca sa se puna pe bus doar trei frame-uri ///////////////////////////////////////////
    for (i=0;i<=200;i++)
        {
         
        if( i>=10 && x==0 && wifistring[i]==1 && wifistring[i-1]==0 && wifistring[i-2]==0 && wifistring[i-3]==0 && wifistring[i-4]==0 && wifistring[i-5]==0 && wifistring[i-6]==0 && wifistring[i-7]==0 && wifistring[i-8]==0 && wifistring[i-9]==0 && wifistring[i-10]==0)
               {j=i; x=1;}
        }
//////////////////////////////////////////////////

Serial.println(20);
    for (i=j;i<=200;i++)
        {
          Serial.println(wifistring[i]);
          x=0;
        }
  //  Serial.println(k);
    delay(1000);
    
}
/////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
void adcserial()
{

///////// inregistreaza un mesaj de la capat, practic se uita cand linia e in zero mai mult de 10 ms
  for (i=0;i<=200;i++)
    {
      val=analogRead(A7);
      delayMicroseconds(100);
      
      if(val<=500){val=0;}
      else{val=5;}
      wifistring[i]=val;
      
      if(i>>10 && x==0 && wifistring[i]==0 && wifistring[i-1]==0 && wifistring[i-2]==0 && wifistring[i-3]==0 && wifistring[i-4]==0 && wifistring[i-5]==0 )
       {i=0;x=1;}
    }
    
  
        for (i=0;i<=200;i++)
          {
            Serial.println(wifistring[i]);
          }
          x=0;
    delay(1000);
}
/////////////////////////////////////////////////////////////

unsigned char zeros;
unsigned int sof = 0;
unsigned int eof = 0;
void readwifi() {

  sof = 0;
  eof = 0;
 for(j = 0; j < 80; j++)
  {
    Command[it] =0;
  }
///////// inregistreaza un mesaj de la capat, practic se uita cand linia e in zero mai mult de 10 ms
  for (i=0;i<=800;i++)
    {
      val=analogRead(A7);
      delayMicroseconds(100);
      
      if(val<=500){val=0;}
      else{val=1;}
      wifistring[i]=val;
    }

    zeros = 0;
    for(i = 0; i < 789; i++)
    {

       if( i>=10 && x==0 && wifistring[i]==1 && wifistring[i-1]==0 && wifistring[i-2]==0 && wifistring[i-3]==0 && wifistring[i-4]==0 && wifistring[i-5]==0 && wifistring[i-6]==0 && wifistring[i-7]==0 && wifistring[i-8]==0 && wifistring[i-9]==0 && wifistring[i-10]==0)
               {sof=i; x=1;}

       if( i>=10 && x==1 && wifistring[i]==1 && wifistring[i+1]==0 && wifistring[i+2]==0 && wifistring[i+3]==0 && wifistring[i+4]==0 && wifistring[i+5]==0 && wifistring[i+6]==0 && wifistring[i+7]==0 && wifistring[i+8]==0 && wifistring[i+9]==0 && wifistring[i+10]==0)
               {eof=i; x=2;}

 /*
      if( (wifistring[i] == 0) && (wifistring[i+1] == 0) ) 
      {
         zeros++; 
      }
      else
      {
        //Serial.println(zeros);
        //delay(50);
        zeros = 0;
      }
      if(zeros == 20)
      {
        sof = i;
        break;
      }
      */
    }
    it = 0;
//Serial.println((eof - sof) /5);
    for(i = sof; i< eof; i+=8)
    {

      for(j = 0; j < 8; j++)
      {
        Command[it] |= wifistring[i+j] << (7-j);
      }

      it++;
    }

  if( ((eof - sof) /5) == 34)
  { 
    for(i = 0; i < it; i++)
    {
      Serial.print(Command[i],HEX);
     }
      Serial.println();
      Serial.println();
  }
  x = 0;
}
//////////////////////////////////////////////////////////////
void blk() {
//if(TimerOne==1000)  {digitalWrite(13,!digitalRead(13) ); 
}
