// Circuit Basics 01 - Blink with Delay

byte LED1 = 9; // this pin controls the LED
int flashTime = 1000; // this is how long the LED will flash

void setup() {
  pinMode(LED1, OUTPUT); // set LED pin for output

  TXLED1; // turn off onboard leds on pro micro
  RXLED1; // turn off onboard leds on pro micro

}

void loop() {

  digitalWrite(LED1, HIGH); // turn LED ON
  delay(flashTime); // wait for a duration
  digitalWrite(LED1, LOW); // turn LED OFF
  delay(flashTime); // wait for a duration
  
}

