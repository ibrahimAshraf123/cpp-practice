
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float D;
	cout << "This program calculates \"Circle Area Through Diameter\"... \n";
	cout << "Please enter value of D: \n";
	cin >> D;
	cout << "\n";

	const float PI = 3.14;
	float Area = (PI * pow(D, 2)) / 4;

	cout << "The Circle Area Through Diameter ~ " << ceil(Area) << endl;



	return 0;
}

