// 21.5 - Generate Keys.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>

using namespace std;

enum enCharacterType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

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
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

char GetRandomCharacter(enCharacterType Type)
{
    switch (Type)
    {
    case enCharacterType::SmallLetter:
        return char(RandomNumber(97, 122)); break;

    case enCharacterType::CapitalLetter:
        return char(RandomNumber(65, 90)); break;

    case enCharacterType::SpecialCharacter:
        return char(RandomNumber(33, 47)); break;

    case enCharacterType::Digit:
        return char(RandomNumber(48, 57));
    }
}

string GenerateWord()
{
    string Word = "";

    for (int i = 1; i <= 4; i++)
    {
        Word = Word + char(GetRandomCharacter(enCharacterType::CapitalLetter));
    }

    return Word;

}

string GenerateKey()
{
    string Key = "";
    for (int i = 1; i <= 4; i++)
    {
        Key = Key + GenerateWord();
        if(i < 4)
        Key = Key + "-";
    }
    return Key;
}

void GenerateKeys(int KeysAmount)
{
    for (int i = 1; i <= KeysAmount; i++)
    {
        cout << "Key [" << i << "]: " << GenerateKey() << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    GenerateKeys(ReadPositiveNumber("Please Enter Keys Amount:"));
    cout << endl;

    return 0;
}