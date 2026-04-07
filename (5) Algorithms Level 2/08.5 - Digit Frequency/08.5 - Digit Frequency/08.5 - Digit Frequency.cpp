// 08.5 - Digit Frequency.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// 08 - Digit Frequency.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

int main()
{
	long long int Digits = ReadPositiveNumber("Please enter Digits \"Whole Number\":");
	int SelectedNum = ReadPositiveNumber("Select a Number to find it's Frequncy...");
	cout << "Number [" << SelectedNum << "] Freqeuncy = " << GetNumFrequency(Digits, SelectedNum);



	return 0;
}
