 int sensorPin = A0;
int buttonPin = 0;
int pushCount = 0;
int buttonState = 0;
int previousState = 0;
int cPin = 2;
int fPin = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
  pinMode(cPin, OUTPUT);
  pinMode(fPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int sensorValue = analogRead(sensorPin);
  double tempCelsius = ((double)sensorValue * 5 / 1024 - 0.5) * 100;
  double tempFahrenheit = tempCelsius * 9 / 5 + 32;

  buttonState = digitalRead(buttonPin);
  if (buttonState != previousState){
    if (buttonState == HIGH){
      pushCount++;
    }
  }
  previousState = buttonState;
  if(pushCount % 2 == 0){
    Serial.print(tempFahrenheit); Serial.println(" degrees fahrenheit");
    digitalWrite(fPin, HIGH);
    digitalWrite(cPin, LOW);
  }
  else{
    Serial.print(tempCelsius); Serial.println(" degrees celsius");
    digitalWrite(fPin, LOW);
    digitalWrite(cPin, HIGH);
  }
}

