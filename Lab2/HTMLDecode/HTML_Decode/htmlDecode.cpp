#include "stdafx.h"
#include <boost/utility/string_ref.hpp>

using namespace std;
using boost::string_ref;

char CheckDictionary(string_ref stringToCheck, size_t startPos, size_t lentgh)
{
	char newChar;
	auto tempString = stringToCheck.substr(startPos, lentgh);
	if (tempString == "&amp;")//(stringToCheck.compare(startPos, endPos - startPos
	{
		newChar = '&';
	}
	else if (tempString == "&apos;")
	{
		newChar = '\'';
	}
	else if (tempString == "&lt;")
	{
		newChar = '<';
	}
	else if (tempString == "&gt;")
	{
		newChar = '>';
	}
	else if (tempString == "&quot;")
	{
		newChar = '\"';
	}
	else
	{
		return '\0';
	}
	return newChar;
}

string HtmlDecode(string const &html)
{
	char startSymbol = '&';
	char endSymbol = ';';
	size_t stringLength = html.length();
	string_ref htmlRef(html);
	string newString;
	size_t substrStart = 0, substrEnd = 0;
	char symbol;
	bool substringStarted = false;
	for (size_t i = 0; i< stringLength; ++i)
	{

		if (htmlRef[i] == startSymbol)
		{
			substringStarted = true;
			if(substrEnd != 0)
				newString = newString + html.substr(substrStart, substrEnd - substrStart + 1);
			substrStart = i;
		}
		if (substringStarted)
		{
			substrEnd = i;
			if (htmlRef[i] == endSymbol)
			{
				substringStarted = false;
				symbol = CheckDictionary(htmlRef, substrStart, substrEnd - substrStart + 1);
				if (symbol != '\0')
				{
					newString += symbol;
				}
				else
				{
					newString += html.substr(substrStart, substrEnd - substrStart + 1);
				}
				substrEnd = 0;
				substrStart = 0;
			}
		}
		else
		{
			newString += html[i];
		}
	}
	if (substringStarted)
	{
		newString = newString + html.substr(substrStart, substrEnd - substrStart + 1);
	}
	return newString;
}