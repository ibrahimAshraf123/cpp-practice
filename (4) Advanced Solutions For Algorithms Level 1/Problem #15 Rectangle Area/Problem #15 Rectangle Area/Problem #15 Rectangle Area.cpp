using namespace std;

#include <iostream>

void ReadVariables(float& L, float& W)
{
	cout << "Length of rectangle?\n";
	cin >> L;
	cout << "Width of rectangle?\n";
	cin >> W;
}

float CalculateRectangleArea(float L, float W)
{
	return L * W;
}

void PrintArea(float Area)
{
	cout << "\nRectangle Area = " << Area <<endl;
}

int main()
{
	float L, W;
	ReadVariables(L, W);
	PrintArea(CalculateRectangleArea(L, W));

	return 0;
}
