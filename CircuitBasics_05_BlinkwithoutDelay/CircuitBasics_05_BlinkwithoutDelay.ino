// Circuit Basics 05 - Blink without Delay
// Blink LEDs without interruptng the flow of a program
// Use this method to flash while reading input pots and buttons.
// By turning the knob change the rate which the LED flashes


// Connect a potentiometer to an Analog Input, by setting it up
// as a voltage divider.  Connect one end of the pot to ground, 
// the other to positive voltage, and the wiper to an Analog Input.
//
//         100k pot
//    5v---/\/\/\---GND
//            ^
//            |
//        Analog Input



byte LED1 = 9; // this pin controls the LED
byte analogInput = A0; // this is the analog input pin for the potentiometer

long currentMillis = 0; // current time value
long prevMillis = 0; // previous time value

int flashRate = 0; // time between flashes
bool toggle = LOW; // track the led toggling

void setup() {
  Serial.begin(9600); // start serial for debugging
  
  pinMode(LED1, OUTPUT); // set LED pin for output

}

void loop() {  
  flashRate = analogRead(analogInput); // read from the potentiometer

  if(currentMillis > prevMillis + flashRate) { //time has expired
    digitalWrite(LED1, toggle);
    toggle = !toggle; // switch value to 'not' toggle
    prevMillis = currentMillis; // reset the timer
  }

  currentMillis = millis(); // update time

}
