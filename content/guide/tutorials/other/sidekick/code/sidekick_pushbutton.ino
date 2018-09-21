/*
  Example 02: Push Button (Input)
  Sidekick Basic Kit for TI LaunchPad

  >Basic Example
  Turns red LED on the LaunchPad on and off using the PUSH2 button.

  >Advanced Example
  Turns on and off a light emitting diode(LED) connected to digital  
  pin 18, when pressing a push button attached to pin 19. 

  Hardware Required:
  * TI LaunchPad
  * Breadboard BoosterPack
  * Breadboard
  * Red LED
  * Push Button
  * 4x Jumper Wires
  * 330 ohm resistor (optional)
  * 10K ohm resistor (optional)

   This example code is in the public domain.
 */

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 19;     // the number of the pushbutton pin
const int ledPin =  18;      // the number of the LED pin

// variables will change:
int breadboardButtonState = 0; // variable for reading the BB button status
int launchpadButtonState = 0; // variable for reading the LP button state

/* In the setup we will set our LEDs to OUTPUT and our buttons
 * to INPUT_PULLUP
 */
void setup() {
  // initialize the breadboard LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the onboard LED
  pinMode(RED_LED, OUTPUT);
  // initialize the breadboard push button pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
  // initialize the onboard pushbutton
  pinMode(PUSH2, INPUT_PULLUP);  
}

/* In the loop section we going to get the state of the pin
 * using digitalRead() and save that to our variables
 * if the button is pressed we turn the LED on otherwise
 * the LED is off.
 */
void loop(){
  // read the state of the push button value:
  breadboardButtonState = digitalRead(buttonPin);
  launchpadButtonState = digitalRead(PUSH2);

  // check if the breadboard push button is pressed.
  // if it is, turn the breadboard LED state HIGH
  if (breadboardButtonState == 0) {       
    digitalWrite(ledPin, HIGH); // turn LED on:  
  } 
  else {
    digitalWrite(ledPin, LOW); // turn LED off:
  }
  
  // check if the LaunchPad pushbutton is pressed.
  // if it is, turn the LaunchPad LED state HIGH
  if (launchpadButtonState == 0) {     
    digitalWrite(RED_LED, HIGH); // turn LED on
  } 
  else {
    digitalWrite(RED_LED, LOW); // turn LED off
  }
}