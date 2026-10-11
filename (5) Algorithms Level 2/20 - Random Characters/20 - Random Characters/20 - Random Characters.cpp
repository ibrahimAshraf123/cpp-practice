// 20 - Random Characters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//print random letter, capital letter, character, digit, in order

#include <iostream>
#include <cstdlib>

using namespace std;

enum enCharType { SmallLeter = 1, CapitalLeter = 2, SpecialCharacter = 3, Digit = 4 };

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

char GetRandomCharacter(enCharType Type)
{
	switch (Type)
	{
	case enCharType::SmallLeter:
			return char(RandomNumber(97, 122));
			break;
	case enCharType::CapitalLeter:
			return char(RandomNumber(65, 90));
			break;
	case enCharType::SpecialCharacter:
			return char(RandomNumber(33, 47));
			break;
	case enCharType::Digit:
			return char(RandomNumber(48, 57));
			break;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	cout << GetRandomCharacter(enCharType::SmallLeter) << endl;
	cout << GetRandomCharacter(enCharType::CapitalLeter) << endl;
	cout << GetRandomCharacter(enCharType::SpecialCharacter) << endl;
	cout << GetRandomCharacter(enCharType::Digit) << endl;

	return 0;
}