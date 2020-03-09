#include <Wire.h>
#include "Adafruit_TCS34725.h"

/* Example code for the Adafruit TCS34725 breakout library */

/* Connect SCL    to analog 5
   Connect SDA    to analog 4
   Connect VDD    to 3.3V DC
   Connect GROUND to common ground */
   
/* Initialise with default values (int time = 2.4ms, gain = 1x) */
// Adafruit_TCS34725 tcs = Adafruit_TCS34725();
int ledPin = 13; 
int cluster = 24;
int val = 0;
/* Initialise with specific int time and gain values */
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);

void setup(void) {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); 
  pinMode(cluster, OUTPUT); 
  
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 fou nd ... check your connections");
    while (1);
  }
  
  // Now we're ready to get readings!
}

void loop(void) {
  uint16_t r, g, b, c, colorTemp, lux;
  
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature(r, g, b);
  lux = tcs.calculateLux(r, g, b);
  
//  Serial.print("Color Temp: "); Serial.print(colorTemp, DEC); Serial.print(" K - ");
//  Serial.print("Lux: "); Serial.print(lux, DEC); Serial.print(" - ");
//  Serial.print("R: "); Serial.print(r, DEC); Serial.print("R: "); Serial.print(r); Serial.print(" ");
//  Serial.print("G: "); Serial.print(g, DEC); Serial.print("G: ");Serial.print(g); Serial.print(" ");
//  Serial.print("B: "); Serial.print(b, DEC);  Serial.print("B: ");Serial.print(b); Serial.print(" ");
//  Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");

  float normalized_r = (float)r/(float)c;
  
  float normalized_g = (float)g/(float)c;
  float normalized_b = (float)b/(float)c; 
  Serial.print("NormalzedR: "); Serial.print(normalized_r, DEC); 
  Serial.print("NormalzedG: "); Serial.print(normalized_g, DEC);
  Serial.print("NormalzedB: "); Serial.print(normalized_b, DEC);
  Serial.print(" ");
  //Serial.print("R: "); Serial.print(normalized_r); Serial.print(" ");

  float initial_r_concrete = 0.475134320476773;
  float initial_g_concrete = 0.408362330818229;
  float initial_b_concrete = 0.414381790870876;

  float initial_r_grass = 0.781608135625124;
  float initial_g_grass = 0.634155549167938;
  float initial_b_grass = 0.631544337770956;
  int counter_grass = 0;
  int counter_concrete = 0;

  float distance_to_concrete = sqrt( pow((normalized_r - initial_r_concrete),2)+ pow((normalized_g - initial_g_concrete),2)+ pow((normalized_b- initial_b_concrete),2) );
  float distance_to_grass = sqrt( pow((normalized_r - initial_r_grass),2)+ pow((normalized_g - initial_g_grass),2)+ pow((normalized_b- initial_b_grass),2) );
  Serial.print('\n');
  Serial.print("concrete: "); Serial.print(distance_to_concrete, DEC); Serial.print(" ");
  Serial.print('\n');
  Serial.print("grass "); Serial.print(distance_to_grass, DEC); Serial.print(" "); 
  Serial.print('\n');

  if(distance_to_grass > distance_to_concrete)
  {
    
    if(digitalRead(ledPin)== 1)
    {
      digitalWrite(ledPin,LOW);
    }
    else
    {
      digitalWrite(ledPin, HIGH);
    }
 
    counter_concrete++;
  }
  else
  {
    digitalWrite(ledPin,LOW);
    counter_grass++;
  }
  if(counter_grass+counter_concrete == 5){
    if(counter_grass>counter_concrete){
      digitalWrite(cluster,HIGH); }
    else{
       digitalWrite(cluster,LOW); }
    counter_concrete = 0;
    counter_grass = 0;
    delay(1000);
  }
}
