#include <iostream>

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

bool IsPerfect(int Num)
{
	int SumOfDivisors = 0;
	for (int i = 1; i < Num; i++)
	{
		if (Num % i == 0)
			SumOfDivisors += i;

	}
		return Num == SumOfDivisors;
}

void PrintPerfectNumbers1ToN(int N)
{

	for (int i = 1; i <= N; i++)
	{
		if (IsPerfect(i))
		{
			cout << i << endl;
		}
	}
}

int main()
{
	
	PrintPerfectNumbers1ToN(ReadPositiveNumber("Please enter a positive Number:"));

	return 0;
}