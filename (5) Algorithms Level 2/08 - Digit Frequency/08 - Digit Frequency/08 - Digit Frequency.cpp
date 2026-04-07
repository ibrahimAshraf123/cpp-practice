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
	string DigitsAsString = to_string(Digits);
	int DigitsSize = DigitsAsString.size();
	int Frequency = 0;

	for (int i = 0; i < DigitsSize; i++)
	{

		if ((DigitsAsString[i] - '0') == SelectedNum)
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
