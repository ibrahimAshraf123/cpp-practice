#include <iostream>
#include <string>

using namespace std;

int ReadPositiveNumber(string Message)
{
	int Num;
	do
	{
		cout << Message << endl;
		cin >> Num;
	} while (Num < 0);
	return Num;
}

void PrintDigitsInReverse(int Num)
{
	string NumberAsString = to_string(Num);
	int NumberAsStringSize = NumberAsString.size();

	for (int i = NumberAsStringSize - 1; i >= 0; i--)
	{
		cout << NumberAsString[i] << endl;
	}

}

int main()
{
	PrintDigitsInReverse(ReadPositiveNumber("Enter Number"));

	return 0;
}