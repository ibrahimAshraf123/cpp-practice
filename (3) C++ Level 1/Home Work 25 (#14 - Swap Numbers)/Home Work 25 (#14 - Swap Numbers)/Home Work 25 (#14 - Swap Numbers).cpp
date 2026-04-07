
#include <iostream>

using namespace std;

void SwapNumberProcedure(int num1, int num2) {

	cout << " num1 = " << num1 << ", num2 = " << num2 << "\n";
	int temp = num1;
	num1 = num2;
	num2 = temp;
	cout << " num1 = " << num1 << ", num2 = " << num2 << "\n";

	return;

}



int main()
{
	int myNum1;
	int myNum2;

	cout << "This program swaps your numbers... \n";
	cout << "Please enter number1? \n";
	cin >> myNum1;
	cout << "\n";

	cout << "Please enter number2? \n";
	cin >> myNum2;
	cout << "\n";

	SwapNumberProcedure(myNum1, myNum2);

	return 0;
}
