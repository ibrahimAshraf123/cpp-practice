using namespace std;

#include <iostream>

enum enWeekday { Sun = 1, Mon = 2, Tue = 3, Wed = 4, Thur = 5, Fri = 6, Sat = 7 };

void showWeekDayMenu() {
	cout << "*********************************\n";
	cout << "               Weekdays            \n";
	cout << "*********************************\n";
	cout << "1) Sunday\n";
	cout << "2) Monday\n";
	cout << "3) Tuesday\n";
	cout << "4) Wednesday\n";
	cout << "5) Thursday\n";
	cout << "6) Friday\n";
	cout << "7) Saturday\n";
	cout << "*********************************\n";
}

enWeekday readWeekDay() {
	enWeekday weekDay;
	int wd;

	cout << "Please enter your number:\n";
	cin >> wd;
	
	return (enWeekday)wd;
}

string getWeekDayName(enWeekday weekDay) {

	switch (weekDay) {
	case enWeekday::Sun:
		return "Sunday";
		break;
	case enWeekday::Mon:
		return "Monday";
		break;
	case enWeekday::Tue:
		return "Tuesday";
		break;
	case enWeekday::Wed:
		return "Wednesday";
		break;
	case enWeekday::Thur:
		return "Thursday";
		break;
	case enWeekday::Fri:
		return "Friday";
		break;
	case enWeekday::Sat:
		return "Saturday";
		break;
	default:
		return "Not a Weekday!";

	}
}

int main()
{
	showWeekDayMenu();
	cout << "Your day is " << getWeekDayName(readWeekDay()) <<endl;


	return 0;
}
