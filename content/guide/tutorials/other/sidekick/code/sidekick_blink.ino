/*
  Example 00: Blinking LED (Output)
  Sidekick Basic Kit for TI LaunchPad
  
  Blink is the most basic Energia example. It is how we know our hardware
  and software environment is correctly set up. 
  
  Turns on an LED on for one second, then off for one second, repeatedly.
  Change the LED define to blink other LEDs.
  
  Hardware Required:
  * LaunchPad with an LED
  
  This example code is in the public domain.
*/

// The code above is called a "Comment Block" This is a section of 
// code where the programmer can make notes to themselves and others
// looking at the code in the future. In comments, we can explain
// related concepts or how the code works.  To make a comment block
// in Energia, open with forward slash + asterick "/*" and close with 
// asterick + forward slash "*/"  
// To make a single line comment use double forward slash "//"

// most launchpads have a red LED called RED_LED in Energia
// let's give it a new name LED using #define
#define LED RED_LED

// there may be more LEDs defined like a green LED
//#define LED GREEN_LED

/* Now we have our first function called setup().
 * A function is a block of code that will run sequentially.
 * It will have a name (this time "setup"), a type (this time
 * "void"), and is enclosed with curly brackets "{" and "}"
 *
 * A function can also have arguments that go inside the 
 * parenthesis but this time we don't have any so it's empty.
 * 
 * The setup function will run once at the beginning of your
 * Energia sketch.
 */ 
void setup() {                
  // initialize the digital pin as an output.
  pinMode(LED, OUTPUT);     
}

/* Now we have our function called loop()
 * The loop function will run forever, repeating whatever code
 * is inside. To blink an LED, we want to turn on the LED, wait
 * for 1 second, and then turn off the LED and wait for 1 second
 * If we put this code inside the loop() it will blink forever
 * or at least as long as the LaunchPad has power.
 */
void loop() {
  digitalWrite(LED, HIGH);   // turn the LED on by making the LED pin HIGH
  delay(1000);               // wait for a second
  digitalWrite(LED, LOW);    // turn the LED off by making the pin LOW
  delay(1000);               // wait for a second
}