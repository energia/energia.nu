/*
  Buzzer
 * Note:  
 This example code is in the public domain.
*/
/* Macro Define */
#define BUZZER_PIN               19            /* sig pin of the buzzer */

int length = 10;         /* the number of notes */
char notes[] = "ccggaaffeeddc ";    /* the notes */
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };  /* the beats*/
int tempo = 300;    /* the tempo */

void setup()
{
    /* set buzzer pin as output */
    pinMode(BUZZER_PIN, OUTPUT);       
}

void loop()
{
    for(int i = 0; i < length; i++) {
        if(notes[i] == ' ') {
            delay(beats[i] * tempo);
        } else {
            playNote(notes[i], beats[i] * tempo);
        }
        delay(tempo / 2);    /* delay between notes */
    }
}
/* play tone */
void playTone(int _tone, int duration) {
   
    for(long i = 0; i < duration * 1000L; i += _tone*2 ) {
        digitalWrite(BUZZER_PIN, HIGH);
        delayMicroseconds(_tone);
        digitalWrite(BUZZER_PIN, LOW);
        delayMicroseconds(_tone);
    }
}
/* play notes */
void playNote(char note, int duration) {
    char name[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'c'};
    int _tone[] = {1915, 1700, 1519, 1432, 1275, 1136, 1014, 956};
    /* play the tone corresponding to the tone name */
    for(int i = 0; i < 8; i++) {
        if(name[i] == note) {
            playTone(_tone[i], duration);
        }
    }
}
