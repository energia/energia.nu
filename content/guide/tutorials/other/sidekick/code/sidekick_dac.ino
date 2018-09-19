/* DAC Example */
#define CS 8 // chip select
#define CLOCK 9
#define DATA  10
 
#define HALF_CLOCK_PERIOD 2 //2 uS of clock period 
float j=0;
int data;
int value;
void setup()
{
   pinMode(DATA, OUTPUT);
   pinMode(CLOCK,OUTPUT);
   pinMode(CS,OUTPUT);
   digitalWrite(CS,HIGH);
   digitalWrite(DATA,LOW);
   digitalWrite(CLOCK,LOW); 
}
 
void writeValue(uint16_t value)
{
   digitalWrite(CS,LOW);//start of 12 bit data sequence
   digitalWrite(CLOCK,LOW);
   data = data << 2; //Add 2 0 at the end of the data. A 10-bit data word should add 2 0 at the LSB bit (sub-LSB) since the DAC input latch is 12 bits wide.(SEE TLC5615C DATASHEET)    
   for(int i=11; i>=0; i--)//send the 12 bit sample data
   {
      digitalWrite(DATA, (value & (1 << i) ) >> i );//DATA ready
      delayMicroseconds(HALF_CLOCK_PERIOD);
      digitalWrite(CLOCK,HIGH);//DAC get DATA at positive edge
      delayMicroseconds(HALF_CLOCK_PERIOD);
      digitalWrite(CLOCK,LOW);
   }
   digitalWrite(CS,HIGH);//end 12 bit data sequence
}
 
void loop()
{
   j=567; //in here, 567 is a example. DAC OUT=j*Vref/1024
   writeValue(floor(j));
}