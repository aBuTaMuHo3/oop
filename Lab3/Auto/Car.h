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
	int currentSpeed = 0;
	int currentGear = 0;
	bool engineIsOn = false;
	int direction = 0;
};

