
#include <iostream>
#include <cmath>

using namespace std;

float SumOf3(float n1, float n2, float n3) {
	return n1 + n2 + n3;
}

float CircleAreaArbitrary(float a, float b, float c) {
	float p = SumOf3(a, b, c) / 2;
	const float PI = 3.14;
	float T = (a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c)));
	T = pow(T, 2);
	float area = PI * T;
	return area;
}

int main()
{
	float myA, myB, myC;
	cout << "This program calculates \"Circle Area with circle Described Around an Arbitrary\"... \n";
	cout << "Please enter value of A,B,C: \n";
	cin >> myA >> myB >> myC;
	cout << "\n";

	cout << "Circle Area = " << CircleAreaArbitrary(myA, myB, myC) << " ~ " << round(CircleAreaArbitrary(myA, myB, myC)) << endl;

	return 0;
}
