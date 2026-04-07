// 47 - MyRound.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

using namespace std;

float ReadNumber()
{
	float Num;
	cout << "Enter Number:\n";
	cin >> Num;

	return Num;
}

float GetFractionPart(float Number)
{
	return Number - int(Number);
}

float MyRound(float Number)
{
	int IntPart;
	IntPart = int(Number);
	float FractionPart = GetFractionPart(Number);

	if (abs(FractionPart) >= .5)
	{
		if (Number > 0)
			return ++IntPart;
		else
			return --IntPart;
	}
	else
		return IntPart;
}

int main()
{
	float Number = ReadNumber();

	cout << "\nMY Round = " << MyRound(Number) << endl;
	cout << "\nC++ Round = " << round(Number) << endl;


	return 0;
}
