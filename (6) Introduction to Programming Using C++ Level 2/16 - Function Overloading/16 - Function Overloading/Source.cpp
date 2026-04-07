#include <iostream>
using namespace std;

int MyAdd(int a, int b)
{
	return a + b;
}

int MyAdd(int a, int b, int c)
{
	return a + b + c;
}

double MyAdd(double a, double b)
{
	return a + b;
}

double MyAdd(double a, double b, double c)
{
	return a + b + c;
}

int main()
{

	double a = 5.5, b = 10.1, c = 15.3;

	cout << "Result = ";
	cout << MyAdd(a,b);
	cout << endl;

	return 0;
}