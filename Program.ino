/*
  Project Name:
    Arduino Bluetooth Home Automation System 

  Participants:
    Ayesha  Alam Riya
    Ishrat  Jahan Ekra
    Baidika Achariya
    Ziniya  Afrin
  */

/*  To Control High Voltage ( 220 V ) Load Such as Light or Fan,
    We Used Relay Module.
    A Relay Module Takes Signal from Arduino and Turn ON or OFF the Load.
    0V signal => Relay OFF => Load OFF
    5V signal => Relay ON  => Load ON
*/

#include <EEPROM.h>
const int LIGHT = 8;  /* Using Arduino's digital pin number 8 to control light */

void setup() {

  /* Begin serial communication with speed 9600 bps(bits per second)*/
  Serial.begin( 9600 );

  /* Set LIGHT pin as output to control it's voltage ( 0V or 5V)  */
  pinMode( LIGHT, OUTPUT );

  /* Read EEPROM Memory to Restore  Last Status */
  if ( EEPROM.read(LIGHT) ){
      digitalWrite( LIGHT , HIGH ); /* Turn on  the LIGHT */
  }
  else if ( !EEPROM.read(LIGHT) ){
      digitalWrite( LIGHT , LOW ); /* Turn on  the LIGHT */
  }

}

void loop() {

    /* If user send any data, that means serial is available */
    if ( Serial.available() ){

        /* Read the data from serial and store it in a character variable */
        char data = Serial.read();

        /* Condition for controlling LIGHT */
        if ( data == 'L' ){
            digitalWrite( LIGHT , HIGH ); /* Turn on  the LIGHT */
            EEPROM.write( LIGHT, true );  /* Store current status */
        }
        else if ( data == 'l' ){
            digitalWrite( LIGHT , LOW );  /* Turn off the LIGHT */
            EEPROM.write( LIGHT, false ); /* Store current status */
        }
 
    }

}
