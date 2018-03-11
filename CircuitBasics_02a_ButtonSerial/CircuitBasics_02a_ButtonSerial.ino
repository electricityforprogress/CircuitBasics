// Circuit Basics 02 - Digital Read
// Connect a tactile button to positive voltage on one side
// and a 10k resistor to ground on the other in parallel with 
// a connection to the arduino button input pin, this will 
// pull LOW the arduino input and show a HIGH when the button
// is pressed.
//                  5v
//                  |
//                  \ switch
//                  |
//       Input o----|
//                  |
//                  10k
//                  |
//                  GND

byte LED1 = 9; // this pin controls the LED
byte buttonPin = 7; // this pin controls the button

int toggles = 0; // counts button bounce toggles
bool buttonPrevState = LOW; // current button state tracker

void setup() {
  Serial.begin(9600); // start serial for debugging
  
  pinMode(LED1, OUTPUT); // set LED pin for output
  pinMode(buttonPin, INPUT); // set button pin for input

  TXLED1; // turn off onboard leds on pro micro
  RXLED1; // turn off onboard leds on pro micro

}

void loop() {

  bool buttonState = digitalRead(buttonPin); // read from the button
  
  if(buttonState == HIGH) { // if the button is pressed 
    if(buttonState != buttonPrevState) { // did the state just change?
      toggles++; // increment the toggles count
    }
    
    digitalWrite(LED1, HIGH); // turn on the LED
  } else {
    if(buttonState != buttonPrevState) { // did the state just change?
      toggles++; // increment the toggles count
    }
    
    digitalWrite(LED1, LOW);
  }

  Serial.print(toggles); Serial.print(","); //high toggles count shows switch bouncing
  Serial.println(buttonState); // output button value to console and plotter
 

}
