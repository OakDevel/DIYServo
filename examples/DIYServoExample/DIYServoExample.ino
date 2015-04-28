#include <DIYServo.h>


int motor_p1 = 7; // Digital Output
int motor_p2 = 8; // Digital Output
int pwmPin = 3; // PWM Pin
int potPin = 5; // Goes to the analog side of arduino
 
 
DIYServo customServo(motor_p1, motor_p2, pwmPin, potPin); //create an instance of the DC motor Class
 
//set the speed at which the motor will turn (Max speed = 255)
int turnSpeed = 100;
 
void setup()
{
     
  Serial.begin(9600); // Start a serial connection if needed
   
  Serial.println("Starting Setup...");
   
  //make sure the motor is stopped at startup...
   customServo.Stop();
   
   //Set the speed of the motor
  customServo.SetTurnSpeed(turnSpeed);
   
  //if the motor is not at the start point, then bring it to the start point
   
  int startPoint =180;
   
  customServo.GoToAngle(startPoint, turnSpeed);
   
  delay(3000); //wait for a few seconds before turning to and fro
 
}
 
void loop()
{
  
  //forwards turning..........
  for (int i = 30; i <= 330; i += 15) //our motor will turn from 30 to 150 degrees in steps of 15 degrees
  {
    customServo.GoToAngle(i, turnSpeed);
    delay(500);
     
  }
   
  //backwards turning..........
  for (int i = 330; i >=30; i-=15)//now turn from 150 to 30 degrees in steps of 15 degrees
  {
    customServo.GoToAngle(i, turnSpeed);
    delay(500);
     
  }
   
  //if the code above works as expected, try commanding the motor through the serial interface...
  //dont forget to uncomment the Serial.begin(9600) line in the setup() function
   
/*  
  if(Serial.available())
 {
   int x = Serial.parseInt();
   customServo.GoToAngle(x, turnSpeed);
 }
 */
   
   
}
