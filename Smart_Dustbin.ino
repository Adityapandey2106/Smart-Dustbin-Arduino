#include<Servo.h>
Servo myservo;
int trigPin= 5; 
int echoPin=6;
long duration, cm, inches; 
void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(0);
pinMode(trigPin,OUTPUT);
pinMode(echoPin, INPUT);
}
void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
//store the time in variable duration
duration=pulseIn(echoPin, HIGH);
cm = (duration/2) / 29.1;
Serial.print("cm:");
Serial.println(cm);
if(cm<20 && cm!=0)
{
  myservo.write(150);
delay(400);
}
else
{
  myservo.write(0);
}
}
