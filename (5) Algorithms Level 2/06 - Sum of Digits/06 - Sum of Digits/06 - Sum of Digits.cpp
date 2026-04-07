#include <iostream>
#include <string>

using namespace std;

int ReadPositiveNumber(string Message)
{
	int Num;
	do {
		cout << Message << endl;
		cin >> Num;
	} while (Num < 0);
	return Num;
}

void PrintSumOfDigits(int Num)
{
	int Sum = 0, Remainder = 0;

	while (Num > 0)
	{
		Remainder = Num % 10;
		Num = Num / 10;
		Sum += Remainder;
	}
	

	cout << "Sum of digits is = " << Sum << endl;

}

int main()
{
   
	PrintSumOfDigits(ReadPositiveNumber("Enter positive Number"));

	return 0;
}
