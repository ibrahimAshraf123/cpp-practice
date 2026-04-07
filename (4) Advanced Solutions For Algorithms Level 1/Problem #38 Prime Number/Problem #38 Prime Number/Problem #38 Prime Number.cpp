using namespace std;

#include <iostream>

enum enPrimeOrNotPrime {Prime = 1, NotPrime = 2};

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

enPrimeOrNotPrime CheckPrimeNumber(int Number)
{
    int Half = round(Number / 2);
    for (int i = 2; i <= Half; i++) 
    {
       if (Number % i == 0)
           return enPrimeOrNotPrime::NotPrime;
    } 
    return enPrimeOrNotPrime::Prime;
}

void PrintPrimeOrNot(int Number)
{
    switch (CheckPrimeNumber(Number))
    {
    case enPrimeOrNotPrime::Prime:
        cout << Number << " is Prime " << endl;
        break;
    case enPrimeOrNotPrime::NotPrime:
        cout << Number << " is Not Prime " << endl;
        break;
    }
    
}

int main()
{
    
    PrintPrimeOrNot(ReadPositiveNumber("Please Enter a Positive Number:"));

    return 0;
}
