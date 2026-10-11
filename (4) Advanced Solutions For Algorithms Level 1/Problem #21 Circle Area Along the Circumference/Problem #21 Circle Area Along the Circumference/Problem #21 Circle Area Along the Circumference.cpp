using namespace std;

#include <iostream>

float ReadCircumference() {
	float L;
	cout << "Value of Circumference?\n";
	cin >> L;

	return L;
}

float CircleAreaByCircumference(float L)
{
	const float PI = 3.14159265359;
	float Area = pow(L, 2) / (4 * PI);

	return Area;
}

void PrintResults(float CircleAreaByCircumference)
{
	cout << "\Circle Area By Circumference = " << CircleAreaByCircumference << endl;
}

int main()
{
	PrintResults(CircleAreaByCircumference(ReadCircumference()));
	return 0;
}
