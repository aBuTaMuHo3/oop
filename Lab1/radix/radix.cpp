// radix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define Digits "0123456789ABCDEFGHIGKLMNOPQRSTUVWXYZ"

using namespace std;


int StringToInt(const string &str, int radix, bool & wasError)
{
	int maxS = str.size();
	string digits = Digits;
	int i = 0, a = 0;
	bool negative = false;
	if (radix < 2)
	{
		wasError = true;
		cout << "Wrong source notation(must be 2 .. 35)" << endl;
	}
	if (str[0] == '-' )
	{
		negative = true;
		i = 1;
	}	
	for (; i < maxS&&!wasError; ++i)
	{
		int previous = a;
		int nextDigit = digits.find(str[i]);
		if (negative)
		{
			nextDigit = -nextDigit;
		}
		
		if (nextDigit >= radix)
		{
			wasError = true;
			cout << "Value mismatches source notation" << endl;			
			return 0;
		}
		a = a * radix + nextDigit;		
		if (previous != (a - nextDigit) / radix||negative&&previous<a)
		{
			wasError = true;
			cout << "Overflow!" << endl;
			return 0;
			
		}
		cout << (a - nextDigit) / radix << "\n" << previous << "\n";
	}	
	return a;
}
string IntToString(int n, int radix, bool & wasError)
{
	string number;
	bool negative = false;
	int i, a;
	if (radix < 2)
	{
		wasError = true;
		cout << "Wrong destination notation(must be 2 .. 35)" << endl;
	}
	if (n == 0)
	{
		number = "0";	
	}
	if (n < 0)
	{
		negative = true;
		//n = -n;
	}
	while (n != 0&&!wasError)
	{
		int digitValue = fabs(n%radix);
		number = Digits[digitValue] + number;
		n = n / radix;
	}
	if (negative)
	{
		return '-' + number;
	}
	else
	{
		return number;
	}
}
int main(int argc, char * argv[])
{
	if (argc != 4)
	{
	cout << "Invalid arguments count\n" << "Usage: radix.exe <source notation> <destination notation> <value>\n";
	return 1;
	}	
	string str = argv[3];
	bool wasError = false;
	long alpha = StringToInt(str, atoi(argv[1]), wasError);
	string beta = IntToString(alpha, atoi(argv[2]), wasError);
	//cout << INT32_MIN;
	cout << alpha << endl;
	if (wasError)
	{ 
		cout << "An error occured during program running" << "\n";
		return 1;
	}
	else
	{
		cout << beta << endl;
		return 0;
	}
}