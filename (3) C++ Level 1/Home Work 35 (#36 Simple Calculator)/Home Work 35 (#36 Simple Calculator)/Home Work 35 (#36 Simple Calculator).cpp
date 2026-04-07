using namespace std;

#include <iostream>

float readNum1() {
	float num1;
	cout << "Enter number 1: \n";
	cin >> num1;
	return num1;	
}

char readOperation() {
	char op;
	cout << "Enter Operation Sign (+, -, *, /): \n";
	cin >> op;
	return op;
}

float readNum2() {
	float num2;
	cout << "Enter number 2: \n";
	cin >> num2;
	return num2;
}

void Calculate(){

	float num1 =readNum1();
	char op = readOperation();
	float num2 = readNum2();

	cout << "Result: ";

	switch (op) {
	case '+':
		cout << num1 + num2;
		break;
	case '-':
		cout << num1 - num2;
		break;
	case '*':
		cout << num1 * num2;
		break;
	case '/':
		if (num2 == 0) {
			cout << "Error: Division by zero!";
		}
		else {
			cout << num1 / num2;
		}
		break;
	default:
		cout << "ERROR: Invalid operator";
	}
	cout << endl;
}

int main()
{
	
	Calculate();
	
	return 0;
}
