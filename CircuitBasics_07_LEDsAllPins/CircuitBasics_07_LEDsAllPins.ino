// Circuit Basics 07 - LED display on ALL pins
// Blink LEDs without interruptng the flow of a program
// Fade LEDs using PWM, use Random to seed different patterns
// Use this display for a variety of student outcome

long currentMillis = 0; // current time value
long prevMillis = 0; // previous time value

const byte ledPinCount = 11;
const byte ledPWMcount = 5;

byte ledPins[] = {2,4,7,8,16,14,15,18,19,20,21};
byte ledPWM[] =  {3,5,6,9,10};

int flashTimeDigital[ledPinCount];
bool ledToggle[ledPinCount];
int flashTimeAnalog[ledPWMcount];
byte ledFade[ledPWMcount];
byte ledDir[ledPWMcount];
long ledPrevDigital[ledPinCount];
long ledPrevAnalog[ledPWMcount];

byte maxBright = 150;
byte minBright = 0;

void setup() {
  Serial.begin(9600); // start serial for debugging
  TXLED1; // turn off onboard leds on pro micro
  RXLED1; // turn off onboard leds on pro micro
  randomSeed(A0); // seed random
  for(byte i=0;i<ledPinCount;i++) {
    pinMode(ledPins[i], OUTPUT); // set LED pins for output
    ledPrevDigital[i] = 0;
    flashTimeDigital[i] = random(250, 2000); // digital delay time
  }
  for(byte i=0;i<ledPWMcount;i++) {
    pinMode(ledPWM[i], OUTPUT); // set LED pins for output
    ledPrevAnalog[i] = 0;
    flashTimeAnalog[i] = random(1, 50); // LED fade rate
    ledFade[i] = 0; // set value to 0
    ledDir[i] = 1; // fade up
  }
  for(byte i=0;i<ledPinCount;i++){ 
    ledPrevDigital[i]=0; //time set
    ledToggle[i] = 0;
  }
  for(byte i=0; i<ledPWMcount; i++) {
    ledPrevAnalog[i] = 0; //time set
  }
  
}


void loop() {  

  for(byte i=0;i<ledPinCount;i++){ // digital LEDs
    if(currentMillis - ledPrevDigital[i] > flashTimeDigital[i]){
      //toggle digital 
      ledToggle[i] = !ledToggle[i];
      digitalWrite(ledPins[i], ledToggle[i]);
      ledPrevDigital[i] = currentMillis; // reset time
    }
  }
  for(byte i=0;i<ledPWMcount;i++){ // analog LEDs
    if(currentMillis - ledPrevAnalog[i] > flashTimeAnalog[i]) {
      if(ledFade[i] >= maxBright) ledDir[i] = 0;
      if(ledFade[i] <= minBright) ledDir[i] = 1;
      if(ledDir[i] == 1) ledFade[i]++; else ledFade[i]--;
      analogWrite(ledPWM[i], ledFade[i]);
      ledPrevAnalog[i] = currentMillis; // reset time  
    }
  }
  currentMillis = millis(); // update time

}
