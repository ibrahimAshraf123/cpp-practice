using namespace std;

#include <iostream>

int ReadAge() 
{
	int Age;
	cout << "Enter Age between 18 & 45 ? \n";
	cin >> Age;

	return Age;
}

bool ValidateNumberInRange(int Num, int From, int To)
{
	return (Num >= From && Num <= To);
}

int ReadUntilAgeBetween(int From, int To)
{
	int Age = 0;
	do
	{
		Age = ReadAge();
	} while (!ValidateNumberInRange(Age, From, To));

	return Age;
}

void PrintResults(int Age)
{
		cout << "\nyour Age is " << Age << endl;
}

int main()
{
	PrintResults(ReadUntilAgeBetween(18,45));

	return 0;
}
