// Auto.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Car.h"
#include "CarController.h"

using namespace std;

int main()
{
	CCar car;
	CCarController controller(car, cin, cout);
	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!controller.HandleCommand())
		{
			cout << "Unknown command!" << endl;
		}
	}
	return 0;
}


