#include<SoftwareSerial.h>

const  int rx = 2, tx = 3;            // setting our own serial pins

const  int x_pin = A0;                // assigning ADXL pin number to variables
const  int y_pin = A1;
const  int z_pin = A2;

SoftwareSerial _serial(rx, tx);

int x_val, y_val, z_val;

void setup()
{
  pinMode( x_pin, INPUT);            // Setting pins as input
  pinMode( y_pin, INPUT);
  pinMode( z_pin, INPUT);
  Serial.begin(115200);
  _serial.begin(9600);
}

void loop()
{
  Serial.println( "x_out :" + String( analogRead(x_pin) )  );          // reading the data from the pins 
  Serial.println( "y_out :" + String( analogRead(y_pin) )   );
  Serial.println( "z_out :" + String( analogRead(z_pin) )   );
  Serial.println("…………………………………………………………");

  //_serial.print(analogRead(x_pin));

  x_val = analogRead(x_pin);
  y_val = analogRead(y_pin);
  z_val = analogRead(z_pin);

  if ( x_val > 350 )                              // comparing the obtainied value to the threshold value
  {
    _serial.println('F');                         // it will send the character according to the values of ADXl
  }
  else if ( x_val < 260 )
  {
    _serial.println('B');
  }

  if ( y_val < 290)
  {
    _serial.println('R');
  }
  else if ( y_val > 400 )
  {
    _serial.println('L');
  }
  if ( z_val > 400 )
  {
    _serial.println('S');
  }

  delay(2000);                              // stop the controller for 2 sec
}
