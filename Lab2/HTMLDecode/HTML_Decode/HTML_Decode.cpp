// HtmlDecode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;
string CheckDictionary(string const &stringToCheck)
{
	string newString;
	if (stringToCheck == "&amp;")
	{
		newString = "&";
	}
	else if (stringToCheck == "&apos;")
	{
		newString = "'";
	}
	else if (stringToCheck == "&lt;")
	{
		newString = "<";
	}
	else if (stringToCheck == "&gt;")
	{
		newString = ">";
	}
	else if (stringToCheck == "&quot;")
	{
		newString = "\"";
	}
	else
	{
		return stringToCheck;
	}
	return newString;
}

string HtmlDecode(string const &html)
{
	char startSymbol = '&';
	char endSymbol = ';';
	size_t stringLength = html.length();
	string newString, tempString;
	char symbol;
	bool substringStarted = false;
	for (int i = 0; i< stringLength;++i)
	{
		symbol = html[i];
		if (symbol == startSymbol)
		{
			substringStarted = true;
			newString += tempString;
			tempString.clear();
		}
		if (substringStarted)
		{
			tempString += symbol;
			if (symbol == endSymbol)
			{
				substringStarted = false;
				newString += CheckDictionary(tempString);
				tempString.clear();
			}		
		}
		else
		{
			newString += symbol;
		}
	}
	newString += tempString;
	return newString;
}


int main(int argc, char* argv[])
{
	string alpha;
	while (!cin.eof())
	{
		getline(cin, alpha);
		//cin >> alpha;
		cout << HtmlDecode(alpha) << endl;
	}
	return 0;
}

