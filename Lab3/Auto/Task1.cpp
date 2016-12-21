// Auto.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Car.h"

using namespace std;
int main()
{
	CCar car;
	cout <<"Turn on: "<< car.TurnOnEngine() << endl;
	cout << "Is on: " << car.IsEngineOn() << endl;
	car.SetSpeed(20);
	cout <<"Speed: " << car.GetSpeed() << endl;
	car.SetGear(1);
	car.SetSpeed(20);
	cout << "\n Speed: " << car.GetSpeed() << endl;
	cout << " Gear: " << car.GetGear() << endl;
	car.SetGear(2);
	car.SetSpeed(20);
	cout << "\n  Speed: " << car.GetSpeed() << endl;
	cout << " Gear: " << car.GetGear() << endl;
	car.SetGear(3);
	car.SetSpeed(30);
	cout << "\n  Speed: " << car.GetSpeed() << endl;
	cout << " Gear: " << car.GetGear() << endl;
	car.SetGear(3);
	car.SetSpeed(60);
	cout << "\n  Speed: " << car.GetSpeed() << endl;
	cout << " Gear: " << car.GetGear() << endl;
	car.SetGear(-1);
	car.SetSpeed(30);
	cout << "\n  Speed: " << car.GetSpeed() << endl;
	cout << " Gear: " << car.GetGear() << endl;
	car.SetGear(-1);
	car.SetSpeed(0);
	cout << "\n  Speed: " << car.GetSpeed() << endl;
	cout << " Gear: " << car.GetGear() << endl;
	car.SetGear(1);
	car.SetSpeed(0);
	cout << "\n  Speed: " << car.GetSpeed() << endl;
	cout << " Gear: " << car.GetGear() << endl;
	car.SetGear(0);
	car.SetSpeed(20);
	cout << "\n  Speed: " << car.GetSpeed() << endl;
	cout << " Gear: " << car.GetGear() << endl;
	car.SetGear(-1);
	car.SetSpeed(20);
	cout << "\n  Speed: " << car.GetSpeed() << endl;
	cout << " Gear: " << car.GetGear() << endl;
    return 0;
}

