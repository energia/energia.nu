/*
  Example 08B: Switch Voltage (Transistor)
  Sidekick Basic Kit for TI LaunchPad
  
  We will learn how to master a transistor to help 
  us control different voltages.
  
  
  Hardware Required:
  * TI LaunchPad
  * Breadboard BoosterPack
  * Breadboard
  * 1x Red LED
  * 1x Transistor (LP395 or 2N2222)
  * 330 ohm resistor (optional)
  * 3x Jumper Wires
  
  This example code is in the public domain.
*/

// pick any digitalWrite() capable pin for the LED control
int ledPin = 19;

/* In the setup function set your motor pin as output.
 * Write it low to start.
 */
void setup()
{
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

/* In the loop section you can set the on time and 
 * off time of the LED (3 second on, 2 seconds off)
 * and just write HIGH or LOW ot the motor pin.
 */
void loop()
{
  int onTime = 3000; // time the motor is on
  int offTime = 2000; // time the motor is off
  digitalWrite(ledPin, HIGH);
  delay(onTime);
  digitalWrite(ledPin, LOW);
  delay(offTime);
}