using namespace std;

#include <iostream>

enum enWeekdays { Sun = 1, Mon = 2, Tue = 3, Wed = 4, Thur = 5, Fri = 6, Sat = 7 };

void showWeekdaysMenu() {
	cout << "****************************\n";
	cout << "          WEEKDAYS          \n";
	cout << "****************************\n";
	cout << "1) Sunday\n";
	cout << "2) Monday\n";
	cout << "3) Tuesday\n";
	cout << "4) Wednesday\n";
	cout << "5) Thursday\n";
	cout << "6) Friday\n";
	cout << "7) Saturday\n";
	cout << "****************************\n";
}

enWeekdays readNum() {
	int num;
	enWeekdays Weekday;

	cout << "Enter number: \n";
	cin >> num;

	if (num < 1 || num > 7) {
		cout << "ERROR: Number out of bounds!\n";
		readNum();
	}
	else {
		return Weekday = (enWeekdays)num;
	}
}

string printWeekDay(enWeekdays Weekday) {
	
	switch (Weekday) {
	case enWeekdays::Sun:
		return "Sunday";
		break;
	case enWeekdays::Mon:
		return "Monday";
		break;
	case enWeekdays::Tue:
		return "Tuesday";
		break;
	case enWeekdays::Wed:
		return "Wednesday";
		break;
	case enWeekdays::Thur:
		return "Thursday";
		break;
	case enWeekdays::Fri:
		return "Friday";
		break;
	case enWeekdays::Sat:
		return "Saturday";
		break;
	}
	
}

int main()
{
	showWeekdaysMenu();
	cout <<"Result: " << printWeekDay(readNum()) << endl;

	return 0;
}
