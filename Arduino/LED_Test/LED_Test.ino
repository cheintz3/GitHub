int topLeft = 3;
int topRight = 5;
int top = 4;
int bottom = 9;
int bottomLeft = 7;
int bottomRight = 6;
int middle = 2;
int dot = 8;
int sensor = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(topLeft, OUTPUT);
  pinMode(topRight, OUTPUT);
  pinMode(top, OUTPUT);
  pinMode(bottom, OUTPUT);
  pinMode(bottomLeft, OUTPUT);
  pinMode(bottomRight,OUTPUT);
  pinMode(middle, OUTPUT);
  pinMode(dot, OUTPUT);
  Serial.begin(115200);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(sensor);
  double tempCelsius = ((double)sensorValue * 5 / 1024 - 0.5) * 100;
  int temp = tempCelsius * 1;
  Serial.println(temp);
  if (temp / 10 == 1){
    digitalWrite(dot, LOW);
    digitalWrite(middle, LOW);
    digitalWrite(topLeft, LOW);
    digitalWrite(top, LOW);
    digitalWrite(bottom, LOW);
    digitalWrite(bottomLeft, LOW);
    digitalWrite(bottomRight, HIGH);
    digitalWrite(topRight, HIGH);
  }
  else if (temp / 10 == 2){
    digitalWrite(dot, LOW);
    digitalWrite(middle, LOW);
    digitalWrite(topLeft, LOW);
    digitalWrite(top, LOW);
    digitalWrite(bottom, LOW);
    digitalWrite(bottomLeft, LOW);
    digitalWrite(top, HIGH);
    digitalWrite(topRight, HIGH);
    digitalWrite(middle, HIGH);
    digitalWrite(bottomLeft, HIGH);
    digitalWrite(bottom, HIGH);
  }
  delay(1000);
}
