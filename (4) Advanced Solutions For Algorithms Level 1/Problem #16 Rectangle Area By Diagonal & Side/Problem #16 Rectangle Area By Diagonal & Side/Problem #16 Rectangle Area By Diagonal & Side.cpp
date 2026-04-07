using namespace std;

#include <iostream>
#include <cmath>

void ReadVariables(float& S, float& D)
{
	cout << "Value of Rectangle's Side Length? \n";
	cin >> S;
	cout << "Value of Rectangle's Diagonal? \n";
	cin >> D;
}

float RectangleAreaSD(float S, float D)
{
	float RectangleArea = S * sqrt(D * D - S * S);
	return RectangleArea;

}

void PrintResults(float RectangleArea)
{
	cout << "\nArea of Rectangle = " << RectangleArea << endl;
}

int main()
{
	float S, D;
	ReadVariables(S, D);
	PrintResults(RectangleAreaSD(S, D));


	return 0;
}
