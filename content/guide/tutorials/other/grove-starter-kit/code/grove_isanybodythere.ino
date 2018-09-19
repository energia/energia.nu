/*
  Grove-PIR-Motion-Sensor

* Note: Position the trig jumper on N_Retrig to ensure   
 This example code is in the public domain.
*/

/* Macro Define */
#define PIR_MOTION_SENSOR        7            /* sig pin of the PIR sensor */
#define LED                      RED_LED      /* led */

#define ON                       HIGH                    /* led on */
#define OFF                      LOW                     /* led off */
#define _handle_led(x)           digitalWrite(LED, x)    /* handle led */ 

/* the setup() method runs once, when the sketch starts */
void setup() {
    pinMode(PIR_MOTION_SENSOR, INPUT);   /* declare the sig pin as an INPUT */
    pinMode(RED_LED, OUTPUT);            /* declare the red_led pin as an OUTPUT */
    _handle_led(OFF);
}

/* the loop() method runs over and over again */
void loop() {
    if(isPeopleDetected()) {
        _handle_led(ON);           /* if we detect a people, turn on the led */
    } else {
        _handle_led(OFF);          /* found nobody, turn off the light */
    }
  
}

/* judge if there is a people around */
boolean isPeopleDetected() {
    int sensor_val = digitalRead(PIR_MOTION_SENSOR);        /* read sig pin */
    if(HIGH == sensor_val) {
        return true;                                        /* people detected */
    } else {
        return false;                                       /* people un-detected */
    }
}