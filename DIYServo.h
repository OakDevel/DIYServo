/**************************************
* Library for DIY Servo from DC Motor 
* - Original Author: https://bayesianadventures.wordpress.com/2014/01/04/diy-servo-motor-cheap-and-with-plenty-muscle/
****************************************/



#ifndef DIYServo_h
#define DIYServo_h


#define POT_VALUE_MAX 1024 //Potentiometer reading when motor shaft is at 360
#define POT_VALUE_MIN 0 // Pot reading when motor shaft is 0 degree position
#define PERM_ERROR 5 //The max permissible error in degrees
#define MAX_ANGLE 360 // Maximum allowance of motor to turn 360 degree 

class DIYServo
{
private:
  int M_Pin1, M_Pin2, M_PWMPin;
  int potPin;
  int M_Speed;
  int turnDirection;
  enum turnDirection {right, left};

public:
  DIYServo(int p1, int p2, int p3, int p4); //Constructor
  void SetTurnDirection(int dir); // Setting turn direction
  void SetTurnSpeed(int s);
  void Turn();
  void Stop();
  void GoToAngle(int target, int howFast);
};

#endif
