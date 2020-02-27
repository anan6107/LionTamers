int pin1 = 10;
int pin2 = 9;

void setup()

{
  pinMode(pin1, OUTPUT);   // sets the pin as output
  pinMode(pin2, OUTPUT);
}

// 133,204 FORWARD
// 133, 51 BACKWARD
//51 ,133 LEFT
//219, 133 RIGHT
//133, 133 STOP (janky)
  // left wheel is running, right wheel is ticking forward
//97, 189 FORWARD LEFT
  // right wheel is very fast
//117,56 BACKWARD LEFT
  // right wheel is too slow
//158,188 FORWARD RIGHT
//153/56 BACKWARD LEFT



void loop()

{
//  val = analogRead(analogPin);   // read the input pin
  analogWrite(pin1, 153);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  analogWrite(pin2, 56);

}
