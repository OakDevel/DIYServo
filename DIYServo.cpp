#include "DIYServo.h"
#include <Arduino.h>
//Constructor 
/*
p1 = Direction pin on L298
p2 = Direction Pin on L298
p3 = PWM Pin on L298
p4 = Potentiometer pin
*/
DIYServo::DIYServo(int p1, int p2, int p3, int p4)
{
	M_Pin1 = p1;
	M_Pin2 = p2;
	M_PWMPin = p3;
	potPin = p4;
	pinMode(M_Pin1, OUTPUT);
	pinMode(M_Pin2, OUTPUT);
	//Debugging purpose
	// Serial.println("Creating DYIServo constructor");

}

//Setting turn direction
void DIYServo::SetTurnDirection(int dir)
{
	turnDirection = dir;
	switch(turnDirection)
	{
		case right:
			digitalWrite(M_Pin1, HIGH);
			digitalWrite(M_Pin2, LOW);
			break;

		case left:
			digitalWrite(M_Pin1, LOW);
			digitalWrite(M_Pin2, HIGH);
			break;

	}
}

//Setting turn speed
void DIYServo::SetTurnSpeed(int s)
{
	M_Speed = s;
}

//Set to turn
void DIYServo::Turn()
{
	analogWrite(M_PWMPin, M_Speed);
}

//Stop
void DIYServo::Stop()
{
	analogWrite(M_PWMPin, 0);
}

//Servo in action
void DIYServo::GoToAngle(int target, int howFast)
{
	int currentAngle = ((float)(analogRead(potPin)) - POT_VALUE_MIN)/POT_VALUE_MAX  * MAX_ANGLE;

	if (currentAngle < target){
		SetTurnDirection(right);
	} else if (currentAngle > target){
		SetTurnDirection(left);
	}

	SetTurnSpeed(howFast);

	while (abs(currentAngle - target) > PERM_ERROR){
		float P_CONSTANT = 5;
		float errVal = abs(currentAngle - target);

		int maxTurnSpeed = 150;

		if (errVal > 50)
		{
			SetTurnSpeed(maxTurnSpeed);
		} else {
			SetTurnSpeed((int)(errVal * P_CONSTANT));
		}

		Turn();

		delay(50);

		 currentAngle = ((float)(analogRead(potPin)) - POT_VALUE_MIN)/POT_VALUE_MAX  * MAX_ANGLE;


		 //Printing status for debugging purpose

	  Serial.print("Pot Pin:");
      Serial.print(analogRead(potPin));
      Serial.print(",   Max vlue:");
      Serial.print(MAX_ANGLE);
      Serial.print(",   Current Angle:");
      Serial.print(currentAngle);
      Serial.print(",    Target Angle:");
      Serial.println(target);

	}

	Stop();
}
