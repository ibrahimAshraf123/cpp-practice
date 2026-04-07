#include <iostream>

using namespace std;

short ReadYear()
{
	short year;
	cout << "Please enter a year? ";
	cin >> year;
	return year;
}

short ReadMonth()
{
	short month;
	cout << "Please enter a month? ";
	cin >> month;
	return month;
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;

	short NumberOfDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month];
}


int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	cout << "\nNumber of Days in Month [" << Month << "] is " << NumberOfDaysInAMonth(Month, Year) << " days.";


	system("pause>0");
	return 0;
}