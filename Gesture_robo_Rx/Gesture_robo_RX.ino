#include<SoftwareSerial.h>

const int tx = 3, rx = 2;          // setting a tx and rx pin

const int a0 = 5, a1 = 6;         // motor1 pin declaration
const int b0 = 8, b1 = 9;         // motor2 pin declaration

SoftwareSerial _serial(rx, tx);

//String str;
char val;

#define Forward  digitalWrite(a0,1);digitalWrite(a1,0);digitalWrite(b0,1),digitalWrite(b1,0);          // passing high(1) or low(0) value to the motor
#define Backward digitalWrite(a0,0);digitalWrite(a1,1);digitalWrite(b0,0);digitalWrite(b1,1);
#define Right    digitalWrite(a0,0);digitalWrite(a1,0);digitalWrite(b0,1);digitalWrite(b1,0);
#define Left     digitalWrite(a0,1);digitalWrite(a1,0);digitalWrite(b0,0);digitalWrite(b1,0);
#define Stop     digitalWrite(a0,0);digitalWrite(a1,0);digitalWrite(b0,0);digitalWrite(b1,0);

void setup() {

  Serial.begin(115200);    
  _serial.begin(9600);       // setting bluetooth baud rate
  pinMode(a0, OUTPUT);       // declaring pins as output
  pinMode(a1, OUTPUT);
  pinMode(b0, OUTPUT);
  pinMode(b1, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:

  if (_serial.available() > 0)                          // checking for incoming data

  {
    //str = _serial.readStringUntil('\n');
    val = _serial.read();                 
    _serial.readStringUntil('\n');

    Serial.println(val);
  }

  switch (val)
  {
    case 'F': Forward; break;                         // calling the funtion according to the value
    case 'B': Backward; break;
    case 'R': Right; break;
    case 'L': Left; break;
    case 'S': Stop; break;

  }



}
