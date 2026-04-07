
#include <iostream>
#include <cmath>

using namespace std;

void RectangleAreaDandS(float s, float d) {

	float area = s * sqrt(pow(d, 2) - pow(s, 2));
	cout << area << endl;
	return;
}

int main()
{
	float side;
	float diagonal;

	cout << "This program calculates \"Rectangle area Through Diagonal and Side\"... \n";
	cout << "Please enter side value: \n";
	cin >> side;
	cout << "\n";
	cout << "Please enter diagonal value: \n";
	cin >> diagonal;
	cout << "\n";

	cout << "Area = ";
	RectangleAreaDandS(side, diagonal);

	return 0;
}
