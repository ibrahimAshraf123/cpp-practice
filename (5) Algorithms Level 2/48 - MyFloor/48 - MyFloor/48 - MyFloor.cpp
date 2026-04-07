// 48 - MyFloor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

float ReadNumber()
{
	float Number;
	cout << "Enter Number: \n";
	cin >> Number;

	return Number;
}

float MyFloor(float Number)
{
	if (Number < 0)
		return int(Number) - 1;
	else
		return int(Number);
}

int main()
{
	float Number = ReadNumber();

	cout << "\nMy Floor = " << MyFloor(Number) << endl;
	cout << "\nC++ Floor = " << floor(Number) << endl;

	return 0;
}
