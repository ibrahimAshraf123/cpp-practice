#include <iostream>

using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

int ReadPositiveNumber(string Message)
{
	int Num;
	do {
		cout << Message << endl;
		cin >> Num;
	} while (Num <= 0);
	
	return Num;
}

enPrimeNotPrime CheckPrime(int n) {
	
	int M = round(n / 2);
	for (int i = 2; i <= M; i++) 
	{
		if (n % i == 0 )
			return enPrimeNotPrime::NotPrime;
	}
	return enPrimeNotPrime::Prime;
}

void PrintPrimeNumbers1toN(int N)
{
	cout << "\nPrime Numbers from " << 1 << " To " << N <<" are:\n";
	for (int i = 1; i <= N; i++)
	{
		if (CheckPrime(i) == enPrimeNotPrime::Prime)
			cout << i << endl;
		else
			continue;
	}
}

int main()
{
	//02 - Print Prime Numbers 1 to N
	int N = ReadPositiveNumber("Please Enter a Positive Number:");
	PrintPrimeNumbers1toN(N);

	return 0;
}