//Juego de Simon Dice

//Declaracion de pines y variables

const int BotonAM=2;
const int BotonV=7;
const int BotonR=8;
const int BotonAZ=9;
const int LEDR=3;
const int LEDAZ=4;
const int LEDV=5;
const int LEDAM=6;
int cont=1;
int valorBotonAM;
int valorBotonV;
int valorBotonR;
int valorBotonAZ;
int randNumber;
int i,k;
int j=0;
int VCPU[10];
int VPLAYER[10];
int valorRESP_AZ;
int valorRESP_AM;
int valorRESP_R;
int valorRESP_V;
int FIN=1;
int aux=0;
int N=4;
int t=1000;
int RED=A1;
int GREEN=10;

//Para el 7 segmentos

byte seven_seg_digits[10] = { B11111100,  // = 0
                              B01100000,  // = 1
                              B11011010,  // = 2
                              B11110010,  // = 3
                              B01100110,  // = 4
                              B10110110,  // = 5
                              B10111110,  // = 6
                              B11100000,  // = 7
                              B11111110,  // = 8
                              B11100110   // = 9
                             };
int latchPin = 12;    //3
int clockPin = 11;  //4
int dataPin = 13;  //2
 


void setup() {
  // put your setup code here, to run once:
pinMode(LEDR,OUTPUT);
pinMode(LEDAZ,OUTPUT);
pinMode(LEDAM,OUTPUT);
pinMode(LEDV,OUTPUT);
pinMode(BotonAM,INPUT);
pinMode(BotonV,INPUT);
pinMode(BotonR,INPUT);
pinMode(BotonAZ,INPUT);
pinMode(latchPin, OUTPUT);
pinMode(clockPin, OUTPUT);
pinMode(dataPin, OUTPUT);
pinMode(RED,OUTPUT);
pinMode(GREEN,OUTPUT);
Serial.begin(9600);
}
 
void sevenSegWrite(byte digit) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, seven_seg_digits[digit]);  
  digitalWrite(latchPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
sevenSegWrite(N-3);
while(aux<1)
{
valorBotonAM=digitalRead(BotonAM);
valorBotonV=digitalRead(BotonV);
valorBotonR=digitalRead(BotonR);
valorBotonAZ=digitalRead(BotonAZ);
//Serial.print(valorBotonR);
if(valorBotonAM==HIGH || valorBotonV==HIGH || valorBotonR==HIGH || valorBotonAZ==HIGH)
  {
    cont=cont+1;
    delay(1000);
  }
if(cont%2==1)
  {
  digitalWrite(LEDR,LOW);
  digitalWrite(LEDAZ,LOW);
  digitalWrite(LEDV,LOW);
  digitalWrite(LEDAM,LOW);
  }
if(cont%2==0)
 {
    for(i=0;i<N;i++)
    {
      randNumber=random(1,5);
  if(randNumber==1)
    {
      digitalWrite(LEDR,HIGH);
      delay(t);
      digitalWrite(LEDR,LOW);
      delay(t);
    }
  else if(randNumber==2)
    {
      digitalWrite(LEDAM,HIGH);
      delay(t);
      digitalWrite(LEDAM,LOW);
      delay(t);
    }
  else if(randNumber==3)
    {
      digitalWrite(LEDV,HIGH);
      delay(t);
      digitalWrite(LEDV,LOW);
      delay(t);
    }
    
  else if(randNumber==4)
    {
      digitalWrite(LEDAZ,HIGH);
      delay(t);
      digitalWrite(LEDAZ,LOW);
      delay(t);
    }
    VCPU[i]=randNumber;
    Serial.print(VCPU[i]);
    }
    cont++;
    aux++;
    i=0;
 }
 
}
aux=0;

 //Implementamos la respuesta
while(j<N)
{
valorRESP_AM=digitalRead(BotonAM);
valorRESP_V=digitalRead(BotonV);
valorRESP_R=digitalRead(BotonR);
valorRESP_AZ=digitalRead(BotonAZ);
if(valorRESP_AM==HIGH)
{
  digitalWrite(LEDAM,HIGH);
  delay(t);
  digitalWrite(LEDAM,LOW);
  VPLAYER[j]=2;
  delay(t);
  j++;  
} 
if(valorRESP_AZ==HIGH)
{
  digitalWrite(LEDAZ,HIGH);
  delay(t);
  digitalWrite(LEDAZ,LOW);
  VPLAYER[j]=4;
  delay(t);
  j++;  
} 
if(valorRESP_V==HIGH)
{
  digitalWrite(LEDV,HIGH);
  delay(t);
  digitalWrite(LEDV,LOW);
  VPLAYER[j]=3;
  delay(t);
  j++;  
} 
if(valorRESP_R==HIGH)
{
  digitalWrite(LEDR,HIGH);
  delay(t);
  digitalWrite(LEDR,LOW);
  VPLAYER[j]=1;
  delay(t);
  j++;  
} 
}
j=0;

for(k=0;k<N;k++)
{
  Serial.print(VCPU[k]);
  Serial.print(VPLAYER[k]);
  if(VCPU[k] != VPLAYER[k])
    FIN=0;
  
}
k=0;
Serial.print(FIN);
if(FIN==1)
{
  //LED_FIN=1;
  t=t/1.1;
  N++;
  digitalWrite(GREEN,HIGH);
  delay(2000);
  digitalWrite(GREEN,LOW);
}
else if(FIN==0)
 {
  N=4; 
  digitalWrite(RED,HIGH);
  delay(2000);
  digitalWrite(RED,LOW);
  }
 
}



//Progress_Update --->  Siguiente paso --> Implementar animación de WIN.

