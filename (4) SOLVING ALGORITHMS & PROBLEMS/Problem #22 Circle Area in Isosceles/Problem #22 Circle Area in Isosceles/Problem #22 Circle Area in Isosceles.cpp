using namespace std;

#include <iostream>

void ReadVariables(float& A, float& B)
{
	cout << "Value of A?\n";
	cin >> A;
	cout << "Value of B?\n";
	cin >> B;
}

float CircleAreaInIsosceles(float A, float B)
{
	const float PI = 3.14159265359;
	float Area = ((PI * pow(B, 2)) / 4) * ((2 * A - B) / (2 * A + B));

	return Area;
}

void PrintResults(float CircleAreaInIsosceles)
{
	cout << "\nCircle Area In Isosceles = " << CircleAreaInIsosceles << endl;
}

int main()
{
	float A, B;
	ReadVariables(A, B);
	PrintResults(CircleAreaInIsosceles(A, B));

	return 0;
}
