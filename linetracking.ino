#include <Servo.h>

Servo servo1;
Servo servo2;
int irsensor=5;

void setup() {
  // put your setup code here, to run once:
servo1.attach(8);
servo2.attach(9);
pinMode(irsensor,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead(irsensor)==LOW){
servo1.write(60);  //makes the rover turn in a circle so as to look for the path again
servo2.write(60);
// delay(1000);
// servo1.write(360);
// servo2.write(180);
}else{
servo1.write(180); //makes the rover move in a continuous straight line
servo2.write(0);
}
}
