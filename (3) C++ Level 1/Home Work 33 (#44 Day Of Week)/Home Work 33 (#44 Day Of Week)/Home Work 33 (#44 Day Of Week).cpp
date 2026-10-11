
#include <iostream>

using namespace std;

void readNumber(int &n) {
	cout << "Please enter a number 1 - 7: \n";
	cin >> n;
}

void numberToDay(int n, string &weekday) {
	if (n > 7 || n < 1) {
		cout << "ERROR\n";
		readNumber(n);
	}

	else if (n == 1) {
		weekday = "Sunday";
	}

	else if (n == 2) {
		weekday = "Monday";
	}

	else if (n == 3) {
		weekday = "Tuesday";
	}

	else if (n == 4) {
		weekday = "Wednesday";
	}

	else if (n == 5) {
		weekday = "Thursday";
	}

	else if (n == 6) {
		weekday = "Friday";
	}

	else if (n == 7) {
		weekday = "Saturday";
	}
}

int main()
{
	int number;
	string weekday;

	cout << "This program assigns numbers into weekdays...\n";

	readNumber(number);
	numberToDay(number, weekday);
	cout << "\n****************************\n";
	cout << weekday << endl;

	return 0;
}
