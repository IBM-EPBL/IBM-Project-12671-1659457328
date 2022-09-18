#include <LiquidCrystal.h>
int trigPin = 10;
int echoPin = 13;
int redledpin = 7;
int greenledpin = 8;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() 
{
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redledpin, OUTPUT);
  pinMode(greenledpin,OUTPUT);
}

void loop()
{
  float time, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(5);
  
  digitalWrite(redledpin,LOW);
  digitalWrite(greenledpin,LOW);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  //distance in cm = (microseconds/2)/29
  //speed of sound = 340m/s 
  time = pulseIn(echoPin, HIGH);
  distance = (time / 2) * 0.0344;
  
  if (distance >= 300 || distance <= 2){
    lcd.print("Out of range");
    delay(500);
    digitalWrite(redledpin,HIGH);
     
  }
  else {
    lcd.print("obstacle in ");
    lcd.print(distance);
    lcd.print(" cm");
    digitalWrite(redledpin,LOW);
    digitalWrite(greenledpin,HIGH);
    delay(500);
  }
  delay(500);
  lcd.clear();
}