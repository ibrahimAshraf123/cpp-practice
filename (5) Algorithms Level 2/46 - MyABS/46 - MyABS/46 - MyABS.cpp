// 46 - MyABS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cmath>

using namespace std;

float ReadNumber(string Message)
{
	int Number;

	cout << Message << endl;
	cin >> Number;

	return Number;
}

float MyABS(float Number)
{
	if (Number < 0)
		return Number * -1;
	else
		return Number;
}

int main()
{
	float Number = ReadNumber("Enter Number to get ABS value:");

	cout << "\nMy ABS = " << MyABS(Number) << endl;
	cout << "\nC++ ABS = " << abs(Number) << endl;

	return 0;
}
