// 36.5 - Add Array Element.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int ReadNumber()
{
    int Num;
    cout << "\nPlease enter a number? ";
    cin >> Num;
    return Num;
}

void AddNumberToArray(int Number, int Arr[100], int &ArrLength)
{
    ArrLength++;
    Arr[ArrLength - 1] = Number;
}

void InputUsersNumbersInArray(int Arr[100], int & ArrLength)
{
    bool AddMore = true;

    do
    {
        AddNumberToArray(ReadNumber(), Arr, ArrLength);
        cout << "\nDo you want to add more numbers? [0]:No, [1]:Yes? ";
        cin >> AddMore;
    } while (AddMore);


}

void PrintArray(int Arr[100], int ArrLength)
{
    for (int i = 0; i < ArrLength; i++)
    {
        cout << "[" << Arr[i] << "] ";
    }
    cout << "\n";
}

int main()
{
    int Arr[100], ArrLength = 0;

    InputUsersNumbersInArray(Arr, ArrLength);

    cout << "\nArray Length: " << ArrLength << endl;
    cout << "\nArray elements: ";
    PrintArray(Arr, ArrLength);

    return 0;
}
