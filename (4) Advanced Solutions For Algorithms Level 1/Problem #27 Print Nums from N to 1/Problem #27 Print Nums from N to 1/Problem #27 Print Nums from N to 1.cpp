using namespace std;

#include <iostream>

int ReadNumber()
{
	int N;
	cout << "Enter Number:\n";
	cin >> N;

	return N;
}

void PrintNumbersFromNTo1_UsingFor(int N)
{
	cout << "\nNumbers From " << N << " To 1 using For statement : \n\n";

	for (int i = 1; i <= N; N--)
	{
		cout << N << endl;
	}
}

void PrintNumbersFromNTo1_UsingWhile(int N)
{
	cout << "\nNumbers From " << N << " To 1 using While statement : \n\n";

	int i = 1;
	while (i <= N)
	{
		cout << N << endl;
		N--;
	}
}

void PrintNumbersFromNTo1_UsingDoWhile(int N)
{
	cout << "\nNumbers From " << N << " To 1 using Do While statement : \n\n";

	int i = 1;
	do
	{
		cout << N << endl;
		N--;
	} while (i <= N);
}


int main()
{
	int N = ReadNumber();

	PrintNumbersFromNTo1_UsingFor(N);
	PrintNumbersFromNTo1_UsingWhile(N);
	PrintNumbersFromNTo1_UsingDoWhile(N);

	return 0;
}
