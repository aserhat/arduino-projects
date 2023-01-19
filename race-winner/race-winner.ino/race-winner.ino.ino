

#include <LedControl.h> // including a library lets you use pre-written code in your project

int sensorPin = 5;
int sensorValue = 0; 
int state = LOW;

int sensorPin2 = 11; // select the input pin for the Soil Moisture Sensor
int sensorValue2 = 0; // variable to store the value coming from the sensor
int state2 = LOW;

const int DIN_PIN = 2; //the pin we connect to the LEDs Digital In (DIN) pin
const int CS_PIN = 3; //the pin we connect to the LEDs Chip Select (CS) pin
const int CLK_PIN = 4; //the pin we connect to the LEDs Clock (CLK) pin

#define VCC5 10
#define GND5 12 
LedControl display = LedControl(DIN_PIN, CLK_PIN, CS_PIN);

void setup() {

  pinMode(VCC5, OUTPUT);
  digitalWrite(VCC5, HIGH);

  pinMode(GND5, OUTPUT);
  digitalWrite(GND5, LOW);

  // set the sensor pin as an input
  pinMode(sensorPin, INPUT);
  pinMode(sensorPin2, INPUT);
  
  // settings for the LED matrix to display properly
  display.shutdown(0, false);
  // Set brightness to a medium value
  display.setIntensity(0, 8);
  // Clear the display
  display.clearDisplay(0);

  // starting the serial monitor so that we can send information there
  Serial.begin(9600);
}

void loop() {
  // change sensorValue to equal what we read from the sensor 
  sensorValue = digitalRead(sensorPin);
  sensorValue2 = digitalRead(sensorPin2);
  //print the value to the seial monitor


  if (sensorValue == HIGH) {           // check if the sensor is HIGH
    if (state == LOW) {
      Serial.println("Sensor 1 Motion detected!"); 
      drawOne();
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      if (state == HIGH){
        Serial.println("Sensor 1 Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }


  if (sensorValue2 == HIGH) {           // check if the sensor is HIGH
    if (state2 == LOW) {
      Serial.println("Sensor 2 Motion detected!"); 
      drawTwo();
      state2 = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      if (state2 == HIGH){
        Serial.println("Sensor 2 Motion stopped!");
        state2 = LOW;       // update variable state to LOW
    }
  }
 
  delay(5000);
  drawLine();
}

void drawOne(){
  display.setRow(0, 0, B00000000);
  display.setRow(0, 1, B00010000);
  display.setRow(0, 2, B00110000);
  display.setRow(0, 3, B01010000);
  display.setRow(0, 4, B00010000);
  display.setRow(0, 5, B00010000);
  display.setRow(0, 6, B01111100);
  display.setRow(0, 7, B00000000);
}
void drawTwo(){
  display.setRow(0, 0, B00000000);
  display.setRow(0, 1, B00011100);
  display.setRow(0, 2, B00100100);
  display.setRow(0, 3, B00001000);
  display.setRow(0, 4, B00010000);
  display.setRow(0, 5, B00100000);
  display.setRow(0, 6, B01111100);
  display.setRow(0, 7, B00000000);
}

void drawLine(){
  display.setRow(0, 0, B00000000);
  display.setRow(0, 1, B00000000);
  display.setRow(0, 2, B00000000);
  display.setRow(0, 3, B11111111);
  display.setRow(0, 4, B11111111);
  display.setRow(0, 5, B00000000);
  display.setRow(0, 6, B00000000);
  display.setRow(0, 7, B00000000);
}

