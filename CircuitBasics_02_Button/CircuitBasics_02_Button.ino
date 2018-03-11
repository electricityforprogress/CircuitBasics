// Circuit Basics 02 - Digital Read
// Connect a tactile button to positive voltage on one side
// and a 10k resistor to ground on the other in parallel with 
// a connection to the arduino button input pin, this will 
// pull LOW the arduino input and show a HIGH when the button
// is pressed.
//                     5v
//                     |
//                     \ switch
//                     |
//  Digital Input o----|
//                     |
//                    10k
//                     |
//                     GND

byte LED1 = 9; // this pin controls the LED
byte buttonPin = 7; // this pin controls the button

void setup() {
  pinMode(LED1, OUTPUT); // set LED pin for output
  pinMode(buttonPin, INPUT); // set button pin for input

  TXLED1; // turn off onboard leds on pro micro
  RXLED1; // turn off onboard leds on pro micro

}

void loop() {

  byte buttonState = digitalRead(buttonPin); // read from the button
  
  if(buttonState == HIGH) { // if the button is pressed 
    digitalWrite(LED1, HIGH); // turn on the LED
  } else {
    digitalWrite(LED1, LOW);
  }
 

}
