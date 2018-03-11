// Circuit Basics 04 - Analog Input
// Use Analog Read to read values between 0 and 1023 on an Analog Input
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



byte LED1 = 9; // this pin controls the LED
byte analogInput = A0; // this is the analog input pin for the potentiometer

void setup() {
  Serial.begin(9600); // start serial for debugging
  
  pinMode(LED1, OUTPUT); // set LED pin for output

}

void loop() {  
  int analogReading = analogRead(analogInput); // read from the potentiometer

  // change the input value to a new range using the map() function
  // map(value, valueMin, valueMax, outMin, outMax);
  int ledBrightness = map(analogReading, 0, 1023, 0, 255);
  analogWrite(LED1, ledBrightness);
  
  // make a ranged display with max and min lines
  Serial.print(0); Serial.print(","); Serial.print(1023); Serial.print(",");

  Serial.println(analogReading); // send reading value to Serial console for plotting
  
  delay(10); // slow everything down 

}
