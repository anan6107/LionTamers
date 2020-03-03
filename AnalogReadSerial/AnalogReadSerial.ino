char incoming;
char a = 's';


// Serial.print(toyou);
// Serial.write(tome);


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
   delay(600);
   Serial.write (a);
  while (Serial.available() > 0){
    incoming = Serial.read();
    Serial.write(incoming);
//    Serial.print(incoming);
  }
}
