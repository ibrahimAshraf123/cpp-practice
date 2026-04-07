#include <iostream>

using namespace std;

void PrintFibonacciUsingLoop(int Number)
{
	int FebNumber = 0;
	int Pre2 = 0, Pre1 = 1;
	cout << "1 ";

	for (int i = 2; i <= Number; i++)
	{
		FebNumber = Pre1 + Pre2;
		cout << FebNumber << " ";
		Pre2 = Pre1;
		Pre1 = FebNumber;
	}
}

int main()
{


	PrintFibonacciUsingLoop(10);






	return 0;
}