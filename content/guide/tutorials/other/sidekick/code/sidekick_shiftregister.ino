/*
  Example 04: Shift Register (Integrated Circuit)
  Sidekick Basic Kit for TI LaunchPad
  
  Use a shift register to control multiple LEDs with less pins
  SN74HC595: 8-Bit Serial-In, Parallel-Out Shift
  
  Hardware Required:
  * TI LaunchPad
  * Breadboard BoosterPack
  * Breadboard
  * Shift Register (SN74HC595)
  * 8x LEDs (Green and Red)
  * 10x Jumper wires
  * 8x 330 ohm resistor (optional)
  
  This example code is in the public domain.
*/

// The SN74HC595 works with a protocol called SPI (Serial Peripheral 
// Interface) that uses 3 pins: data, latch, and clock. 
int data = 11; // connect data of shift register to pin 11 or LaunchPad
int latch = 12; // connect latch of shift register to pin 12 of LaunchPad
int clock = 13; // connect clock of shift register to pin 13 of LaunchPad

/* Connect the pins of the shift register accordingly
//////////////TOP//////////////
   pin 1: LED2   pin 16: VCC
   pin 2: LED3   pin 15: LED1
   pin 3: LED4   pin 14: data
   pin 4: LED5   pin 13: GND
   pin 5: LED6   pin 12: latch
   pin 6: LED7   pin 11: clock
   pin 7: LED8   pin 10: VCC
   pin 8: GND    pin  9: 
////////////BOTTOM/////////////
*/
                        
/* In the setup function we will set our data, clock, and latch pins 
 * to output. That's all we need to do at setup. 
 */
void setup()
{
  pinMode(data, OUTPUT);
  pinMode(latch, OUTPUT);  
  pinMode(clock, OUTPUT);  

}

/* In the loop section we will call the updateRegister() function defined later
 * in the code. There is also another way to do it using updateRegister2(). 
 * We use both to show that the result is the same. 
 */
void loop() 
{
  int delayTime = 300; // the number of milliseconds to delay between LED updates
  for(int i = 0; i < 256; i++){
   updateRegister(i);
   delay(delayTime); 
  }
  for(int i = 0; i < 256; i++){
   updateRegister2(i);
   delay(delayTime); 
  }
}

/* updateRegister() - in this function we will update the state of the shift register.
 * We first pull the latch pin low, then we use shiftOut() to shift the 8 bits to the 
 * shift register. Then we pull the latch pin high to display the new bits.
 */
void updateRegister(int value){
  digitalWrite(latch, LOW);
  shiftOut(data, clock, MSBFIRST, value);
  digitalWrite(latch, HIGH);
}

/* updateRegister2() - in this function we will update the state of the shift register.
 * We first pull the latch pin low, then for each bit we use a bit mask to check bit by 
 * bit which LEDs should be illuminated based on which number we are writing. This bit 
 * mask uses the binary &apos;and&apos; operation to compare the value being written with the bit 
 * mask equal to &apos;10000000&apos;.  If the most significant bit, or the left-most bit, is a 
 * '1', then the result of the &apos;and&apos; operation will also be a &apos;1&apos;.  We then shift the 
 * data stored in the value variable left by one bit so that every bit will sequentially 
 * become the most significant bit.  A shift is done using the &apos;<<&apos; operator to shift the 
 * value left, or the &apos;>>&apos; operator to shift the value right.  If the most significant bit 
 * is determined to be a &apos;1&apos;, then the corresponding LED is illuminated by writing HIGH to 
 * the data pin, otherwise a LOW is written.  Iterating through the value eight times allows
 * each bit to be compared to the bit mask. After this comparison on all eight bits is 
 * complete, we pulse the clock by turning it HIGH then LOW very quickly. We then pull the 
 * latch pin high to display the new bits.
 */
void updateRegister2(int value){
  digitalWrite(latch, LOW);
  for(int i = 0; i < 8; i++){  // Repeat 8 times (once for each bit)
    int bit = value & B10000000; // bitmask
    value = value << 1; // Move up one bit value
    if(bit == 128) { 
      digitalWrite(data, HIGH); // if last bit is set, pull data pin high
    } else { 
      digitalWrite(data, LOW); // if last bit is unset, pull data pin low
    }            
    digitalWrite(clock, HIGH); // pulse the clock pin
    delay(1);
    digitalWrite(clock, LOW);
  }
  digitalWrite(latch, HIGH);
}

