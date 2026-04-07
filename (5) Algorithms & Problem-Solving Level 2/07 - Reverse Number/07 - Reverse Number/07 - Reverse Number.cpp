#include <iostream>
#include <string>

using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number < 0);
	return Number;
}

void ReverseNumber(int Num)
{
	string NumAsString = to_string(Num);
	int NumAsStringSize = NumAsString.size();

	for (int i = NumAsStringSize-1; i>=0; i--)
	{
		cout << NumAsString[i];
	}

}

int main()
{
	ReverseNumber(ReadPositiveNumber("Enter a Positive Number:"));



	return 0;
}