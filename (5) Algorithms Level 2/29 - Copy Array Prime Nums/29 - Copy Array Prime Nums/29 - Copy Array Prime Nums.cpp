// 29 - Copy Array Prime Nums.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>

using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

enPrimeNotPrime CheckIsPrime(int Num)
{
    int M = round(Num / 2);

    for (int i = 2; i <= M; i++)
    {
        if (Num % i == 0)
        {
           return enPrimeNotPrime::NotPrime;
        }
    }
    return enPrimeNotPrime::Prime;
    
}

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

void FillArrayWithRandomNumbers(int Arr[100], int &ArrayLength)
{
    cout << "\nEnter Array Length:\n";
    cin >> ArrayLength;

    for (int i = 0; i < ArrayLength; i++)
    {
        Arr[i] = RandomNumber(1, 100);
    }
}

void CopyArrayPrimeNumbers(int ArrSource[100], int ArrDestination[100], int ArrSourceLength, int &ArrDestinationLength)
{
    int Counter = 0;

    for (int i = 0; i < ArrSourceLength; i++)
    {
        if (CheckIsPrime(ArrSource[i]) == enPrimeNotPrime::Prime)
        {
            ArrDestination[Counter] = ArrSource[i];
            Counter++;
        }
    }
    ArrDestinationLength = --Counter;
}

void PrintArray(int Arr[100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    srand((unsigned)time(NULL));
    int Arr1[100], Arr1Length = 0;

    FillArrayWithRandomNumbers(Arr1, Arr1Length);

    int Arr2[100], Arr2Length = 0;
    CopyArrayPrimeNumbers(Arr1, Arr2, Arr1Length, Arr2Length);

    cout << "\nArray 1 elements: \n";
    PrintArray(Arr1, Arr1Length);
    
    cout << "\nPrime Numbers in Array 2: \n";
    PrintArray(Arr2, Arr2Length);

    return 0;
}