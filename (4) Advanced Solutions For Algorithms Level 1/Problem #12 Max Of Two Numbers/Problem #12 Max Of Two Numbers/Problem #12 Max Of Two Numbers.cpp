
#include <iostream>

using namespace std;

void ReadNumbers(int &Num1, int &Num2)
{
    cout << "Enter Number 1:\n";
    cin >> Num1;
    cout << "Enter Number 2:\n";
    cin >> Num2;
}

void CheckEquality(int &Num1, int &Num2) {
    while (Num1 == Num2) {
        cout << "ERROR, Numbers are equal (NO MAX)\n";
        ReadNumbers(Num1, Num2);
    }
}

int GetMax(int Num1, int Num2) 
{
        return (Num1 > Num2) ? Num1 : Num2;
}

void PrintMax(int &Num1,int &Num2)
{
    CheckEquality(Num1, Num2);

    cout << "Max = " << GetMax(Num1, Num2) << endl;
}

int main()
{
    int Num1, Num2;
    ReadNumbers(Num1, Num2);
    PrintMax(Num1, Num2);
    
    return 0;
}
