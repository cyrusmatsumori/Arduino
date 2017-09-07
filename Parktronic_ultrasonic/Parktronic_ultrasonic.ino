//ULTRASONIC
#include <Ultrasonic.h>

#define echoPin 13 // Echo Pin
#define trigPin 12 // Trigger Pin
#define LEDPin 13 // Onboard LED
int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance


//DISPLAY
// select pin for cathode 
int a = 1;
int b = 2;
int c = 3;
int d = 4;
int e = 5;
int f = 6;
int g = 7;
int dp = 8;

// select pin for anode 
int d4 = 9;
int d3 = 10;
int d2 = 11;
int d1 = 12;

// set variable 
long n = 1230; 
int x = 100; 
int del = 55; // fine adjustment for clock

void setup()
{
  //ULTRASONIC
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)

  //DISPLAY
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT); 
  pinMode(d3, OUTPUT); 
  pinMode(d4, OUTPUT); 
  pinMode(a, OUTPUT); 
  pinMode(b, OUTPUT); 
  pinMode(c, OUTPUT); 
  pinMode(d, OUTPUT); 
  pinMode(e, OUTPUT); 
  pinMode(f, OUTPUT); 
  pinMode(g, OUTPUT); 
  pinMode(dp, OUTPUT);
}

void WeiXuan(unsigned char n)//
{
  switch(n)
    {
   case 1: 
    digitalWrite(d1,LOW); 
    digitalWrite(d2, HIGH); 
    digitalWrite(d3, HIGH); 
    digitalWrite(d4, HIGH);
   break; 
   case 2:
    digitalWrite(d1, HIGH);
    digitalWrite(d2, LOW); 
    digitalWrite(d3, HIGH); 
    digitalWrite(d4, HIGH);
   break; 
   case 3:
    digitalWrite(d1,HIGH);
    digitalWrite(d2, HIGH);
    digitalWrite(d3, LOW);
    digitalWrite(d4, HIGH);
   break; 
   case 4:
    digitalWrite(d1, HIGH);
    digitalWrite(d2, HIGH);
    digitalWrite(d3, HIGH);
    digitalWrite(d4, LOW);
   break;
   default :
    digitalWrite(d1, HIGH);
    digitalWrite(d2, HIGH);
    digitalWrite(d3, HIGH);
    digitalWrite(d4, HIGH);
   break;
   }
}
void Num_0()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
  digitalWrite(dp,LOW);
}
void Num_1()
{
  digitalWrite(a, LOW); 
  digitalWrite(b, HIGH); 
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp,LOW);
}
void Num_2()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
  digitalWrite(dp,LOW);
}
void Num_3() 
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
  digitalWrite(dp,LOW);
 }
void Num_4() 
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp,LOW);
}
void Num_5() 
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp,LOW);
}
void Num_6() 
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp,LOW);
}
void Num_7() 
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp,LOW); }
void Num_8() 
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp,LOW);
}
void Num_9() 
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(dp,LOW);
}



void Clear()  // clear the screen 
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp,LOW);
}

void pickNumber(unsigned char n)  // select number 
{
  switch(n)
  {
    case 0:Num_0();
    break;
    case 1:Num_1(); 
    break;
    case 2:Num_2(); 
    break;
    case 3:Num_3(); 
    break;
    case 4:Num_4();
    break;
    case 5:Num_5();
    break;
    case 6:Num_6(); 
    break;
    case 7:Num_7();
    break;
    case 8:Num_8();
    break;
    case 9:Num_9(); 
    break;
    default:Clear(); 
    break;
    } 
}

void Display(unsigned char x, unsigned char Number) // take x as coordinate and display number
{
 WeiXuan(x);
 pickNumber(Number);
 delay(1);
 Clear(); // clear the screen
}

void loop()
{
  //ULTRASOUND
  // The following trigPin/echoPin cycle is used to determine the distance of the nearest object by bouncing soundwaves off of it.
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
  //Calculate the distance (in cm) based on the speed of sound. distance = duration/58.2;
  if (distance >= maximumRange || distance <= minimumRange) /* Send a negative number to computer and Turn LED ON to indicate "out of range" */
  {
    Serial.println("-1");
    digitalWrite(LEDPin, HIGH);
  }
  else /* Send the distance to the computer using Serial protocol, and turn LED OFF to indicate successful reading. */ 
  {
    Serial.println(distance);
    digitalWrite(LEDPin, LOW); 
  }
delay(50); //Delay 50ms before next reading.

  Display(1, 0); 
  Display(2, 234/100);
  Display(3, 0);
  Display(4, 9);

}
