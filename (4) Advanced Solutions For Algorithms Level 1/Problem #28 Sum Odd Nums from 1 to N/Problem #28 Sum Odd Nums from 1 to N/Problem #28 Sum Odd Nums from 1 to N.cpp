using namespace std;

#include <iostream>

enum enOddOrEven { Odd = 1, Even = 2 };

int ReadNumber()
{
    int N;
    cout << "Enter Number?\n";
    cin >> N;

    return N;
}

enOddOrEven CheckOddOrEven(int N)
{
    if (N % 2 != 0)
        return enOddOrEven::Odd;
    else
        return enOddOrEven::Even;
}

int SumOddNumbersFrom1ToN_UsingFor(int N)
{
    cout << "Sum of Odd Numbers From 1 To " << N << " Using For statement:\n";

    int Sum = 0;
    for (int i = 1; i <= N; i++)
    {
        if (CheckOddOrEven(i) == enOddOrEven::Odd)
        {
            Sum += i;
        }
    }
    return Sum;
}

int SumOddNumbersFrom1ToN_UsingWhile(int N)
{
    cout << "Sum of Odd Numbers From 1 To " << N << " Using While statement:\n";

    int Sum = 0;
    int i = 1;

    while (i <= N)
    {
        if (CheckOddOrEven(i) == enOddOrEven::Odd)
        {
            Sum += i;
        }
        i++;
    }
    return Sum;
}

int SumOddNumbersFrom1ToN_UsingDoWhile(int N)
{
    cout << "Sum of Odd Numbers From 1 To " << N << " Using Do While statement:\n";

    int Sum = 0;
    int i = 1;

    do
    {
        if (CheckOddOrEven(i) == enOddOrEven::Odd)
        {
            Sum += i;
        }
        i++;
    } while (i <= N);

    return Sum;
}

void PrintSum(int Sum)
{
    cout << Sum << endl;
}

int main()
{
    int N = ReadNumber();

    PrintSum(SumOddNumbersFrom1ToN_UsingFor(N));
    PrintSum(SumOddNumbersFrom1ToN_UsingWhile(N));
    PrintSum(SumOddNumbersFrom1ToN_UsingDoWhile(N));

    return 0;
}
