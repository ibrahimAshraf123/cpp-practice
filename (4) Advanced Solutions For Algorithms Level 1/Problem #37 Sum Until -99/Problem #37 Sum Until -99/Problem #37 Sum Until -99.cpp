using namespace std;

#include <iostream>
#include <string>

int ReadNumber(string Message) {
	int N;
	cout << Message << endl;
	cin >> N;

	return N;
}

int SumInputsUntilX(int X)
{
	int Sum = 0, Number = 0, counter = 1;

	do 
	{
		Number = ReadNumber("Please Enter Number " + to_string(counter));
		if (Number == X)
		{
			break;
		}

		Sum += Number;
		counter++;

	} while (Number != X);

	return Sum;
}

int main()
{
	cout<< "\nResult: " << SumInputsUntilX(-99) << endl;

	return 0;
}

