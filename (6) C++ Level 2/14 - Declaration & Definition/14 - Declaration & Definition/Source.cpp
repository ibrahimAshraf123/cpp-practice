#include <iostream>

using namespace std;

//Func declaration
int add(int, int);


int main()
{
	int a = 2, b = 3;

	cout << "Result = " << add(a, b);
	cout << endl;


	return 0;
}

//Func definition
int add(int a, int b)
{
	return a + b;
}