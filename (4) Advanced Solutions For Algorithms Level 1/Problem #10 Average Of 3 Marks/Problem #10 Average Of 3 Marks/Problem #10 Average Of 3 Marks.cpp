
#include <iostream>

using namespace std;

void ReadNumbers(int &Num1, int &Num2, int &Num3) 
{
	cout << "Enter Number 1: \n";
	cin >> Num1;
	cout << "Enter Number 2: \n";
	cin >> Num2;
	cout << "Enter Number 3: \n";
	cin >> Num3;
}

int SumOfNumbers(int Num1, int Num2, int Num3) {
	int Sum = Num1 + Num2 + Num3;
	return Sum;
}

float AverageOfNumbers(int Num1, int Num2, int Num3)
{
	float Average = (float)SumOfNumbers(Num1, Num2, Num3) / 3;
	return Average;
}

void PrintResults(float Average) 
{
	cout << "\nSum = " << Average * 3 << endl;
	cout << "Average = " << Average << endl;
}

int main()
{
	int Num1, Num2, Num3;

	ReadNumbers(Num1,Num2,Num3);
	PrintResults(AverageOfNumbers(Num1, Num2, Num3));

	return 0;
}