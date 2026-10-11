
#include <iostream>
#include <cmath>

using namespace std;

float CircleAreaInSquare(float A) {
	const float PI = 3.14;
	float area = (PI * pow(A, 2)) / 4;
	return area;
}

int main()
{
	float myA;
	cout << "This program calculates \"Circle Area Inscribed in a Square\"... \n";
	cout << "Please enter value of A: \n";
	cin >> myA;
	cout << "Circle Area = " << CircleAreaInSquare(myA) << " ~ " << round(CircleAreaInSquare(myA)) << endl;

	return 0;
}
