
#include <iostream>

using namespace std;

void ReadPositiveNumber() {
	int number;

	cout << "Please enter a positive number \n";
	cin >> number;

	while (number < 0) {
		cout << "WRONG, number must be positive:\n";
		cout << "Please enter a positive number \n";
		cin >> number;
	}

	cout << "Your number is: " << number << endl;
}

int ReadIntInRange(int From, int To) {
	int number;
	cout << "Enter a number between " << From << " And " << To << endl;
	cin >> number;

	while (number < From || number > To) {
		cout << "WRONG, number must be in range\n";
		cout << "Enter a number between " << From << " And " << To << endl;
		cin >> number;
	}
	return number;

}

int RangeFrom(){
	int From;
	cout << "Range From?" << endl;
	cin >> From;
	return From;
}

int RangeTo() {
	int To;
	cout << "Range To?" << endl;
	cin >> To;
	return To;
}

int main()
{
	//ReadPositiveNumber();
	int From, To;
	cout << "Your number is : " << ReadIntInRange(18, 45) <<endl;
	


	return 0;
}
