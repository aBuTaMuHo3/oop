#include "stdafx.h"
#include "Car.h"


CCar::CCar()
{
}


CCar::~CCar()
{
}
bool CCar::TurnOnEngine()
{
	if (!engineIsOn)
	{
		engineIsOn = true;
		return true;
	}
	return false;

}

bool CCar::TurnOffEngine()
{
	if (engineIsOn&& currentGear == 0 && currentSpeed == 0)
	{
		engineIsOn = false;
		return true;		
	}
	return false;
}
bool CCar::SetGear(int gear)
{
	if (engineIsOn)
	{
		if (gear == -1 && currentSpeed == 0 && currentGear <= 1 && direction <= 0)
		{
			currentGear = -1;
			return true;
		}
		else if (gear == 0)
		{
			currentGear = 0;
			return true;
		}
		else if (gear == 1 && currentSpeed >= 0 && currentSpeed <= 30 && currentGear >= 1 || gear == 1 && currentSpeed == 0 && currentGear <= 0 && direction == 0)
		{
			currentGear = 1;
			return true;
		}
		else if (gear == 2 && currentSpeed >= 20 && currentSpeed <= 50 && currentGear >= 0)
		{
			currentGear = 2;
			return true;
		}
		else if (gear == 3 && currentSpeed >= 30 && currentSpeed <= 60 && currentGear >= 0)
		{
			currentGear = 3;
			return true;
		}
		else if (gear == 4 && currentSpeed >= 40 && currentSpeed <= 90 && currentGear >= 0)
		{
			currentGear = 4;
			return true;
		}
		else if (gear == 5 && currentSpeed >= 50 && currentSpeed <= 150 && currentGear >= 0)
		{
			currentGear = 5;
			return true;
		}
	}
	return false;
}
bool CCar::SetSpeed(int speed)
{
	if (engineIsOn)
	{
		if (currentGear == -1 && speed >= 0 && speed <= 20 && direction == 0)
		{
			currentSpeed = speed;
			direction = -1;
			return true;
		}
		else if (currentGear == 0 && speed >= 0 && speed <= currentSpeed)
		{
			currentSpeed = speed;
			return true;
		}
		else if (currentGear == 1 && speed >= 0 && speed <= 30)
		{
			currentSpeed = speed;
			direction = 1;
			return true;
		}
		else if (currentGear == 2 && speed >= 20 && speed <= 50)
		{
			currentSpeed = speed;
			return true;
		}
		else if (currentGear == 3 && speed >= 30 && speed <= 60 )
		{
			currentSpeed = speed;
			return true;
		}
		else if (currentGear == 4 && speed >= 40 && speed <= 90 )
		{
			currentSpeed = speed;
			return true;
		}
		else if (currentGear == 5 && speed >= 50 && speed <= 150)
		{
			currentSpeed = speed;
			return true;
		}
		if (currentGear <= 1 && currentGear >= -1 && currentSpeed == 0)
		{
			direction = 0;
		}
	}
	return false;
}

int CCar::GetDirection() const
{
	return direction;
}
int CCar::GetSpeed() const
{
	return currentSpeed;
}
int CCar::GetGear() const
{
	return currentGear;
}
bool CCar::IsEngineOn() const
{
	return engineIsOn;
}
