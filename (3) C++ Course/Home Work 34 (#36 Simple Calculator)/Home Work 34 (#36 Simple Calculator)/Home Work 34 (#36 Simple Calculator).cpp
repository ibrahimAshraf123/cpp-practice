
#include <iostream>

using namespace std;

void readData(int &num1, char &op, int &num2) {
	cout << "Enter number 1: \n";
	cin >> num1;
	cout << "Enter operation symbol: \n";
	cout << "(+ ,- ,* ,/ ) \n";
	cin >> op;
	cout << "Enter number 2: \n";
	cin >> num2;
	cout << endl;
}

void printCalculation(int num1, char op, int num2) {
	switch (op) {
	case '+':
		cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
		break;
	case '-':
		cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
		break;
	case '*':
		cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
		break;
	case '/':
		cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
		break;
	default:
		cout << "ERROR\nWrong symbol\n";

	}
}

int main()
{
	
	int num1, num2;
	char op;

	cout << "This program is a \"Simple Calculator\"...\n";

	readData(num1, op, num2);
	printCalculation(num1, op, num2);
	

	return 0;
}
