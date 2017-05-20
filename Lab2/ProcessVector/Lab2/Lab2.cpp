// Lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ProcessVector.h"
using namespace std;

int main()
{
	vector<double> numbers(istream_iterator<double>(cin), (istream_iterator<double>()));

	ProcessVector(numbers);
	//sort(numbers.begin(), numbers.end());
	copy(numbers.begin(), numbers.end(), ostream_iterator<double>(cout, ", "));

	cout << "\nSize of vector: " << numbers.size() << "\n";
    return 0;
}

