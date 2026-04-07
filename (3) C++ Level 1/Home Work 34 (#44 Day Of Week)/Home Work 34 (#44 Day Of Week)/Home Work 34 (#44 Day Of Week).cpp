
#include <iostream>

using namespace std;

enum enWeekdays { Sunday = 1, Monday = 2, Tuesday = 3, Wednesday = 4, Thursday = 5, Friday = 6, Saturday = 7 };

void readNumber(int& num) {
	//read num
	cout << "Enter number 1 - 7: \n";
	cin >> num;
	if (num > 7 || num < 1) {
		cout << "ERROR \"Number out of bounds\"\n\n";
		readNumber(num);
	}
}

void printWeekday(int num, enWeekdays& Weekday) {
	Weekday = (enWeekdays)num;

	switch (Weekday) {
	case enWeekdays::Sunday:
		cout << "Sunday\n";
		break;
	case enWeekdays::Monday:
		cout << "Monday\n";
		break;
	case enWeekdays::Tuesday:
		cout << "Tuesday\n";
		break;
	case enWeekdays::Wednesday:
		cout << "Wednesday\n";
		break;
	case enWeekdays::Thursday:
		cout << "Thursday\n";
		break;
	case enWeekdays::Friday:
		cout << "Friday\n";
		break;
	case enWeekdays::Saturday:
		cout << "Saturday\n";
		break;
	}
}

int main()
{
	int num;
	enWeekdays Weekday;

	cout << "This program reads number and prints \"Day of The Week\"...\n";
	
	readNumber(num);
	printWeekday(num,Weekday);	


	return 0;

}
