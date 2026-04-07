// 33 - Fill Array With Keys.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
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

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

char RandomCharacter()
{
	return char(RandomNumber(65, 90));
}

string RandomWord()
{
	string Word = "";
	for (int i = 1; i <= 4; i++)
	{
		Word = Word + RandomCharacter();
	}
	return Word;
}

string GenerateKey(int WordsAmount)
{
	string Key = "";
	for (int i = 1; i <= WordsAmount; i++)
	{
		if (i == WordsAmount)
			Key += RandomWord();
		else
			Key += RandomWord() + "-";
	}
	return Key;
}

void FillArrayWithKeys(string Array[100], int KeysAmount)
{
	for (int i = 0; i < KeysAmount; i++)
	{
		Array[i] = GenerateKey(4);
	}
}

void PrintStringArray(string Array[100], int KeysAmount)
{
	for (int i = 0; i < KeysAmount; i++)
	{
		cout << "Array[" << i << "]: " << Array[i] << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	string Array[100];
	int KeysAmount = ReadPositiveNumber("How many keys to generate?");

	FillArrayWithKeys(Array, KeysAmount);

	cout << "\nArray elements:\n";
	PrintStringArray(Array, KeysAmount);


	return 0;
}
