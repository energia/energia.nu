/*
  Relay
  The basic Energia example.
.    
  This example code is in the public domain.
*/
#define RELAY_PIN    9
  
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(RELAY_PIN, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(RELAY_PIN, HIGH);   // turn the relay on (HIGH is the voltage level)
  delay(1000);                     // wait for a second
  digitalWrite(RELAY_PIN, LOW);    // turn the relay off by making the voltage LOW
  delay(1000);               // wait for a second
}
