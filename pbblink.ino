/* The main goal of this program is that the LED will blink and when we press the PB, 
the serial monitor will be giving an indication of either 0 or 1 depending if it is pressed or not. The theme is Non-blocking timing and input processing.  */ 
 
// constants won't change. Used here to set a pin number: 
const int ledPin =  LED_BUILTIN;// the number of the LED pin 
int pushButton = 2; 
  
// Variables will change: 
int ledState = LOW;             // ledState used to set the LED 
  
// Generally, you should use "unsigned long" for variables that hold time 
// The value will quickly become too large for an int to store 
unsigned long previousMillis = 0;        // will store last time LED was updated 
  
// constants won't change: 
const long interval = 1000;           // interval at which to blink (milliseconds) 
  
void setup() { 
  // set the digital pin as output: 
  pinMode(ledPin, OUTPUT); 
Serial.begin(9600); 
pinMode(2, INPUT); 
} 
void loop() { 
  // here is where you'd put code that needs to be running all the time. 
  // check to see if it's time to blink the LED; that is, if the difference 
  // between the current time and last time you blinked the LED is bigger than 
  // the interval at which you want to blink the LED. 
  unsigned long currentMillis = millis(); 
  
  if (currentMillis - previousMillis >= interval) { 
    // save the last time you blinked the LED 
    previousMillis = currentMillis; 
  
    // if the LED is off turn it on and vice-versa: 
    if (ledState == LOW) { 
      ledState = HIGH; 
    } else { 
      ledState = LOW; 
    } 
    // set the LED with the ledState of the variable: 
    digitalWrite(ledPin, ledState); 
   int buttonState = digitalRead(pushButton); 
   Serial.println(buttonState); 
  } 
} 