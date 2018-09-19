/*
  Example 08: Spin the Motor (Transistor)
  Sidekick Basic Kit for TI LaunchPad
  
  We will use the motor in this circuit and learn how to 
  master a transistor to help us control different voltages.
  
  
  Hardware Required:
  * TI LaunchPad
  * Breadboard BoosterPack
  * Breadboard
  * DC Motor
  * 2x Transistor (2N2222)
  * Diode (1N4004)
  * 100 nF capacitor (optional
  * 330 ohm resistor (optional)
  * 5x Jumper Wires
  
  This example code is in the public domain.
*/

// pick any digitalWrite() capable pin for the motor control
int motorPin = 19;

/* In the setup function set your motor pin as output.
 * Write it low to start.
 */
void setup()
{
  pinMode(motorPin, OUTPUT);
  digitalWrite(motorPin, LOW);
}

/* In the loop section you can set the on time and 
 * off time of the motor (1 second on, 2 seconds off)
 * and just write HIGH or LOW ot the motor pin.
 */
void loop()
{
  int onTime = 3000; // time the motor is on
  int offTime = 2000; // time the motor is off
  digitalWrite(motorPin, HIGH);
  delay(onTime);
  digitalWrite(motorPin, LOW);
  delay(offTime);
}