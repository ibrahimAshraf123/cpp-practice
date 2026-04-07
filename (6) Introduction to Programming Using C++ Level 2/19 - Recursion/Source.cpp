#include <iostream>
using namespace std;

void PrintNumbersUp(int a, int b)
{
	if (a <= b)
	{
		cout << a << endl;
		PrintNumbersUp(a + 1, b);
	}
}

void PrintNumbersDown(int b, int a)
{
	if (b >= a)
	{
		cout << b << endl;
		PrintNumbersDown(b - 1, a);
	}

}

int NumberPower(int Base, int Power)
{
	if (Power == 0)
		return 1;

	else
		return (Base * NumberPower(Base, Power-1));
}

int main()
{

	PrintNumbersUp(1, 10);
	cout << endl;

	PrintNumbersDown(10, 1);
	cout << endl;

	cout << NumberPower(2, 4) << endl;



	return 0;
}