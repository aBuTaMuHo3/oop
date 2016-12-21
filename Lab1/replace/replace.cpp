// replace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

string SearchAndReplace(string fullString, const string &stringToFind, const string & stringToReplace)
{
	size_t position = fullString.find(stringToFind);
	if (position != string::npos)
	{
		if (position == 0)
		{
			return stringToReplace + SearchAndReplace(fullString.substr(position + stringToFind.length()), stringToFind, stringToReplace);
		}
		else
		{
			return fullString.substr(0, position) + stringToReplace + SearchAndReplace(fullString.substr(position + stringToFind.length()), stringToFind, stringToReplace);
		}
	}
	else
	{
		return fullString;
	}
}

int main(int argc, char* argv[])
{
	if (argc < 4 || argc >= 6)
	{
		cout << "Invalid arguments count\n" << "Usage: replace.exe <input file> <output file> <search string> <replace string>\n";
		return 1;
	}
	string inFileName = argv[1];
	string outFileName = argv[2];
	string searchString = argv[3];
	string replaceString = argv[4];

	fstream inputFile;
	inputFile.open(inFileName, fstream::in);
	if (!inputFile.is_open())
	{
		cout << "Impossible to find input file\n";
		return 1;
	}
	string fullString;
	fstream outFile;
	outFile.open(outFileName, fstream::out);
	while (!inputFile.eof())
	{
	    getline(inputFile, fullString);
		outFile << SearchAndReplace(fullString, searchString, replaceString) << endl;
	}
	outFile.close();
	inputFile.close();
	return 0;
}
