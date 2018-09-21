/*
  Example: Shift Register 2 (IC and Display)
  Sidekick Basic Kit for TI LaunchPad
  
  Use a shift register to control multiple LEDs with less pins
  SN74HC595: 8-Bit Serial-In, Parallel-Out Shift
  
  Hardware Required:
  * TI LaunchPad
  * Breadboard
  * Shift Register (SN74HC595)
  * 8x LEDs (Green and Red)
  * 7 Segment Display
  * 19x Jumper wires 
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
                        

// Define the LED digit patterns for 0 - 9 in a 2 dimensional array.
// The 2D array (an array of arrays or a matrix) has 10 arrays that each 
// contain 7 values. 
// Note that these patterns are for common cathode displays. For common 
// anode displays, change the 1's to 0's and 0's to 1's
// 1 = LED on, 0 = LED off, in this order:
byte seven_segment_digits[10][7] = { { 1,1,1,1,1,1,0 }, // display '0'
                                     { 0,1,1,0,0,0,0 }, // display '1'
                                     { 1,1,0,1,1,0,1 }, // display '2'
                                     { 1,1,1,1,0,0,1 }, // display '3'
                                     { 0,1,1,0,0,1,1 }, // display '4'
                                     { 1,0,1,1,0,1,1 }, // display '5'
                                     { 1,0,1,1,1,1,1 }, // display '6'
                                     { 1,1,1,0,0,0,0 }, // display '7'
                                     { 1,1,1,1,1,1,1 }, // display '8'
                                     { 1,1,1,0,0,1,1 }  // display '9'
                                   };
                                
/* Connect the pins of the display accordingly. 
Only one of the GND pins need to be connected to work, but it's ok
to connect both if you want. 
///////////////TOP//////////////
   pin 1 : G (9)  pin 10: A (3)
   pin 2 : F (8)  pin 9 : B (4)
   pin 3 : GND    pin 8 : GND
   pin 4 : E (7)  pin 7 : C (5)
   pin 5 : D (6)  pin 6 : Dot (10)
/////////////BOTTOM/////////////
*/

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latch, OUTPUT);
  pinMode(3, OUTPUT); // set segment A as output
  pinMode(4, OUTPUT); // set segment B as output
  pinMode(5, OUTPUT); // set segment C as output
  pinMode(6, OUTPUT); // set segment D as output
  pinMode(7, OUTPUT); // set segment E as output
  pinMode(8, OUTPUT); // set segment F as output
  pinMode(9, OUTPUT); // set segment G as output
  pinMode(10, OUTPUT); // set dot as output
  for(int i = 3; i < 10; i++) { // start with segments off
    digitalWrite(i, LOW);
  }
  digitalWrite(10, LOW);  // start with the dot off

}

void loop() {

  //function that blinks all the LEDs
  //gets passed the number of blinks and the pause time
  blinkAll_2Bytes(1,500); 

  // light each pin one by one using a function A
  for (int j = 0; j < 8; j++) {
    //ground latchPin and hold low for as long as you are transmitting
    digitalWrite(latch, 0);
    //red LEDs
    lightShiftPinA(7-j);
    //green LEDs
    lightShiftPinA(j);
    //return the latch pin high to signal chip that it 
    //no longer needs to listen for information
    digitalWrite(latch, 1);
    delay(1000);
  }

  // light each pin one by one using a function A
  for (int j = 0; j < 8; j++) {
    //ground latchPin and hold low for as long as you are transmitting
    digitalWrite(latch, 0);
    //red LEDs
    lightShiftPinB(j);
    //green LEDs
    lightShiftPinB(7-j);
    //return the latch pin high to signal chip that it 
    //no longer needs to listen for information
    digitalWrite(latch, 1);
    delay(1000);
  } 

}

//This function uses bitwise math to move the pins up
void lightShiftPinA(int p) {
  //defines a local variable
  int pin;

  //this is line uses a bitwise operator
  //shifting a bit left using << is the same
  //as multiplying the decimal number by two. 
  pin = 1<< p;

  //move 'em out
  shiftOut(data, clock, pin);   

}

//This function uses that fact that each bit in a byte
//is 2 times greater than the one before it to
//shift the bits higher
void lightShiftPinB(int p) {
  //defines a local variable
  int pin;

  //start with the pin = 1 so that if 0 is passed to this
  //function pin 0 will light. 
  pin = 1;

  for (int x = 0; x < p; x++) {
    pin = pin * 2; 
  }
  //move 'em out
  shiftOut(data, clock, pin);   
}


// the heart of the program
void shiftOut(int myDataPin, int myClockPin, byte myDataOut) {
  // This shifts 8 bits out MSB first, 
  //on the rising edge of the clock,
  //clock idles low

  //internal function setup
  int i=0;
  int pinState;
  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, OUTPUT);

  //clear everything out just in case to
  //prepare shift register for bit shifting
  digitalWrite(myDataPin, 0);
  digitalWrite(myClockPin, 0);

  //for each bit in the byte myDataOut�
  //NOTICE THAT WE ARE COUNTING DOWN in our for loop
  //This means that %00000001 or "1" will go through such
  //that it will be pin Q0 that lights. 
  for (i=7; i>=0; i--)  {
    digitalWrite(myClockPin, 0);

    //if the value passed to myDataOut and a bitmask result 
    // true then... so if we are at i=6 and our value is
    // %11010100 it would the code compares it to %01000000 
    // and proceeds to set pinState to 1.
    if ( myDataOut & (1<<i) ) {
      pinState= 1;
    }
    else {	
      pinState= 0;
    }

    //Sets the pin to HIGH or LOW depending on pinState
    digitalWrite(myDataPin, pinState);
    //register shifts bits on upstroke of clock pin  
    digitalWrite(myClockPin, 1);
    //zero the data pin after shift to prevent bleed through
    digitalWrite(myDataPin, 0);
  }

  //stop shifting
  digitalWrite(myClockPin, 0);
}


//blinks both registers based on the number of times you want to 
//blink "n" and the pause between them "d"
//starts with a moment of darkness to make sure the first blink
//has its full visual effect.
void blinkAll_2Bytes(int n, int d) {
  digitalWrite(latch, 0);
  shiftOut(data, clock, 0);
  shiftOut(data, clock, 0);
  digitalWrite(latch, 1);
  delay(200);
  for (int x = 0; x < n; x++) {
    digitalWrite(latch, 0);
    shiftOut(data, clock, 255);
    shiftOut(data, clock, 255);
    digitalWrite(latch, 1);
    delay(d);
    digitalWrite(latch, 0);
    shiftOut(data, clock, 0);
    shiftOut(data, clock, 0);
    digitalWrite(latch, 1);
    delay(d);
  }
}