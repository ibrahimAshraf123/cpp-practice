using namespace std;

#include <iostream>

float ReadNumber(string Message)
{
	float N;
	cout << Message << endl;
	cin >> N;

	return N;
}

enum enOperations { Addition = '+', Subtraction = '-', Multiplication = '*', Division = '/' };

enOperations ReadOperationType() {
	char OpType = '+';
	cout << "Enter Operation Type (+,-,*,/)\n";
	cin >> OpType;

	return (enOperations)OpType;
}

float Calculate(float Num1, float Num2, enOperations& Operation)
{
	switch (Operation) {
	case enOperations::Addition:
		return Num1 + Num2; break;

	case enOperations::Subtraction:
		return Num1 - Num2; break;

	case enOperations::Multiplication:
		return Num1 * Num2; break;

	case enOperations::Division:
		return Num1 / Num2; break;

	}
}

int main()
{
	int Num1 = ReadNumber("Enter Number 1");
	enOperations Operation = ReadOperationType();
	int Num2 = ReadNumber("Enter Number 2");

	cout <<endl << "Result: " << Calculate(Num1, Num2, Operation) << endl;

	return 0;
}
