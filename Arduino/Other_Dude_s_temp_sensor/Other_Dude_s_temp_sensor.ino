int sensorPin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(sensorPin);
  double tempCelsius = ((double)sensorValue * 5 / 1024 - 0.5) * 100;
  Serial.println(tempCelsius);
  delay(1000);
}
