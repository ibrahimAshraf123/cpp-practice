
#include <iostream>

using namespace std;

int x = 333;

void myFunction() {

	int x = 200;
	cout << x;
}

int main()
{
	int x = 555;

	cout << "My Function's x = ";
	myFunction();
	cout << "\n";

	cout << "My main's x = " << x << "\n";

	cout << "My global x = " << ::x << "\n";

	return 0;
}
