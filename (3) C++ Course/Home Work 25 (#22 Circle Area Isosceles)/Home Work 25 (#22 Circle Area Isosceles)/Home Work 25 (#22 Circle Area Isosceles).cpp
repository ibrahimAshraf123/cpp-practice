
#include <iostream>
#include <cmath>

using namespace std;

float CircleAreaIsosceles(float a, float b) {
	const float PI = 3.14;
	float area = (PI * pow(b, 2) / 4) * ((2 * a - b) / (2 * a + b));
	return area;
}

int main()
{
	float myA, myB;
	cout << "This program calculates \"Circle Area Inscribed in an Isosceles\"... \n";
	cout << "Please enter value of A: \n";
	cin >> myA;
	cout << "\n";

	cout << "Please enter value of B: \n";
	cin >> myB;
	cout << "\n";

	cout << "Circle Area = " << CircleAreaIsosceles(myA, myB) << " ~ " << round(CircleAreaIsosceles(myA, myB)) << endl;


	return 0;
}
