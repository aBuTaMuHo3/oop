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
	if (m_engineIsOn)
	{
		if (gear == -1 && m_speed == 0 && m_gear <= 1 && m_direction == Direction::none)
		{
			m_gear = -1;
			return true;
		}
		else if (gear == 0)
		{
			m_gear = 0;
			return true;
		}
		else if (gear == 1 && m_speed >= 0 && m_speed <= 30 && m_gear >= 1 || gear == 1 && m_speed == 0 && m_gear <= 0 && m_direction == Direction::none)
		{
			m_gear = 1;
			return true;
		}
		else if (gear == 2 && m_speed >= 20 && m_speed <= 50 && m_gear >= 0)
		{
			m_gear = 2;
			return true;
		}
		else if (gear == 3 && m_speed >= 30 && m_speed <= 60 && m_gear >= 0)
		{
			m_gear = 3;
			return true;
		}
		else if (gear == 4 && m_speed >= 40 && m_speed <= 90 && m_gear >= 0)
		{
			m_gear = 4;
			return true;
		}
		else if (gear == 5 && m_speed >= 50 && m_speed <= 150 && m_gear >= 0)
		{
			m_gear = 5;
			return true;
		}
	}
	return false;
}
bool CCar::SetSpeed(int speed)
{
	if (!m_engineIsOn)
	{
		return false;
	}
	switch (m_gear)
	{
		case -1:
		{
			if (speed >= 0 && speed <= 20 && (m_direction == Direction::none || m_direction == Direction::backward))
			{
				m_speed = speed;
				
				if (speed == 0)
				{
					m_direction = Direction::none;
				}
				else
				{
					m_direction = Direction::backward;
				}
				return true;
			}
			break;
		}
		case 0:
		{
			if (speed >= 0 && speed <= m_speed)
			{
				m_speed = speed;
				if (speed == 0)
				{
					m_direction = Direction::none;
				}
				return true;
			}
			break;
		}
		case 1:
		{
			if (speed >= 0 && speed <= 30)
			{
				m_speed = speed;
				if (speed == 0)
				{
					m_direction = Direction::none;
				}
				else
				{
					m_direction = Direction::forward;
				}				
				return true;
			}
			break;
		}
		case 2:
		{
			if (speed >= 20 && speed <= 50)
			{
				m_speed = speed;
				return true;
			}
			break;
		}
		case 3:
		{
			if (speed >= 30 && speed <= 60)
			{
				m_speed = speed;
				return true;
			}
			break;
		}
		case 4:
		{
			if (speed >= 40 && speed <= 90)
			{
				m_speed = speed;
				return true;
			}
			break;
		}
		case 5:
		{
			if (speed >= 50 && speed <= 150)
			{
				m_speed = speed;
				return true;
			}
			break;
		}
	}
	return false;
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
