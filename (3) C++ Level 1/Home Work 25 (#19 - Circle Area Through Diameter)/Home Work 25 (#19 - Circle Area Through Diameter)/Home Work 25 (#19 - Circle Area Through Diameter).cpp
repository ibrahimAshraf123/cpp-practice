
#include <iostream>
#include <cmath>

using namespace std;

float CircleAreaDiameter(float D) {
	const float PI = 3.14;
	float area = (PI * pow(D, 2)) / 4;
	return area;
}

int main()
{
	float Diameter;
	cout << "This program calculates \"Circle Area Through Diameter\"... \n";
	cout << "Please enter value of Diameter: \n";
	cin >> Diameter;

	cout << "Circle Area = " << CircleAreaDiameter(Diameter) << endl;



	return 0;
}
