#include <iostream>
#include "clsInputValidate.h"

using namespace std;

int main()
{
	cout << clsInputValidate::IsNumberBetween(5, 1, 10) << endl;
	cout << clsInputValidate::IsNumberBetween(5.5, 1.3, 10.8) << endl;

	cout << clsInputValidate::IsDateBetween(clsDate(),
											clsDate(8, 9, 2026),
											clsDate(30, 9, 2026)) << endl;

	cout << clsInputValidate::IsDateBetween(clsDate(), 
											clsDate(30, 9, 2026),
											clsDate(8, 9, 2026)) << endl;

	cout << "\nPlease Enter a Number: \n";
	int x = clsInputValidate::ReadIntNumber();
	cout << "x = " << x << endl;

	cout << "\nPlease Enter a Number between 1 and 5: \n";
	int y = clsInputValidate::ReadIntNumberBetween(1,5);
	cout << "y = " << y << endl;

	cout << "\nPlease Enter a double Number: \n";
	double a = clsInputValidate::ReadDblNumber();
	cout << "a = " << a << endl;

	cout << "\nPlease Enter a double Number between 1 and 5: \n";
	double b = clsInputValidate::ReadDblNumberBetween(1, 5);
	cout << "b = " << b << endl;

	cout << clsInputValidate::IsValidDate(clsDate(35, 12, 2022));

	system("pause>0");
	return 0;
}