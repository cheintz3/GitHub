#include<Servo.h>

Servo myServo;
int servoPin = 9;
int potPin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  int rotationVal = map(analogRead(potPin), 0, 1023, 0, 180);
  myServo.write(180 - rotationVal);
}
