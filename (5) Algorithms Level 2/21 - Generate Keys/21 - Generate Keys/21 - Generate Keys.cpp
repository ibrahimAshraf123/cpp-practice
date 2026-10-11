// 21 - Generate Keys.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

int ReadPositiveNumber(string Message)
{
	int Num;
	do
	{
		cout << Message << endl;
		cin >> Num;
	} while (Num < 0);

	return Num;
}

string GenerateKey()
{
	string key = "";
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			key = key + char(RandomNumber(65, 90));
		}
		if (i < 4)
			key = key + "-";
	}
	return key;

}

void PrintKeys(int Num)
{

	for (int i = 1; i <= Num; i++)
	{
		cout << "Key [" << i << "]: " << GenerateKey() << endl;;
	}

}

int main()
{
	srand((unsigned)time(NULL));

	PrintKeys(ReadPositiveNumber("Please enter number of keys:"));

	return 0;
}
