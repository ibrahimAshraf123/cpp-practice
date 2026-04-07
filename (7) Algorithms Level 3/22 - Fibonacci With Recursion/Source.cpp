#include <iostream>

using namespace std;

void PrintFibonacciUsingRecursion(int Number, int Prev1, int Prev2)
{
	
	int FebNumber = 0;

	if (Number > 0)
	{
		FebNumber = Prev2 + Prev1;
		cout << FebNumber << " ";
		Prev2 = Prev1;
		Prev1 = FebNumber;
		PrintFibonacciUsingRecursion(Number - 1, Prev1, Prev2);
	}
}


int main()
{


	PrintFibonacciUsingRecursion(10, 0, 1);








	return 0;
}