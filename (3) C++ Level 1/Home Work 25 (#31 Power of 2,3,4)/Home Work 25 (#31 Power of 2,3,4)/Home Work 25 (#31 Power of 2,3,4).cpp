
#include <iostream>
#include <cmath>

using namespace std;

void Powers2nd3rd4th(double n) {
	double x = pow(n, 2);
	double y = pow(n, 3);
	double z = pow(n, 4);
	cout << x << " " << y << " " << z << endl;
	return;
}

int main()
{
	double num;
	cout << "This program prints out \"Power of 2,3,4\"... \n";
	cout << "Enter a number to find powers: \n";
	cin >> num;

	Powers2nd3rd4th(num);

	return 0;
}
