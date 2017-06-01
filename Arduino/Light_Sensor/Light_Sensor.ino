int sensor = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(sensor);
  Serial.println(sensorValue);
  delay(1000);
  
}
