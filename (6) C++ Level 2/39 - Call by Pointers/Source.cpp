#include <iostream>
using namespace std;


void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

}

int main()
{

	int a = 1, b = 2;

	cout << "Before swap: " << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << endl;

	swap(&a, &b);
	cout << "After swap: " << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << endl;



	return 0;
}