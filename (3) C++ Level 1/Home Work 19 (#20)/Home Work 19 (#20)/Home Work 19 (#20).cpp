
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float A;
	cout << "This program calculates \"Circle Area Inscribed in a Square\"...\n";
	cout << "Please insert A: \n";
	cin >> A;
	cout << endl;

	const float PI = 3.14;
	float Area = (PI * pow(A, 2)) / 4;

	cout << "The Circle Area Inscribed in a Square ~ " << ceil(Area) << endl;


	return 0;
}

