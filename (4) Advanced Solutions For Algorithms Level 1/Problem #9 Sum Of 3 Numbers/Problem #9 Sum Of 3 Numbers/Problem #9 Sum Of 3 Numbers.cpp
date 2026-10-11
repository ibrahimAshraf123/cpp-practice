using namespace std;

#include <iostream>

void Read3Numbers(int &num1, int &num2, int &num3) 
{
	cout << "Enter Number 1:\n";
	cin >> num1;
	cout << "Enter Number 2:\n";
	cin >> num2;
	cout << "Enter Number 3:\n";
	cin >> num3;
}

int Sum3Numbers(int num1, int num2, int num3)
{
	int total = num1 + num2 + num3;
	return total;
}

void PrintResult(int total)
{
	cout << "\Sum of 3 numbers = " << total << endl;
}

int main()
{
	int num1, num2, num3;
	Read3Numbers(num1,num2,num3);
	PrintResult(Sum3Numbers(num1,num2,num3));

	return 0;
}
