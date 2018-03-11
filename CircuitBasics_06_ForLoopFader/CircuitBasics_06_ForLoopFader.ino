// Circuit Basics 06 - For Loop Fader
// For Loops are used to count or increment through a series of 
// values or variables.  This example fades an LED from 0 to 255
// in a 'ramp' wave.  Modifications can be made for a smooth fade 
// up and down as a 'saw' or 'sine' wave.
//

byte LED1 = 9; // this pin controls the LED
int maximum = 255; // this is the maximum count
int wait = 10; // delay time for fading


void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT); // set LED pin for output
}

void loop() {  
  
  for(byte i = 0; i < maximum; i = i+1) { // fade up
    analogWrite(LED1, i);
    Serial.println(i); //send the value to the console
    delay(wait);
  }
  
  for(byte i = maximum; i > 0; i = i-1) { // fade down
    analogWrite(LED1, i);
    Serial.println(i); //send the value to the console
    delay(wait);
  }
  
}
