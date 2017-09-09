#pragma once
class CCar
{
public:
	CCar();
	~CCar();
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
	int GetDirection() const;
	int GetSpeed() const;
	int GetGear() const;
	bool IsEngineOn() const;
private:
	int m_speed;
	int m_gear;
	bool m_engineIsOn;
	int m_direction;
};

