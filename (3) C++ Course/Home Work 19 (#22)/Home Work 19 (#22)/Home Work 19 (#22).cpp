
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float a, b;
	cout << "This program calculates \"Circle Area Inscribed in an Isosceles\"... \n";
	cout << "Please enter value of A: \n";
	cin >> a;
	cout << endl;

	cout << "Please enter value of B: \n";
	cin >> b;
	cout << endl;

	const float PI = 3.14;
	float Area = (PI * pow(b, 2) / 4) * ((2 * a - b) / (2 * a + b));

	cout << "The Circle Area Inscribed in an Isosceles ~ " << floor(Area) << endl;



	return 0;
}
