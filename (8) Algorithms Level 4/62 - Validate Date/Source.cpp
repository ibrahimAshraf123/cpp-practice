#include <iostream>

using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
};

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 0 || Month >12)
		return 0;

	short arrMonthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : arrMonthDays[Month - 1]);
}

bool IsValidDay(stDate Date)
{
	return (Date.Day > 0 && Date.Day <= NumberOfDaysInMonth(Date.Month, Date.Year));
}

bool IsValidMonth(short Month)
{
	return (Month > 0 && Month <= 12);
}

bool IsValidDate(stDate Date)
{
	//validate day, month, year

	if (!IsValidDay(Date))
		return false;

	if (!IsValidMonth(Date.Month))
		return false;

	if (Date.Year <= 0)
		return false;

	return true;
}

//read Date Functions

short ReadDay()
{
	short Day;
	cout << "Please enter a Day? ";
	cin >> Day;
	return Day;
}

short ReadMonth()
{
	short Month;
	cout << "Please enter a Month? ";
	cin >> Month;
	return Month;
}

short ReadYear()
{
	short Year;
	cout << "Please enter a Year? ";
	cin >> Year;
	return Year;
}

stDate ReadFullDate()
{
	stDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}


int main()
{
	stDate Date = ReadFullDate();

	if (IsValidDate(Date))
		cout << "\nYes, Date is a valid date.";
	else
		cout << "\nNo, Date is NOT a valid date.";

	system("pause>0");
	return 0;
}