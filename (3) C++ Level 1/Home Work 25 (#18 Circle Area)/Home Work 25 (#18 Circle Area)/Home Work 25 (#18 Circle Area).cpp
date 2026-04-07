
#include <iostream>
#include <cmath>

using namespace std;

float CircleArea(float r) {
	const float PI = 3.14;
	float area = PI * pow(r, 2);
	return area;
}

int main()
{
	float r;
	cout << "This program calculates \"Circle Area \"... \n";
	cout << "Please enter the value of r: \n";
	cin >> r;
	cout << "\n";

	cout << "Area = " << CircleArea(r) << endl;


	return 0;
}

