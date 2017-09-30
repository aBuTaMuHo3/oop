// HtmlDecode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "htmlDecode.h"
using namespace std;


int main(int argc, char* argv[])
{
	string alpha;
	while (!cin.eof())
	{
		getline(cin, alpha);
		cout << HtmlDecode(alpha) << endl;
	}
	return 0;
}

