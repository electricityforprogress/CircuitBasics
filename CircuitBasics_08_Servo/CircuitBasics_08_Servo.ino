// Circuit Basics 08 - Servo Position Control
// using a potentiometer to position a Servo Motor
//
// Connect the servo wires to Positive voltage, Ground, and a PWM pin
// The Yellow wire is usually the PWM lead, Red VCC, Brown Ground
//
// Connect a potentiometer to an Analog Input, by setting it up
// as a voltage divider.  Connect one end of the pot to ground, 
// the other to positive voltage, and the wiper to an Analog Input.
//
//         100k pot
//    5v---/\/\/\---GND
//            ^
//            |
//        Analog Input

#include <Servo.h> // include the Servo library

byte analogInput = A0; // this is the analog input pin for the potentiometer
int  servoPos = 0; // the current position of the servo
byte servoPin = 9; // this pin controls the servo
byte servoDelay = 10; // slow everything down for the servo to keep up

Servo myServo; // create a Servo object

void setup() {
  Serial.begin(9600); // start serial for debugging

  TXLED1; // turn off onboard leds on pro micro
  RXLED1; // 

  myServo.attach(servoPin); // setup the servo to a PWM pin


  // a trick using adjacent pins for pot voltage divider
  pinMode(15, OUTPUT);
  pinMode(A1, OUTPUT);
  digitalWrite(15, HIGH);
  digitalWrite(A1, LOW);
 // not needed if you are using a pot with jumper wires

}

void loop() {  
  int analogReading = analogRead(analogInput); // read from the potentiometer

  // change the input value to a new range using the map() function
  // map(value, valueMin, valueMax, outMin, outMax);
  int knobPos = map(analogReading, 0, 1023, 0, 180); // servo range is 180 max
  
  // ~~ Serial Plotter as a ranged display with max and min lines ~~
  Serial.print(0); Serial.print(","); Serial.print(1023); Serial.print(",");
  Serial.println(analogReading); // send reading value to Serial console for plotting
  // ~~
  
  myServo.write(knobPos); // move the servo to the new position
  delay(servoDelay); // slow everything down 


//*** sweeping demo for testing
//  for(servoPos = 0; servoPos <= 180; servoPos+= 1) // goes from 0 degrees to 180 degrees 
//  {                                  // in steps of 1 degree 
//    myServo.write(servoPos);              // tell servo to go to position in variable 'pos' 
//    delay(servoDelay);                       // waits 15ms for the servo to reach the position 
//  } 
//  for(servoPos = 180; servoPos>=0; servoPos-=1)     // goes from 180 degrees to 0 degrees 
//  {                                
//    myServo.write(servoPos);              // tell servo to go to position in variable 'pos' 
//    delay(servoDelay);                       // waits 15ms for the servo to reach the position 
//  } 
//***
}
