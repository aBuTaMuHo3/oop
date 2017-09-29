#pragma once
#define MAX_SPEED 150
#define MIN_SPEED 0
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
	bool SpeedIsInRange(int const &gear, int speed) const;
	bool CheckGear(int gear) const;
};

typedef std::pair<int, int> Speed;
typedef std::map<int, Speed> SpeedRange;

static const SpeedRange speedRange =
{
	{ -1, Speed(MIN_SPEED, 20) },
	{ 0, Speed(MIN_SPEED, MAX_SPEED) },
	{ 1, Speed(MIN_SPEED, 30) },
	{ 2, Speed(20, 50) },
	{ 3, Speed(30, 60) },
	{ 4, Speed(40, 90) },
	{ 5, Speed(50, MAX_SPEED) }
};
