/*
  Example 07: Photoresistor (Light Sensor)
  Sidekick Basic Kit for TI LaunchPad
  
  Use the photoresistor (also called photocell) to trigger a threshold.
  The photocell will change it's resistance based on light. You can 
  change the voltage divider to adjust the brightness detected.  The 
  photocell is not super sensistive so shine a light and cover it to 
  see a significant change. If you are in a lighter room use a 1K ohm
  resistor and use a 10K ohm resistor in a darker room. 
   
  Hardware Required:
  * TI LaunchPad
  * Breadboard
  * Photoresistor
  * Red LED
  * 1K or 10K ohm resistor
  * 330 ohm resistor (optional)
  * 5x Jumper wires
  
  This example code is in the public domain.
*/


/* In the setup function we initialize serial communication and set
 * the external LED on PWM pin 19 as OUTPUT. You can use a different 
 * LED if you prefer. Connect the photoresistor to pin 2.
 */
void setup()
{
  Serial.begin(9600); // initialize serial communication 
  pinMode(19, OUTPUT); // sets the LED on pin 19 to output
}

/* In the loop section we will read the photoresistor analog value
 * then we will use the map() and constrain() functions to adjust the 
 * range for PWM. When the photoresistor is dark the LED will turn on, 
 * you can cover the photoresistor with your hand to block out light.
 */
void loop()
{
  int lightLevel = analogRead(2); // Read the light level from analog pin 2
  delay(1); // delay for 1 millisecond for smoothness
  Serial.println(lightLevel); // Print the analog value to Serial
  // adjust the value 0 to max resolution to span 0 to 255
  lightLevel = map(lightLevel, 0, 4096, 0, 255); 
  lightLevel = constrain(lightLevel, 0, 255); // constrain values between 0-255
  analogWrite(19, lightLevel); // Write the PWM value to the LED
}