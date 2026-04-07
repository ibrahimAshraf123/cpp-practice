// 49 - MyCeil.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

using namespace std;

float ReadNumber()
{
	float Number;
	cout << "Enter Number: \n";
	cin >> Number;

	return Number;
}

float GetFractionPart(float Number)
{
	return Number - int(Number);
}

float MyCeil(float Number)
{
	float FractionPart = GetFractionPart(Number);

	if (abs(FractionPart) > 0)
	{
		if (Number > 0)
			return int(Number) + 1;
		else
			return int(Number);
	}
	else
		return Number;
		
}

int main()
{
	float Number = ReadNumber();

	cout << "\nMy Ceil = " << MyCeil(Number) << endl;
	cout << "\nC++ Ceil = " << ceil(Number) << endl;

	return 0;
}
