// 45 - CountArrayNegativeNums.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "\nPlease enter Array Length: \n";
    cin >> arrLength;

    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = RandomNumber(-100, 100);
    }
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";
}

int NegativeNumsCount(int arr[100], int arrLength)
{
    int count = 0;

    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] < 0)
            count++;
    }
    return count;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], arrLength = 0;

    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray Elements: \n";
    PrintArray(arr, arrLength);

    cout << "\nNegative numbers count is: ";
    cout << NegativeNumsCount(arr, arrLength) << endl;


    return 0;
}
