
#include <iostream>

using namespace std;

void readOperation(float &n1,char &op, float &n2) {
	cout << "Please enter number 1: \n";
	cin >> n1;
	cout << "enter operation sign: \n(+,-,*,/) \n";
	cin >> op;
	cout << "Please enter number 2: \n";
	cin >> n2;
}

void calcProcedure(float n1, char op, float n2) {
	float calc;
	if (op == '+'){
		calc = n1 + n2;
	}
	else if (op == '-') {
		calc = n1 - n2;
	}
	else if (op == '*') {
		calc = n1 * n2;
	}
	else if (op == '/') {
		calc = n1 / n2;
	}
	else {
		cout << "ERROR: Unidentified operation\n";
	}
	cout << "\n****************************************\n";
	cout << "Your calculation is: \n";
	cout << n1 << " " << op << " " << n2 << " = " << calc << endl;
}

int main()
{
	float n1;
	float n2;
	char op;

	cout << "This program is a simple calculator... \n";

	readOperation(n1, op, n2);
	calcProcedure(n1, op, n2);

	return 0;
}
