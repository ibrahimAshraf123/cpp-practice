// 22 - Count Repeated Elements.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>

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

void GenerateArray(int Array[100],int ArraySize)
{
    
    for (int i = 0; i < ArraySize; i++)
    {
        cout << "Element [" << i + 1 << "]: ";
        cin >> Array[i];
   }


}

void PrintArrayElements(int Array[100], int ArraySize)
{
    for (int i = 0; i < ArraySize; i++)
    {
        cout << Array[i] << " ";
    }

}

int GetNumFrequency(int Array[100], int ArraySize, int Check)
{
    int Freqeuncy = 0;
    for (int i = 0; i < ArraySize; i++)
    {
        if (Array[i] == Check)
            Freqeuncy++;
    }
    return Freqeuncy;
}

int main()
{
    int Arr[100];
    int ArraySize = ReadPositiveNumber("How many elements you want to store?");
    GenerateArray(Arr, ArraySize);

    int Check = ReadPositiveNumber("Enter Number to check frequency:");
    cout << "Original Array: ";
    PrintArrayElements(Arr, ArraySize);
    cout << endl;
    cout << Check << " is repeated " << GetNumFrequency(Arr, ArraySize, Check) << " Time(s)\n";
    return 0;
}
