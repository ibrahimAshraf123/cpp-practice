
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float L;
	cout << "This program calculates \" Circle Area Along the Circumference\"... \n";
	cout << "Please enter value of L: \n";
	cin >> L;
	cout << endl;

	const float PI = 3.14;
	float Area = pow(L, 2) / (4 * PI);

	cout << "The Circle Area Along the Circumference ~ " << floor(Area) << endl;


	return 0;
}
