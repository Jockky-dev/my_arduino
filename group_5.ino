#include <Servo.h>
#define trigPin 9
#define echoPin 8
Servo servo;

void setup() 
{
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
servo.attach(6);
}

void loop() 
{
  
long duration, distance;
  
digitalWrite(trigPin, LOW);
delay(500);
digitalWrite(trigPin, HIGH);
delay(500);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1; 
  
if (distance > 70) {

Serial.print(distance);
Serial.println(" cm");
servo.write(90);
}

else if (distance<120) {
Serial.print(distance);
Serial.println(" cm"); //we use "cm" for demo purpose only
  servo.write(0);
  }

else {
Serial.println("The distance is more than 180cm");
  }
delay(500);
}
