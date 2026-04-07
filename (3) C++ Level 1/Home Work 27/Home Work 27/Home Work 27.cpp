
#include <iostream>

using namespace std;

void mySwapFunction(int &a, int &b) { //by-ref

	int temp = a;
	a = b;
	b = temp;
	cout << "A = " << a << ", B = " << b << endl;
}

int main()
{
	int a;
	int b;
	cout << "This program swaps numbers... \n";
	cout << "Please enter value of A? \n";
	cin >> a;
	cout << "Please enter value of B? \n";
	cin >> b;
	cout << "\n";
	cout << "After Swap inside procedure: "; mySwapFunction(a, b);
	cout << "After Swap inside Main Function: A = " << a << ", B = " << b << "\n";

	return 0;
}
