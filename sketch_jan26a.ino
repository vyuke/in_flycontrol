#include<Servo.h>;

#define AIL1  22   //AIL fuyi
#define ELE2  24   //ELE shengjiang
#define THR3  26   //THR youmen
#define RUD4  28   //RUD fangxiang
#define LED   13
unsigned long INAIL;
unsigned long INELE;
unsigned long INTHR;
unsigned long INRUD;

int OUTAIL;
int OUTELE;
int OUTTHR;
int OUTRUD;

Servo AIL;
Servo ELE;
Servo THR;
Servo RUD;

void setup()
{  
  pinMode(AIL1,0);
  pinMode(ELE2,0);
  pinMode(THR3,0);
  pinMode(RUD4,0);
  pinMode(LED,1);
  
  AIL.attach(4);
  ELE.attach(5);
  THR.attach(6);
  RUD.attach(7);
  
  Serial.begin(9600);
}
void loop()
{ 
  digitalWrite(LED,1);
  INAIL = pulseIn(AIL1, 1);
  INELE = pulseIn(ELE2, 1);
  INTHR = pulseIn(THR3, 1);
  INRUD = pulseIn(RUD4, 1);

  OUTAIL = map(INAIL,1000,2007,47,144);
  OUTELE = map(INELE,1000,2007,47,144);
  OUTTHR = map(INTHR,1000,2007,47,144);
  OUTRUD = map(INRUD,1000,2007,47,144);
  
  AIL.write(OUTAIL); 
  ELE.write(OUTELE); 
  THR.write(OUTTHR); 
  RUD.write(OUTRUD); 
  
 
  Serial.print("AIL=");
  Serial.print(INAIL);
  Serial.print(" ");
  Serial.print(OUTAIL);
  Serial.print(" ELE=");
  Serial.print(INELE);
  Serial.print(" ");
  Serial.print(OUTELE);
  Serial.print(" THR=");
  Serial.print(INTHR);
  Serial.print(" ");
  Serial.print(OUTTHR);
  Serial.print(" RUD=");
  Serial.print(INRUD);
  Serial.print(" ");
  Serial.println(OUTRUD);
 
 
  digitalWrite(LED,0);
  delay(3);
  
}




