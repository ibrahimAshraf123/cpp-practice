
#include <iostream>

using namespace std;

enum enMonths { January = 1, Febraury = 2, March = 3, April = 4, May = 5, June = 6, July = 7, August = 8, September = 9, October = 10, November = 11, December = 12 };

void readNumber(int& num) {
	cout << "Please enter a number 1 - 12: \n";
	cin >> num;
	if (num < 1 || num > 12) {
		cout << "ERROR \"Number out of bounds\"\n";
		readNumber(num);
	}
}

void printMonth(int num, enMonths& month) {
	month = (enMonths)num;

	switch (month) {
	case enMonths::January:
		cout << "January" << endl;
		break;
	case enMonths::Febraury:
		cout << "Febraury" << endl;
		break;
	case enMonths::March:
		cout << "March" << endl;
		break;
	case enMonths::April:
		cout << "April" << endl;
		break;
	case enMonths::May:
		cout << "May" << endl;
		break;
	case enMonths::June:
		cout << "June" << endl;
		break;
	case enMonths::July:
		cout << "July" << endl;
		break;
	case enMonths::August:
		cout << "August" << endl;
		break;
	case enMonths::September:
		cout << "September" << endl;
		break;
	case enMonths::October:
		cout << "October" << endl;
		break;
	case enMonths::November:
		cout << "November" << endl;
		break;
	case enMonths::December:
		cout << "December" << endl;
		break;
	}
}

int main()
{
	int num;
	enMonths month;

	cout << "This program reads number and prints \"Month Of The Year\"...\n";

	readNumber(num);
	printMonth(num, month);
	
		

	return 0;
}
