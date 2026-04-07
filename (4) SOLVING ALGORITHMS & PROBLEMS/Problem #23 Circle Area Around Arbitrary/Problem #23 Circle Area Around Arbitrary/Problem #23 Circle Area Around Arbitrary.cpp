using namespace std;

#include <iostream>

void ReadVariables(float& A, float& B, float& C)
{
	cout << "Value of A?\n";
	cin >> A;

	cout << "Value of B?\n";
	cin >> B;

	cout << "Value of C?\n";
	cin >> C;
}

float CircleAreaByArbitraryTriangle(float A, float B, float C)
{
	const float PI = 3.14159265359;
	float P;
	P = (A + B + C) / 2;
	
	float T;
	T = (A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C)));
	T = pow(T, 2);

	float Area = PI * T;

	return Area;
}

void PrintResults(float CircleAreaByArbitraryTriangle)
{
	cout << "\nCircle Area By Arbitrary Triangle = " << CircleAreaByArbitraryTriangle << endl;
}

int main()
{
	float A, B, C;
	ReadVariables(A, B, C);
	PrintResults(CircleAreaByArbitraryTriangle(A, B, C));

	return 0;
}