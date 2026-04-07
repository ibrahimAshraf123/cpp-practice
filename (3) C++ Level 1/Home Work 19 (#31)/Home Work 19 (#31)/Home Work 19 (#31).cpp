
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float num;
	cout << "This program calculates \"Power of 2,3,4\"... \n";
	cout << "Please enter a number: \n";
	cin >> num;
	cout << endl;

	float x = pow(num, 2);
	float y = pow(num, 3);
	float z = pow(num, 4);

	cout << "Results: \n";
	cout << num << " ^ 2 ~ " << round(x) << "\n";
	cout << num << " ^ 3 ~ " << round(y) << "\n";
	cout << num << " ^ 4 ~ " << round(z) << "\n";
	cout << endl;



	return 0;
}
