
#include <iostream>
using namespace std;

enum enNumberType { Odd = 1,Even = 2 };

int ReadNumber() 
{
	int number;

	cout << "Enter number to know its type:\n";
	cin >> number;
	return number;
}

enNumberType CheckNumberType(int number) 
{
	int Result = number % 2;

	if (Result == 0) {
		return enNumberType::Even;
	}
	else {
		return enNumberType::Odd;
	}
}

void PrintNumberType(enNumberType NumberType) 
{
	if (NumberType == enNumberType::Even) {
		cout << "\nNumber is Even\n";
	}
	else {
		cout << "\nNumber is Odd\n";
	}
}

int main()
{
	PrintNumberType(CheckNumberType(ReadNumber()));

	return 0;
}
