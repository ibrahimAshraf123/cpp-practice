using namespace std;

#include <iostream>

enum enOddOrEven { Odd = 1, Even = 2};

int ReadNumber()
{
	int N;
	cout << "Enter Number:\n";
	cin >> N;

	return N;
}

void PrintInstructions()
{
	cout << "This program prints Sum of \"Odd, Even and All\" Numbers from 1 to N...\n";
	
}

enOddOrEven CheckOddOrEven(int N)
{
	if (N % 2 != 0)
		return enOddOrEven::Odd;
	else
		return enOddOrEven::Even;
}

int SumEvenNumbersFrom1ToN_UsingFor(int N)
{
	cout << "Sum of Even Numbers From 1 To " << N << " Using For statement:\n";
	int Sum = 0;
	int Counter = 0;

	for (Counter = 1; Counter <= N; Counter++)
	{
		if (CheckOddOrEven(Counter) == enOddOrEven::Even)
		{
			Sum += Counter;
		}
	}
	return Sum;
}

int SumOddNumbersFrom1ToN_UsingFor(int N)
{
	cout << "Sum of Odd Numbers From 1 To " << N << " Using For statement:\n";
	int Sum = 0;
	int Counter = 0;

	for (Counter = 1; Counter <= N; Counter++)
	{
		if (CheckOddOrEven(Counter) == enOddOrEven::Odd)
		{
			Sum += Counter;
		}
	}
	return Sum;
}

int SumAllNumbersFrom1ToN_UsingFor(int N)
{
	cout << "Sum of All Numbers From 1 To " << N << " Using For statement:\n";
	int Sum = 0;
	int Counter = 0;

	for (Counter = 1; Counter <= N; Counter++)
	{
		Sum += Counter;
	}
	return Sum;
}

void PrintSum(int Sum)
{
	cout << Sum << endl;
}

int main()
{
	PrintInstructions();

	int N = ReadNumber();
	PrintSum(SumOddNumbersFrom1ToN_UsingFor(N));
	PrintSum(SumEvenNumbersFrom1ToN_UsingFor(N));
	PrintSum(SumAllNumbersFrom1ToN_UsingFor(N));


	return 0;
}