// 09 - Get All Digits Frequncy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

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

int GetNumFrequency(int Digits, int SelectedNum)
{
	int Remain = 0;
	int Frequency = 0;

	while (Digits > 0)
	{
		Remain = Digits % 10;
		Digits /= 10;

		if (Remain == SelectedNum)
			Frequency++;
	}

	return Frequency;

}

void GetAllDigitsFrequncy(int Digits)
{
	for (int i = 0; i < 10; i++)
	{

		short DigitFrequency = 0;
		DigitFrequency = GetNumFrequency(Digits, i);

		if (DigitFrequency > 0)
		{
			cout << "Digit " << i << " Frequency is "
				<< DigitFrequency << endl;
		}
	}

}

int main()
{
	long int Digits = ReadPositiveNumber("Please enter Digits \"Whole Number\":");
	GetAllDigitsFrequncy(Digits);



	return 0;
}
