// https://www.instructables.com/id/Simple-Arduino-and-HC-SR04-Example/


#define trigPin 13
#define echoPin 12
#define led 11
#define led2 10

void setup() {
  Serial.begin (9600);
  pinMode(echoPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  long duration, distance;
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;


  if (distance < 30) {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  if (distance >= 1 && distance < 30) {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(200);
  
  //  if (distance >= 100 || distance <= 0) {
  //    Serial.println("Out of range");
  //  }

}
