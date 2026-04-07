// 16 - from AAA to ZZZ.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void PrintFromAAAtoZZZ()
{
	string Word = "AAA";
	int WordSize = Word.size();

	for (int i = WordSize-1; i >= 0; i--)
	{
		for (int j = 65; j <= 90; j++)
		{
			Word[i] = char(j);
			cout << Word << endl;
		}
	}
}


int main()
{

	PrintFromAAAtoZZZ();

	return 0;
}
