int latchPin = 7;
int clockPin = 5;
int dataPin = 6;
int latch2 = 13;
int clock2 = 11;
int data2 = 12;
int sensor = 2;

int numArray[10] = {252, 96, 218, 242, 102, 182, 190, 224, 254};

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(latch2, OUTPUT);
  pinMode(clock2, OUTPUT);
  pinMode(data2, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int sensorValue = analogRead(sensor);
  double tempCelsius = ((double)sensorValue * 5 / 1024 - 0.5) * 100;
  Serial.println(tempCelsius);
  int temp = tempCelsius;
  Serial.println(temp);
  int printVal = temp;
  digitalWrite(latchPin,LOW);
  digitalWrite(latch2,LOW);
  shiftOut(dataPin,clockPin,MSBFIRST,numArray[temp/10]);
  shiftOut(data2,clock2,MSBFIRST,numArray[temp%10]);
  digitalWrite(latchPin,HIGH);
  digitalWrite(latch2,HIGH);
  delay(1000);
}
