/*TEA5767_Encoder_Serial
Written By: Kanad Nemade
Github: Arduino3128
Simple FM Radio using TEA5767 and Rotary Encoder.(Serial Output)
Wiring:
TEA5767------------------>Arduino

SDA-------------SDA
SCL-------------SCL
VCC-------------3.3V
GND-------------GND
10K Pull-Up Resistors between SDA to 3.3V and SCl to 3.3V.
Rotary Encoder ---------->Arduino

+----------------5V
GND--------------GND
SW---------------10
DT---------------9
CLK--------------8
10K Pull-Up Resistor between SW and 5V.
Usage:
1. Use rotary encoder to tune into desired station.
2. Push rotary encoder switch to select the staion.
*/
#include<Wire.h>
const int OA = 9;
const int OB = 8;
bool aLast;
bool bLast;
String str;
float freq;
int freg;
String dat1;
String dat2;
int addr;
int dat3;
int dat4;
float freq2;
String fregstr;
const int OC = 10;
void setup(){
  freq=88.0;
  freq2=0;
  addr=0x60;
  Wire.begin();
  Serial.begin(9600);
  pinMode(OA,INPUT);
  pinMode(OB, INPUT);
  pinMode(OC, INPUT);
  aLast=digitalRead(OA);
}
void loop(){
  bLast=digitalRead(OB);
  if (aLast!=digitalRead(OA)){
    if (bLast!=aLast){
      freq=freq+0.1;
      if (freq>108.0){
        freq=88.0;
      }
      }
    else{
    freq=freq-0.1;
    if (freq<88.0){
        freq=108.0;
      }
    }
  Serial.println("Set Frequency:");
  Serial.println(freq);
  freg=4*(freq*1000000+225000)/32768;
  fregstr=String(freg,BIN);
  dat1=String("00" + fregstr.substring(0,6));
  dat2=String(fregstr.substring(6,14));
  dat3=strtol(dat1.c_str(),NULL,2);
  dat4=strtol(dat2.c_str(),NULL,2);
  
  }
  if (digitalRead(OC)==LOW and freq2!=freq){
  Wire.beginTransmission(addr);
  Wire.write(dat3);
  Wire.write(dat4);
  Wire.write(0x10);
  Wire.write(0x10);
  Wire.write(0x40);
  Wire.endTransmission(); 
  Serial.println("Radio Playing at: ");
  Serial.println(freq);
  freq2=freq;
  }
  
  aLast=digitalRead(OA);
}
