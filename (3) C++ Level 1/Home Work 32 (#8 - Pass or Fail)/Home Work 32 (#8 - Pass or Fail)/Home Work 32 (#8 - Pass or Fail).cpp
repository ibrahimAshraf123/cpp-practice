
#include <iostream>

using namespace std;

void readMark(int& mark) {
	cout << "Please enter your Mark: \n";
	cin >> mark;
}

void PassOrFailProcedure(int mark) {
	if (mark >= 50) {
		cout << mark << " is >= 50 \nPass\n";
	}
	else {
		cout << mark << " is not >= 50 \nFail\n";
	}
}


int main()
{
	int mark;
	cout << "This program prints \"Pass or Fail\" according to your mark... \n";

	readMark(mark);
	PassOrFailProcedure(mark);

	return 0;
}
