#include "stdafx.h"
#include "Car.h"

CCar::CCar()
{
	m_engineIsOn = false;
	m_gear = 0;
	m_direction = Direction::none;
	m_speed = 0;
}


CCar::~CCar()
{
}
bool CCar::TurnOnEngine()
{
	if (!m_engineIsOn)
	{
		m_engineIsOn = true;
		return true;
	}
	return false;

}

bool CCar::TurnOffEngine()
{
	if (m_engineIsOn&& m_gear == 0 && m_speed == 0)
	{
		m_engineIsOn = false;
		return true;		
	}
	return false;
}
bool CCar::SetGear(int gear)
{
	bool canSetGear = false;
	if (m_engineIsOn && gear <= 5 && gear >= -1)
	{
		canSetGear = (gear == -1 && m_speed == 0 && m_direction <= Direction::none) || (gear == 1 && m_speed == 0 && m_direction>= Direction::none) || (gear == 0)||(gear>=2);
		canSetGear = canSetGear && SpeedIsInRange(gear, GetSpeed());
		if (canSetGear)
		{
			m_gear = gear;
		}
	}
	return canSetGear;
}
bool CCar::SetSpeed(int speed)
{
	bool canSetSpeed = false;
	if (SpeedIsInRange(m_gear, speed)&&m_engineIsOn)
	{
		if (((m_gear == 0) && (speed <= GetSpeed())) || !(m_gear == 0))
		{
			m_speed = speed;
			if (speed == 0)
			{
				m_direction = Direction::none;
			}
			else
			{
				if (m_gear == -1)
				{
					m_direction = Direction::backward;
				}
				else if (m_gear >= 1)
				{
					m_direction = Direction::forward;
				}
			}
			canSetSpeed = true;
		}
	}
	return canSetSpeed;
}

std::string CCar::GetDirection() const
{
	std::string direction;
	if (m_direction == Direction::forward)
		direction = "forward";
	else if (m_direction == Direction::backward)
		direction = "backward";
	else if (m_direction == Direction::none)
		direction = "none";
	return direction;
}
int CCar::GetSpeed() const
{
	return m_speed;
}
int CCar::GetGear() const
{
	return m_gear;
}
bool CCar::IsEngineOn() const
{
	return m_engineIsOn;
}
bool CCar::SpeedIsInRange(int const &gear, int speed) const
{
	auto it = speedRange.find(gear);
	auto speedRange = it->second;
	return  (speedRange.second >= speed) && (speedRange.first <= speed);
}
