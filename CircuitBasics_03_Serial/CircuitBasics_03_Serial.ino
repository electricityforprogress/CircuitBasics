// Circuit Basics 03 - Serial
// Show a message on the Serial console using Serial.print() 
// functions, this allows debuging and displays the value of 
// variables.  Also checkout the Serial Plotter which draws lines!
//
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

int toggles = 0; // counts button change toggles
bool buttonPrevState = LOW; // previous button state 

void setup() {
  Serial.begin(9600); // start serial for debugging
  //** only use this while loop if your program will always have serial! 
  //while(!Serial) { } ; // wait for a serial connection --- !!!
  
  Serial.println("Hello World!");
  delay(3000); // wait a few seconds to enjoy our welcome message
  
  pinMode(LED1, OUTPUT); // set LED pin for output
  pinMode(buttonPin, INPUT); // set button pin for input

}

void loop() {

  bool buttonState = digitalRead(buttonPin); // read from the button

  if(buttonState == HIGH) { // if the button is pressed 
    digitalWrite(LED1, HIGH); // turn on the LED
    if(buttonState != buttonPrevState) { // did the state just change?
      toggles++; // increment the toggles count
      Serial.print(toggles); Serial.print(","); //high toggles count shows switch bouncing
      Serial.println(buttonState); // output button value to console and plotter
    }   
  } else {
    digitalWrite(LED1, LOW);
    if(buttonState != buttonPrevState) { // did the state just change?
      toggles++; // increment the toggles count
      Serial.print(toggles); Serial.print(","); //high toggles count shows switch bouncing
      Serial.println(buttonState); // output button value to console and plotter
    }
  }
  
  buttonPrevState = buttonState; // store the new value
}
