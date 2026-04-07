
#include <iostream>

using namespace std;

float RectangleArea(float width, float length) {
	return width * length;
}

int main()
{
	float a;
	float b;

	cout << "This program finds \"Rectangle Area\"... \n";
	cout << "Please enter width: \n";
	cin >> a;
	cout << "\n";
	cout << "Please enter length: \n";
	cin >> b;
	cout << "\n";

	cout << "Area = " << RectangleArea(a, b) << endl;


	return 0;
}
