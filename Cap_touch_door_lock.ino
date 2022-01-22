/*
  Arduino Starter Kit example
 Project 13  - Touch Sensor Lamp

 This sketch is written to accompany Project 13 in the
 Arduino Starter Kit

 Parts required:
 1 Megohm resistor
 metal foil or copper mesh
 220 ohm resistor
 LED

 Software required :
 CapacitiveSensor library by Paul Badger
 http://www.arduino.cc/playground/Main/CapacitiveSensor

 Created 18 September 2012
 by Scott Fitzgerald

 http://www.arduino.cc/starterKit

 This example code is part of the public domain
 */

// import the library (must be located in the
// Arduino/libraries directory)
#include <CapacitiveSensor.h>
#include<Servo.h>
CapacitiveSensor c1=CapacitiveSensor(4,2);
CapacitiveSensor c2=CapacitiveSensor(3,5);
Servo ser;


// pin the LED is connected to
const int ledPin = 12;
uint32_t t1,t2,t;
int count=0; //To measure how long the LEDs are on
int cnt=0; // TO lock/ reset
int d;
int m=3,n=3,p=0,q=0;
void setup() {
  
  
  ser.attach(10);
  ser.write(0);
  
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(12,LOW);
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
}

void loop() {
  long s0 = c1.capacitiveSensor(30);
  long s1=c2.capacitiveSensor(30);
  
   
  
  accepto(s0,s1);
  if(p==m&&q==n)
  {ser.write(180);
  Serial.print("HERE"); 
   time3(s0,s1);
    }
    else if(p==5||q==5)
    {ser.write(0);
     p=0;
     q=0;
     digitalWrite(7,HIGH);
     digitalWrite(8,HIGH);
      }
    
    else
    digitalWrite(12,LOW);
 
  
  
  
  
  delay(1000);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
   
  
  
  
  
  
  
}

void codecnt1(long a,long b)
{
  if(a>500&&b<500)
  {p++;
  digitalWrite(7,HIGH);
  }
  delay(100);
  
  
  digitalWrite(7,LOW);
  }

void codecnt2(long a,long b)
  {
  if(b>500&&a<500)
  {q++;
  digitalWrite(8,HIGH);
  }
  delay(100);
  digitalWrite(8,LOW);
      
  }
  
  void accepto(long a,long b)
  {int i,j;
  
  
    
    
    codecnt1(a,b);
    codecnt2(a,b);
     
    
  }
      
    void time3(long a,long b)
    {if(a>=500&&b>=500)
    {digitalWrite(12,HIGH);
      if(count==0)
    {
      t1=millis();
      count=1;
     
      }
      else 
      {t2=millis();
       count=0;
       t=t2-t1;
       t=t/1000;       
                   
       if(t==1)
       {
        cnt++;
       
        }
        if(cnt==3)
        {
          ser.write(0);
          p=0;
          q=0;
          cnt=0;
          }
         
         
        }

    } delay(10);
    digitalWrite(12,LOW);
      }
      
  
    
