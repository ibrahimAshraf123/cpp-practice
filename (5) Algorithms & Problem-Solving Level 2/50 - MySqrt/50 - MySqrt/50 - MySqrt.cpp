// 50 - MySqrt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

float ReadNumber()
{
	float Number;
	cout << "Enter a number: \n";
	cin >> Number;
	return Number;
}

float MySqrt(float Number)
{
	return pow(Number,.5);
}

int main()
{
	float Number = ReadNumber();

	cout << "\nMy Sqrt = " << MySqrt(Number) << endl;
	cout << "\nC++ square root = " << sqrt(Number) << endl;

	return 0;
}
