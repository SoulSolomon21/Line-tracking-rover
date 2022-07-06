#include <Servo.h>

#define echoPin 6
#define trigPin 5
Servo servo1;
Servo servo2;
int irsensorfront=2;
int irsensorleft=3;
int irsensorright=4;
long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
Serial.begin(9600);  // Serial Communication is starting with 9600 of baudrate speed
servo1.attach(8);
servo2.attach(9);
pinMode(irsensorfront ,INPUT);
pinMode(irsensorleft ,INPUT);
pinMode(irsensorright ,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
if (digitalRead(irsensorfront)==LOW){
servo1.write(60);  //makes the rover turn in a circle so as to look for the path again
servo2.write(60);

if(distance < 10){
  servo1.write(0); //makes the rover move in a continuous straight line
  servo2.write(180);
}

}else{
servo1.write(180); //makes the rover move in a continuous straight line
servo2.write(0);
} 

if (digitalRead(irsensorleft)==LOW){
servo1.write(60);  //makes the rover turn in a circle so as to look for the path again
servo2.write(60);
}

if (digitalRead(irsensorright)==LOW){
servo1.write(60);  //makes the rover turn in a circle so as to look for the path again
servo2.write(60);
}

}