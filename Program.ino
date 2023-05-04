/*
  Project Name:
    Arduino Bluetooth Home Automation System 

  Participants:
    Ishrat  Jahan Ekra
    Ayesha  Alam Riya
    Baidika Achariya
    Ziniya  Afrin
  */

/*  To Control High Voltage ( 220 V ) Load Such as Light or Fan,
    We Used Relay Module.
    A Relay Module Takes Signal from Arduino and Turn ON or OFF the Load.
    0V signal => Relay OFF => Load OFF
    5V signal => Relay ON  => Load ON
*/

const int LIGHT = 7;  /* Using Arduino's digital pin number 7 to control light */
const int FAN   = 8;  /* Using Arduino's digital pin number 8 to control fan   */

void setup() {

  /* Begin serial communication with speed 9600 bps(bits per second)*/
  Serial.begin( 9600 );

  /* Set LIGHT pin as output to control it's voltage ( 0V or 5V)  */
  pinMode( LIGHT , OUTPUT );

  /* Set FAN   pin as output to control it's voltage ( 0V or 5V)  */
  pinMode( FAN, OUTPUT );

}

void loop() {

    /* If user send any data, that means serial is available */
    if ( Serial.available() ){

        /* Read the data from serial and store it in a character variable */
        char data = Serial.read();

        /* Condition for controlling LIGHT */
        if ( data == 'L' ){
            digitalWrite( LIGHT , HIGH ); /* Turn on  the LIGHT */
        }
        else if ( data == 'l' ){
            digitalWrite( LIGHT , LOW );  /* Turn off the LIGHT */
        }

        /* Condition for controlling FAN  */
        else if ( data == 'F' ){
            digitalWrite( FAN , HIGH );   /* Turn on  the FAN */
        }
        else if ( data == 'f' ){
            digitalWrite( FAN, LOW );     /* Turn off the FAN */
        }
 
    }

}
