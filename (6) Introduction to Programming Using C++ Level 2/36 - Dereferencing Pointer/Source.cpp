#include <iostream>
using namespace std;

int main()
{
	int a = 10;

	cout << "a value    = " << a << endl;
	cout << "a address  = " << &a << endl;

	int* p;
	p = &a;

	cout << "p value    = " << p << endl;
	cout << "value pointed to by p = " << *p << endl;

	*p = 20;

	cout << a << endl;
	cout << *p << endl;

	*p = 30;

	cout << a << endl;
	cout << *p << endl;


	return 0;
}