#pragma once
enum struct Direction
{
	backward = -1,
	none = 0,
	forward = 1,
};

class CCar
{
public:
	CCar();
	~CCar();
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
	std::string GetDirection() const;
	int GetSpeed() const;
	int GetGear() const;
	bool IsEngineOn() const;
private:
	int m_speed;
	int m_gear;
	bool m_engineIsOn;
	Direction m_direction;
};

