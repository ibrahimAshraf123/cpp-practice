using namespace std;

#include <iostream>

void ReadVariables(float& B, float& H)
{
	cout << "Value of Triangle's Base?\n";
	cin >> B;
	cout << "Value of Triangle's Height?\n";
	cin >> H;
}

float TriangleArea(float B, float H)
{
	float Area = (B / 2) * H;
	return Area;
}

void PrintResults(float TriangleArea)
{
	cout << "\nTriangle's Area = " << TriangleArea << endl;
}

int main()
{
	float B, H;
	ReadVariables(B, H);
	PrintResults(TriangleArea(B, H));

	return 0;
}
