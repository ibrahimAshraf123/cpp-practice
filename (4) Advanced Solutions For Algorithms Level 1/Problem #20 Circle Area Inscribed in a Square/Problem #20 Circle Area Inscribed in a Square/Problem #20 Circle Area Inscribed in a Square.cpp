using namespace std;

#include <iostream>

float ReadSquareSide()
{
	float A;
	cout << "Square's Side?\n";
	cin >> A;
	
	return A;
}

float CirlceAreaInscribedInSquare(float A)
{
	const float PI = 3.14159265359;
	float Area = (PI * pow(A, 2)) / 4;

	return Area;
}

void PrintResults(float CirlceAreaInscribedInSquare)
{
	cout << "\nCirlce Area Inscribed In a Square = " << CirlceAreaInscribedInSquare << endl;
}

int main()
{
	PrintResults(CirlceAreaInscribedInSquare(ReadSquareSide()));
	return 0;
}
