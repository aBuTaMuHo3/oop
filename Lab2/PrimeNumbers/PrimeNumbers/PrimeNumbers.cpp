// PrimeNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iterator>
#include "ProcessPrimeNumbers.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n";
		return 1;
	}
	int upperBound = atoi(argv[1]);
	if ((upperBound < 2) && (upperBound > 100000000))
	{
		cout << "Invalid input number";
		return 1;
	}
	set<int> numbers = GeneratePrimeNumbersSet(upperBound);
	cout << "Size of set:" << numbers.size();
	return 0;
}

