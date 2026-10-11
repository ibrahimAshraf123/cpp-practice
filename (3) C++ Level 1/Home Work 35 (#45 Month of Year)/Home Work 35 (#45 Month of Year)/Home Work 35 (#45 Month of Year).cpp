using namespace std;

#include <iostream>

enum enMonths { Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, Jun = 6, Jul = 7, Aug = 8, Sep = 9, Oct = 10, Nov = 11, Dec = 12 };

void showMonthsMenu() {
	cout << "****************************\n";
	cout << "            MONTHS          \n";
	cout << "****************************\n";
	cout << "1) January\n";
	cout << "2) Febuary\n";
	cout << "3) March\n";
	cout << "4) April\n";
	cout << "5) May\n";
	cout << "6) June\n";
	cout << "7) July\n";
	cout << "8) August\n";
	cout << "9) September\n";
	cout << "10) October\n";
	cout << "11) November\n";
	cout << "12) December\n";
	cout << "****************************\n";
}

enMonths readNum() {
	int num;
	enMonths month;

	cout << "Enter number of month:\n";
	cin >> num;

	if (num < 1 || num > 12) {
		cout << "ERROR: Number out of bounds!\n";
		readNum();
	}
	else {
		return month = (enMonths)num;
	}
}

void printMonth(enMonths month) {
	cout << "Result: ";

	switch (month) {
	case enMonths::Jan:
		cout << "January";
		break;
	case enMonths::Feb:
		cout << "Febuary";
		break;
	case enMonths::Mar:
		cout << "March";
		break;
	case enMonths::Apr:
		cout << "April";
		break;
	case enMonths::May:
		cout << "May";
		break;
	case enMonths::Jun:
		cout << "June";
		break;
	case enMonths::Jul:
		cout << "July";
		break;
	case enMonths::Aug:
		cout << "August";
		break;
	case enMonths::Sep:
		cout << "September";
		break;
	case enMonths::Oct:
		cout << "October";
		break;
	case enMonths::Nov:
		cout << "November";
		break;
	case enMonths::Dec:
		cout << "December";
		break;
	}
	cout << endl;
}

int main()
{
	showMonthsMenu();
	printMonth(readNum());

	return 0;
}
