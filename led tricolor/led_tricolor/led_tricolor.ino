#include <TimerOne.h>
#include "Arduino.h"
#define M1A 3
#define M1B 5
#define M2A 6
#define M2A 9
#define red 3
#define vcc 5
#define green 6
#define blue 9

static long int a,b,c,x,y,z,i,j,k,on,off;

void setup() 
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
 
}

/////////////////////////////////////////////////////
void loop()
{
  i++;
blk(50,2);             // wait for a second
}
///////////////////////////////////////////////
void blk(int pwm,int f) 
{
  on=10*pwm/f;
  off=(1000/f)-on;
 if(milli()%on==0)  {digitalWrite(13,!digitalRead(13)); }
 if(milli()%off==0)  {digitalWrite(13,!digitalRead(13)); }
  
}
/////////////////////////////////////////////////////////
/*
void light(int x,int y)
{
  if(i%100)  {digitalWrite(13,!digitalRead(13)); }
}
//////////////////////////////////////////////////////////
void rgb(int r,int g,int b)
{
  if(i%100)  {digitalWrite(13,!digitalRead(13)); } 
}
*/
