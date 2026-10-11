
#include <iostream>
#include <cmath>

using namespace std;

float CircleAreaAlongC(float L) {
	const float PI = 3.14;
	float area = pow(L, 2) / (4 * PI);
	return area;
}

int main()
{
	float myL;

	cout << "This program calculates \"Circle Area Along the Circumference\"... \n";
	cout << "Please enter value of L: \n";
	cin >> myL;
	cout << "\n";

	cout << "Circle Area = " << CircleAreaAlongC(myL) << " ~ " << round(CircleAreaAlongC(myL)) << endl;
	return 0;
}
