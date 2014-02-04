/***********************************************************************************
 *           RobotGeek Firgelli Linear Actuator Control Demo   
 *           Precoded Button Control                
 * 
 *
 *  The following sketch will allow you to control a Firgelli Linear actuator using
 *  three RobotGeek Pushbutton Sensors.
 *
 *  Products
 *  
 *    http://www.robotgeek.com/robotgeek-geekduino-sensor-kit
 *    http://www.robotgeek.com/robotGeek-pushbutton
 *    http://www.robotgeek.com/p/power-supply-6vdc-2a.aspx
 *    Firgelli Mini Linear Actuators http://www.robotgeek.com/store/Search.aspx?SearchTerms=firgelli
 *    http://www.robotgeek.com/robotgeek-small-workbench.aspx
 
 *  Wiring
 *    100mm Linear Actuator - Digital Pin 9 
 *
 *    Button1 - Analog Pin 0
 *    Button2 - Analog Pin 1 
 *    Button3 - Analog Pin 2
 *    Jumper for pins 9/10/11 should be set to 'VIN'
 *  
 *
 *  Control Behavior:
 *    Each button is coded to a set position and moves the linear actuator to that position
 *
 *  External Resources
 *
 ***********************************************************************************/


//Includes
#include <Servo.h> 

//Defines
#define LINEARACTUATORPIN 9        //Linear Actuator Digital Pin

const int button1Pin = 1;     // the number of the pushbutton pin
const int button2Pin = 2;     // the number of the pushbutton pin
const int button3Pin = 4;     // the number of the pushbutton pin

// variables will change:
int button1State = 0;         // variable for reading the pushbutton status
int button2State = 0;         // variable for reading the pushbutton status
int button3State = 0;         // variable for reading the pushbutton status

Servo LINEARACTUATOR;  // create servo objects to control the linear actuator

int linearValue = 1500;   //current positional value being sent to the linear actuator. 


void setup() 
{ 
  //initialize servo/linear actuator objects
  LINEARACTUATOR.attach(LINEARACTUATORPIN, 1050, 2000);      // attaches/activates the linear actuator as a servo object 

  // initialize the pushbutton pin as an input:
  pinMode(button1Pin, INPUT);   
  pinMode(button2Pin, INPUT);  
  pinMode(button3Pin, INPUT);      
  
  //use the writeMicroseconds to set the linear actuators to their default positions
  LINEARACTUATOR.writeMicroseconds(linearValue); 

} 

void loop() 
{ 

  // if the pushbutton is pressed set the linear value
  button1State = digitalRead(button1Pin);
  if (button1State == HIGH) {    
    // set the position value  
    linearValue = 1300;  
  } 

  button2State = digitalRead(button2Pin);
  if (button2State == HIGH) {     
    // set the position value   
    linearValue = 1500;  
  } 

  button3State = digitalRead(button3Pin);  
  if (button3State == HIGH) {     
    // set the position value   
    linearValue = 1700;  
  }   

  //use the writeMicroseconds to set the actuator to the new position
  LINEARACTUATOR.writeMicroseconds(linearValue); 

} 

