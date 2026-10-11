using namespace std;

#include <iostream>

void ReadNumbers(int& Num1, int& Num2, int& Num3)
{
	cout << "Enter Number 1:\n";
	cin >> Num1;
	cout << "Enter Number 2:\n";
	cin >> Num2;
	cout << "Enter Number 3:\n";
	cin >> Num3;
}

void CheckEquality(int& Num1, int& Num2, int& Num3)
{
	while (Num1 == Num2 && Num2 == Num3)
	{
		cout << "\nERROR, All Numbers are equal (NO MAX)\n";
		ReadNumbers(Num1, Num2, Num3);
	}
}

int GetMax(int& Num1, int& Num2, int& Num3)
{
	CheckEquality(Num1, Num2, Num3);

	if (Num1 > Num2 && Num1 > Num3)
		return Num1;
	else if (Num2 > Num1 && Num2 > Num3)
		return Num2;
	else if (Num3 > Num1 && Num3 > Num2)
		return Num3;
}

void PrintMax(int Max)
{
	cout << "\nMax = " << Max << endl;
}

int main()
{
	int Num1, Num2, Num3;
	ReadNumbers(Num1, Num2, Num3);
	PrintMax(GetMax(Num1, Num2, Num3));

	return 0;
}
