
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float a, b, c;
	cout << "This program calculates \"Circle Area for circle Described Around an Arbitrary\"...\n";
	cout << "Please enter the value of a, b and c: \n";

	cout << "a ? \n";
	cin >> a;
	cout << "b ? \n";
	cin >> b;
	cout << "c ? \n";
	cin >> c;
	cout << endl;

	float p = (a+b+c) / 2;
	const float PI = 3.14;
	float T = (a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c)));
	T = pow(T, 2);
	float Area = PI * T;

	cout << "The result ~ " << round(Area) << endl;

	return 0;
}
